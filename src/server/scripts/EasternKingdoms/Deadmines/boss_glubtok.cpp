#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "deadmines.h"

enum Spells {
    SPELL_FIRE_BLOSSOM          = 88129, 
    SPELL_FROST_BLOSSOM         = 88169, 
    SPELL_ARCANE_POWER          = 88009, 
    SPELL_FIST_OF_FLAME         = 87859,
    SPELL_FIST_OF_FROST         = 87861, 
    SPELL_BLINK                 = 87925  
};

#define SAY_AGGRO               "Glubtok show you da power of de Arcane."
#define SOUND_AGGRO             21151

#define SAY_KILL                "Ha..Ha..Ha..Ha..Ah!"
#define SOUND_KILL              21152

#define SAY_FISTS_OF_FLAME       "Fists of Flame!"
#define SOUND_FISTS_OF_FLAME     21153

#define SAY_FISTS_OF_FROST      "Fists of Frost!"
#define SOUND_FISTS_OF_FROST    21156

#define SAY_READY               "Glubtok ready?"
#define SOUND_READY             21154
//
#define SAY_LETS_DO_IT          "Let's do it!"
#define SOUND_LETS_DO_IT        21157

#define SAY_ARCANE_POWER        "ARCANE POWER"
#define SOUND_ARCANE_POWER      21146

#define SAY_TOO_MUCH_POWER      "TOO... MUCH... POWER"
#define SOUND_TOO_MUCH_POWER    21145
#define SAY_FLAME               "Elemental Fists!"


#define spell_elemental_fists RAND(87859, 91273)

const Position pos[1] = {
    {-192.328003f, -450.244995f, 54.521500f, 0.00f}
};

enum Phases {
    PHASE_NORMAL        = 1,
    PHASE_50_PERCENT    = 2,
};

class boss_glubtok : public CreatureScript {
public:
    boss_glubtok() : CreatureScript("boss_glubtok") {}

    struct boss_glubtokAI : public ScriptedAI {
        boss_glubtokAI(Creature* creature) : ScriptedAI(creature) {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        uint8 Phase;
        uint32 phase;
        uint32 SpellTimer;

        uint32 elemental_fists;
        uint32 ArcanePowerTimer;
        uint32 blinkTimer;
        uint32 PhaseChangeTimer;
        uint32 NormalCastTimer;
        uint8 BlossomSpell;

        bool Phased;

        void Reset() {
            Phased                  = false;
            Phase                   = PHASE_NORMAL;

            phase = 1;
            SpellTimer = urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS);

            elemental_fists         = 20000;
            blinkTimer              = 12000;

            NormalCastTimer         = 3000;
        }

        void EnterCombat(Unit* /*who*/) {
            DoPlaySoundToSet(me, SOUND_AGGRO);
        }

        void JustDied(Unit* /*Killer*/) {
            DoPlaySoundToSet(me, SOUND_TOO_MUCH_POWER);
            if (instance) 
                instance->SetData(BOSS_GLUBTOK_DATA, DONE);
        }

        void KilledUnit(Unit* Victim) {
            DoPlaySoundToSet(me, SOUND_KILL);
        }

        void UpdateAI(uint32 const diff) {
            if (!UpdateVictim())
                return;

            if (phase == 1) {
                if (SpellTimer <= diff) {
                    switch(urand(0, 1)) {
                        case 0:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(me, SPELL_FIST_OF_FLAME);
                            
                            DoPlaySoundToSet(me, SOUND_FISTS_OF_FLAME);
                            break;

                        case 1:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(me, SPELL_FIST_OF_FROST);
            
                            DoPlaySoundToSet(me, SOUND_FISTS_OF_FROST);
                            break;
                    }

                    SpellTimer = urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS);
                } else SpellTimer -= diff;

                if (HealthBelowPct(50)) {
                    phase = 2;
                    DoCast(me, SPELL_ARCANE_POWER);
                    DoPlaySoundToSet(me, SOUND_ARCANE_POWER);
                }

                DoMeleeAttackIfReady();
            } else {
                if (SpellTimer <= diff) {
                    DoCast(me, urand(1, 2) == 1 ? SPELL_FROST_BLOSSOM : SPELL_FIRE_BLOSSOM);
                    SpellTimer = urand(10*IN_MILLISECONDS, 25*IN_MILLISECONDS);
                } else SpellTimer -= diff;
            }

            if (PhaseChangeTimer <= diff && Phase == PHASE_NORMAL) {
                if (PhaseChangeTimer<= diff) {
                    me->SetReactState(REACT_AGGRESSIVE);
                    elemental_fists     = 20000;
                    blinkTimer          = 12000;
                    Phase               = PHASE_NORMAL;
                } else PhaseChangeTimer -= diff;

                if (elemental_fists <= diff && Phase == PHASE_NORMAL) {
                    if (elemental_fists<= diff) {
                        DoCast(me, elemental_fists);
        
                        elemental_fists = 20000;
                    } else elemental_fists -= diff;
                }

                if (blinkTimer <= diff && Phase == PHASE_NORMAL) {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1,10.0f, true))
                    DoCast(me, SPELL_BLINK);
                    blinkTimer = 12000;
                } else blinkTimer -= diff;

                DoMeleeAttackIfReady();
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const {
        return new boss_glubtokAI(creature);
    }
};

void AddSC_boss_glubtok() {
    new boss_glubtok();
}
