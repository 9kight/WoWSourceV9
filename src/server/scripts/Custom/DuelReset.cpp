/*
* Copyright (C) 2012-2013 HTCore <http://cata.vfire-core.com/>
* Copyright (C) 2012-2013 WoW Source <http://wowsource.info/>
* by Shee Shen
*/

#include "ScriptPCH.h"

class Reset_OnDuelEnd : public PlayerScript
{
	public:
		Reset_OnDuelEnd() : PlayerScript("Reset_OnDuelEnd") {}

	void OnDuelEnd (Player* winner, Player* loser, DuelCompleteType type)
	{
		// reset cooldowns (in order) Elwyn, Durotar, Tirisfal, Tendrasil, Dun Morogh, Gurubashi Arena, Exodar, Mulgore
		if (winner->GetZoneId() == 12 || winner->GetZoneId() == 14 || winner->GetZoneId() == 85 || winner->GetZoneId() == 141 || winner->GetZoneId() == 1 || winner->GetZoneId() == 5287 || winner->GetZoneId() == 3524 || winner->GetZoneId() == 215)
		{
				winner->RemoveArenaSpellCooldowns();
				loser->RemoveArenaSpellCooldowns();
				winner->SetHealth(winner->GetMaxHealth());
				winner->SetPower(POWER_MANA, winner->GetMaxPower(POWER_MANA));
				loser->SetHealth(loser->GetMaxHealth());
				loser->SetPower(POWER_MANA, loser->GetMaxPower(POWER_MANA));
		}
	}
};

void AddSC_Reset()
{
	new Reset_OnDuelEnd;
}