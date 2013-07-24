#include "ScriptPCH.h"
#include "Chat.h"
#include "World.h"

class KickEvent : public BasicEvent {
    public:
        KickEvent(WorldSession& session) :  _session(session) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) {
            _session.KickPlayer("KickEvent PWSCommands");
            return true;
        }

    private:
        WorldSession& _session;
};

class PWSPlayer : public PlayerScript
{
public:
    PWSPlayer() : PlayerScript("PWSPlayer") { }

    void OnLogin(Player* player) {
        QueryResult result = LoginDatabase.PQuery("SELECT reason FROM account_tempban WHERE accountId = %u", player->GetSession()->GetAccountId());
        if (result) {
            player->GetSession()->SendAreaTriggerMessage("Dein Account wurde aus dem Spiel genommen! Du wirst in 10 Sekunden gekickt.");
            player->GetSession()->SendAreaTriggerMessage("|cffff0000Grund: %s", result->Fetch()[0].GetCString());
            
            if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(9454))
                if (!player->AddAura(9454, player))
                     player->CastSpell(player, 9454, true);

            if (WorldSession* session = player->GetSession())
                player->m_Events.AddEvent(new KickEvent(*session), player->m_Events.CalculateTime(10000), true);     
        } else {
            player->RemoveAurasDueToSpell(9454);
        }

        result = LoginDatabase.PQuery("SELECT FROM_UNIXTIME(`time`), `comment` FROM account_verwarnung WHERE accountid = %u", player->GetSession()->GetAccountId());
        if (result) {
            ChatHandler(player->GetSession()).PSendSysMessage("|cffff0000Dein Account wurde bereits verwarnt!");
            do {
                Field* field = result->Fetch();
                const char* date = field[0].GetCString();
                const char* comment = field[1].GetCString();

                ChatHandler(player->GetSession()).PSendSysMessage("%s - %s", date, comment);
            } while (result->NextRow());
        }
    }

    void OnLogout(Player* player) {
        QueryResult result = LoginDatabase.PQuery("SELECT bannedby FROM account_banned WHERE id = %u AND active = 1", player->GetSession()->GetAccountId());
        if (result)
            player->GetSession()->KickPlayer("KickEvent PWSCommands");
    }
};

class pws_commandscript : public CommandScript {
    public:
        pws_commandscript() : CommandScript("pws_commandscript") { }

        static bool HandleStrafenCommand(ChatHandler* handler, const char* args) {
            Player* target;
            uint64 targetGuid;
            std::string targetName;
            uint32 accountId;

            if (handler->GetSession()->GetSecurity() > SEC_PLAYER) {

                if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
                    return false;

                if (!target) {
                    QueryResult result = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", targetGuid);
                    if (!result)
                        return false;
                    accountId = result->Fetch()[0].GetUInt32();
                } else {
                    accountId = target->GetSession()->GetAccountId();
                }
            } else {
                accountId = handler->GetSession()->GetAccountId();
            }

            uint32 strafpunkte = 0;

            QueryResult result = LoginDatabase.PQuery("SELECT FROM_UNIXTIME(`time`), `comment`, `by`, strafpunkte, `active`, id FROM account_strafe WHERE account = %u", accountId);
            if (result) {
                handler->PSendSysMessage("|cffff0000Der Account wurde bereits bestraft!");
                do {
                    Field* field = result->Fetch();
                    const char* date = field[0].GetCString();
                    const char* comment = field[1].GetCString();
                    strafpunkte += field[3].GetUInt32();
                    const char* active = field[4].GetUInt8() == 1 ? "" : "[|cffff0000verjaehrt]";

                    QueryResult res = LoginDatabase.PQuery("SELECT username FROM account WHERE id = %u", field[2].GetUInt32());

                    const char* by = res ? res->Fetch()[0].GetCString() : "Unknown";

                    handler->PSendSysMessage("%s - ID[%u] - %u SP - %s - %s - %s", active, field[5].GetUInt32(), strafpunkte, by, date, comment);
                } while (result->NextRow());
                handler->PSendSysMessage("|cff00ff00Der Account hat %u Strafpunkte!", strafpunkte);
            } else {
                handler->PSendSysMessage("Der Account hat keine Strafen!");
            }

            return true;
        }

        static bool HandleWarnInfoCommand(ChatHandler* handler, const char* args) {
            Player* target;
            uint64 targetGuid;
            std::string targetName;
            uint32 accountId;

            if (handler->GetSession()->GetSecurity() > SEC_PLAYER) {

                if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName))
                    return false;

                if (!target) {
                    QueryResult result = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", targetGuid);
                    if (!result)
                        return false;
                    accountId = result->Fetch()[0].GetUInt32();
                } else {
                    accountId = target->GetSession()->GetAccountId();
                }
            } else {
                accountId = handler->GetSession()->GetAccountId();
            }

            QueryResult result = LoginDatabase.PQuery("SELECT FROM_UNIXTIME(`time`), `comment`, by_account FROM account_verwarnung WHERE accountid = %u", accountId);
            if (result) {
                handler->PSendSysMessage("|cffff0000Der Account wurde bereits verwarnt!");
                do {
                    Field* field = result->Fetch();
                    const char* date = field[0].GetCString();
                    const char* comment = field[1].GetCString();

                    QueryResult res = LoginDatabase.PQuery("SELECT username FROM account WHERE id = %u", field[2].GetUInt32());

                    const char* by = res ? res->Fetch()[0].GetCString() : "Unknown";
                    if (handler->GetSession()->GetSecurity() > SEC_PLAYER)
                        handler->PSendSysMessage("%s - %s - %s", by, date, comment);
                    else 
                        handler->PSendSysMessage("%s - %s", date, comment);
                } while (result->NextRow());
            } else {
                handler->PSendSysMessage("Der Account hat keine Verwarnungen!");
            }

            return true;
        }

        static bool HandleWarnCommand(ChatHandler* handler, const char* args) {
            if (!*args)
                return false;

            char* playerName = strtok((char*)args, " ");
            char* comment = strtok(NULL, "");

            if (!playerName || !comment)
                return false;

            QueryResult result = CharacterDatabase.PQuery("SELECT account, guid FROM characters WHERE name = '%s'", playerName);

            if (!result) {
                handler->PSendSysMessage("Spieler nicht gefunden!");
                return true;
            }

            uint32 accountId = result->Fetch()[0].GetUInt32();
            uint32 guid = result->Fetch()[1].GetUInt32();

            if (Player* player = ObjectAccessor::FindPlayer(guid)) {
                ChatHandler(player->GetSession()).PSendSysMessage("Du wurdest soeben verwarnt! |cffff0000Grund: %s", comment);
                player->GetSession()->SendAreaTriggerMessage("Du wurdest soeben verwarnt! |cffff0000Grund: %s", comment);
            }

            LoginDatabase.PExecute("INSERT INTO account_verwarnung (accountId, by_account, comment, `time`) VALUES (%u, %u, '%s', UNIX_TIMESTAMP())", accountId, handler->GetSession()->GetAccountId(), comment);
            handler->PSendSysMessage("Spieler verwarnt!");

            return true;
        }

        static bool HandleStrafeCommand(ChatHandler* handler, const char* args) {
            if (!*args)
                return false;

            sLog->outError(LOG_FILTER_GENERAL, "[PWS-Commands] .strafe executed. Player: %u - Arguments: %s", handler->GetSession()->GetPlayer()->GetGUID(), (char*)args);

            char* playerName = strtok((char*)args, " ");
            uint32 strafPunkte = atoi(strtok(NULL, " "));
            char* comment = strtok(NULL, "");
            uint32 _strafPunkte = strafPunkte;

            if (!playerName || !comment | !strafPunkte) 
                return false;

            sLog->outError(LOG_FILTER_GENERAL, "[PWS-Commands] .strafe Parameters: PN%s - %uSP - Comment[%s]", playerName, strafPunkte, comment);

            if (strafPunkte > 7 && handler->GetSession()->GetSecurity() < 6) {
                handler->PSendSysMessage("Du kannst maximal 7 Strafpunkte vergeben!");
                return true;
            } 

            if (strafPunkte < 1) {
                handler->PSendSysMessage("Du musst mindestens einen Strafpunkt vergeben!");
                return true;
            }

            if (!playerName || !comment)
                return false;

            QueryResult result = CharacterDatabase.PQuery("SELECT account, guid FROM characters WHERE name = '%s'", playerName);

            if (!result) {
                handler->PSendSysMessage("Spieler nicht gefunden!");
                return true;
            }

            uint32 accountId = result->Fetch()[0].GetUInt32();
            uint32 guid = result->Fetch()[1].GetUInt32();
            sLog->outError(LOG_FILTER_GENERAL, "[PWS-Commands] Get Data GUID: %u - AccountId: %u", guid, accountId);
            

            QueryResult res = LoginDatabase.PQuery("SELECT strafpunkte FROM account_strafe WHERE account = %u", accountId);

            if (res) {
                do {
                    _strafPunkte += res->Fetch()[0].GetUInt32();
                } while (res->NextRow());
            }

            uint32 banTime = strafPunkte * 60 * 60 * 24;

            if (Player* player = ObjectAccessor::FindPlayer(guid)) {
                if (WorldSession* session = player->GetSession()) {
                    sLog->outError(LOG_FILTER_GENERAL, "[PWS-Commands] init kick event");
                    ChatHandler(session).PSendSysMessage("|cffff0000Dein Account bekommt eine Sanktion! Du wirst in 10 Sekunden abgemeldet. |cff00ff00Grund: %s", comment);
                    session->SendAreaTriggerMessage("|cffff0000Dein Account bekommt eine Sanktion! Du wirst in 10 Sekunden abgemeldet. |cff00ff00Grund: %s", comment);
                    player->m_Events.AddEvent(new KickEvent(*session), player->m_Events.CalculateTime(10000), true);
                }
            }

            LoginDatabase.PExecute("INSERT INTO account_strafe (account, `by`, `comment`, `strafpunkte`, `time`, `active`) VALUES (%u, %u, '%s', %u, UNIX_TIMESTAMP(), 1)", accountId, handler->GetSession()->GetAccountId(), comment, strafPunkte);
            LoginDatabase.PExecute("INSERT INTO account_banned (id, realm, bandate, unbandate, bannedby, banreason, active) VALUES (%u, '-1', UNIX_TIMESTAMP(), UNIX_TIMESTAMP()+%u, '%s', '%s', 1)", accountId, banTime, handler->GetSession()->GetPlayer()->GetName().c_str(), comment);

            if (_strafPunkte >= 10) {
                LoginDatabase.PExecute("UPDATE account SET locked = 1, last_ip = '1337' WHERE id = %u", accountId);
                sLog->outError(LOG_FILTER_GENERAL, "[PWS-Commands] Account %u locked", accountId);
            }

            handler->PSendSysMessage("Spieler wird gesperrt!");
            return true;
        }

        static bool HandleDelStrafeCommand(ChatHandler* handler, const char* args) {
            if (!*args)
                return false;

            int id = atoi((char*)args);

            QueryResult result = LoginDatabase.PQuery("SELECT active FROM account_strafe WHERE account = %u", id);

            if (!result) {
                handler->PSendSysMessage("Strafe wurde nicht gefunden. ID kontrollieren!");
                return true;
            }

            if (result->Fetch()[0].GetUInt8() == 0) {
                handler->PSendSysMessage("Strafe ist verjaehrt!");
                return true;
            }

            LoginDatabase.PExecute("UPDATE account_strafe SET active = 0 WHERE id = %u", id);
            LoginDatabase.PExecute("UPDATE account_banned SET active = 0 WHERE id = %u", id);
            LoginDatabase.PExecute("UPDATE account SET locked = 0 WHERE id = %u", id);
            handler->PSendSysMessage("Strafe wurde entfernt.");
            
            return true;
        }

        static bool HandleTempBanCommand(ChatHandler* handler, const char* args) {
            Player* target;
            uint64 targetGuid;
            std::string targetName;
            uint32 accountId;

            if (!*args)
                return false;

            char* playerName = strtok((char*)args, " ");
            char* reason = strtok(NULL, "");

            if (!reason) {
                handler->PSendSysMessage("Bitte einen Grund angeben!");
                return true;
            }

            if (!handler->extractPlayerTarget(playerName, &target, &targetGuid, &targetName)) {
                handler->PSendSysMessage("Spieler nicht gefunden!");
                return true;
            }

            if (!target) {
                QueryResult result = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", targetGuid);
                    
                if (!result) {
                    handler->PSendSysMessage("WTF das kann logisch gesehen nicht passieren Oo");
                    return true;
                }

                accountId = result->Fetch()[0].GetUInt32();
            } else {
                accountId = target->GetSession()->GetAccountId();
            }

            QueryResult result = LoginDatabase.PQuery("SELECT reason FROM account_tempban WHERE accountId = %u", accountId);
            if (result) {
                handler->PSendSysMessage("Der Spieler hat bereits einen TempBan!");
                return true;
            }

            LoginDatabase.PQuery("INSERT INTO account_tempban (accountId, reason) VALUES (%u, '%s')", accountId, reason);

            if (target) {
                target->GetSession()->KickPlayer("KickEvent PWSCommands");
            }

            handler->PSendSysMessage("TempBan gesetzt!");
            
            return true;
        }

        static bool HandleDelTempBanCommand(ChatHandler* handler, const char* args) {
            Player* target;
            uint64 targetGuid;
            std::string targetName;
            uint32 accountId;

            if (!*args)
                return false;

            if (!handler->extractPlayerTarget((char*)args, &target, &targetGuid, &targetName)) {
                handler->PSendSysMessage("Spieler nicht gefunden!");
                return true;
            }

            if (!target) {
                QueryResult result = CharacterDatabase.PQuery("SELECT account FROM characters WHERE guid = %u", targetGuid);
                    
                if (!result) {
                    handler->PSendSysMessage("WTF das kann logisch gesehen nicht passieren Oo");
                    return true;
                }

                accountId = result->Fetch()[0].GetUInt32();
            } else {
                accountId = target->GetSession()->GetAccountId();
            }

            LoginDatabase.PExecute("DELETE FROM account_tempban WHERE accountId = %u", accountId);
            handler->PSendSysMessage("TempBan entfernt");
            
            return true;
        }

        ChatCommand* GetCommands() const {
            static ChatCommand PWSCommandTable[] = {
                { "verwarnungen",    SEC_PLAYER,        true, &HandleWarnInfoCommand,   "",   NULL },
                { "verwarnen",       SEC_MODERATOR,     true, &HandleWarnCommand,       "",   NULL },
                { "strafe",          SEC_MODERATOR,     true, &HandleStrafeCommand,     "",   NULL },
                { "strafen",         SEC_PLAYER,        true, &HandleStrafenCommand,    "",   NULL },
                { "delstrafe",       SEC_ADMINISTRATOR, true, &HandleDelStrafeCommand,  "",   NULL },
                { "tempban",         SEC_ADMINISTRATOR, true, &HandleTempBanCommand,    "",   NULL },
                { "deltempban",      SEC_ADMINISTRATOR, true, &HandleDelTempBanCommand, "",   NULL },
                { NULL, 0, false, NULL, "", NULL }
            };

            return PWSCommandTable;
        }
};


void AddSC_pws_commandscript() {
    new pws_commandscript();
    new PWSPlayer();
}
