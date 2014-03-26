/* ScriptData
SDScript by Loukie
SDName: boss_arcurion
SD%Complete: 60% or less
SDCategory: Hour of Twilight
EndScriptData */

#include"ScriptPCH.h"
#include"hour_of_twilight.h"

enum eArcurionYells 
{
	SAY_AGGRO  = 0,
	SAY_KILL   = 1,
	SAY_DEATH  = 2,
	SAY_HP_LOW = 3,
	SAY_FORCES = 4	
};

enum Spells 
{
 SPELL_HANDS_OF_FROST   = 102593,
 SPELL_CHAINS_OF_FROST  = 102582,
 SPELL_ICY_TOMB         = 103252,
 SPELL_ICY_BOULDER		= 102199,
 SPELL_SUMMON_VISUAL    = 103595,
 SPELL_TORRENT_OF_FROST = 103962
};

enum Events 
{
 EVENT_HANDS_OF_FROST,
 EVENT_CHAINS_OF_FROST,
 EVENT_ICY_BOULDER,
 EVENT_ICY_TOMB
};


class boss_arcurion : public CreatureScript
{
public:
    boss_arcurion() : CreatureScript("boss_arcurion") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_arcurionAI (creature);
    }

    struct boss_arcurionAI : public ScriptedAI
    {
        boss_arcurionAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
			
        }
		
		uint32 m_uiHealthAmountModifier;
        InstanceScript* instance;
        EventMap events;

        void Reset() 
        {
            events.Reset();
			m_uiHealthAmountModifier = 1;
        }
		
        void EnterCombat(Unit* /*Ent*/)
        {
			Talk(SAY_FORCES);	
			Talk(SAY_AGGRO);
			DoCast(SPELL_HANDS_OF_FROST);
			
            events.ScheduleEvent(EVENT_HANDS_OF_FROST, urand(5000,10000));
            events.ScheduleEvent(EVENT_CHAINS_OF_FROST, urand(12000,19000));
			events.ScheduleEvent(EVENT_ICY_BOULDER, urand(10000,11000));
            events.ScheduleEvent(EVENT_ICY_TOMB, 1000);
		}

        void JustDied(Unit* /*Kill*/)
        {
				Talk(SAY_DEATH);
        }		
		
        void KilledUnit(Unit* /*victim*/)
        {
            Talk(SAY_KILL);
        }		
		
        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HANDS_OF_FROST:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(SPELL_HANDS_OF_FROST);
						events.ScheduleEvent(EVENT_HANDS_OF_FROST, 1500);
                        break;
    
                    case EVENT_CHAINS_OF_FROST:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                       DoCast(SPELL_CHAINS_OF_FROST);
					   events.ScheduleEvent(EVENT_CHAINS_OF_FROST, 17000);
                        break;
						
                    case EVENT_ICY_BOULDER:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(SPELL_ICY_BOULDER);
						events.ScheduleEvent(EVENT_ICY_BOULDER, 11000);
                        break;
						
                    case EVENT_ICY_TOMB:
                        DoCast(SPELL_ICY_TOMB);
						events.ScheduleEvent(EVENT_ICY_TOMB, urand(111000, 113000));
                        break;						
						
					default:
                       break;
				}
			}
            // Health check
            if (HealthBelowPct(30 * m_uiHealthAmountModifier))
            {

				Talk(SAY_HP_LOW);
				   DoCast(SPELL_TORRENT_OF_FROST);

            }			
			
            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_arcurion() 
{
    new boss_arcurion();
}
