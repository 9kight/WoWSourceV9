/*
 * Copyright (C) 2013 WoW Source  <http://wowsource.info/>
 *
 * Copyright (C) 2013 WoWSource [WS] <http://wowsource.info/>
 *
 * Dont Share The SourceCode
 * and read our WoWSource Terms
 *
 */

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "MoveSplineInit.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "firelands.h"

#define GO_ALYSRAZOR_VOLCANO_GUID 100576

Position const SpawnPos[31] =
{
// Position on summon
    { 102.487f, -402.623f, 30.465743f, 2.517f }, // startPos
    { 49.467f, -344.118f, 90.471171f, 2.517f },  // endPos

    // Starting Waypoints
    { -0.617f, -306.765f, 70.330f, 2.517f },   // start center
    { -66.545f, -246.700f, 60.082f, 2.354f },  // end center
    { -94.406f, -251.076f, 111.694f, 4.390f }, // left 1
    { -95.940f, -306.784f, 110.108f, 4.818f }, // left 2
    { -84.214f, -328.750f, 108.429f, 5.780f }, // left 3
    { -43.594f, -346.574f, 128.981f, 0.035f }, // left 4
    { -3.449f, -337.038f, 122.448f, 0.188f },  // left 5
    { 14.184f, -243.657f, 142.407f, 1.779f },  // right 1
    { 17.443f, -273.178f, 136.369f, 2.156f },  // right 2
    { 17.748f, -236.526f, 139.634f, 1.884f },  // right 3
    { -35.472f, -214.974f, 140.048f, 3.172f }, // right 4
    { -47.900f, -219.760f, 135.246f, 3.401f }, // right 5
    { -78.433f, -237.402f, 65.301f, 5.576f },  // end center 2
    { 5.627f, -314.356f, 65.871f, 5.812f },    // start center 2
    { 14.184f, -243.657f, 142.407f, 1.779f },  // left(n) 1
    { 17.443f, -273.178f, 136.369f, 2.156f },  // left(n) 2
    { 17.748f, -236.526f, 139.634f, 1.884f },  // left(n) 3
    { -35.472f, -214.974f, 140.048f, 3.172f }, // left(n) 4
    { -47.900f, -219.760f, 135.246f, 3.401f }, // left(n) 5
    { -94.406f, -251.076f, 111.694f, 4.390f }, // right(n) 1
    { -95.940f, -306.784f, 110.108f, 4.818f }, // right(n) 2
    { -84.214f, -328.750f, 108.429f, 5.780f }, // right(n) 3
    { -43.594f, -346.574f, 128.981f, 0.035f }, // right(n) 4
    { -3.449f, -337.038f, 122.448f, 0.188f },  // right(n) 5
    { -38.087f, -302.436f, 115.977f, 2.848f }, // wayPoints aly on tornados 1
    { -60.484f, -278.438f, 115.977f, 1.265f }, // wayPoints aly on tornados 2
    { -47.210f, -241.612f, 115.977f, 0.201f }, // wayPoints aly on tornados 3
    { -24.410f, -266.740f, 115.977f, 4.980f }  // wayPoints aly on tornados 4
};

Position const WormsPos[4] =
{
    { -24.1f, -311.1f, 53.115f, 1.0f },
    { -75.1f, -296.1f, 55.533f, 4.0f },
    { -71.1f, -255.1f, 55.800f, 0.2f },
    { -17.1f, -257.1f, 55.109f, 2.0f }
};

enum Guids
{
    uiFeatherGUID = 400430
};

Position const FallPos[2] =
{
    { -41.1f, -282.1f, 54.31f, 0.188f }, // fall pos ground
    { -41.534f, -282.622f, 115.000f, 0.188f } // fall pos fly
};

Position const BirdsPos[2] =
{
    { 46.930f, -207.560f, 105.000f, 3.951f },
    { -28.813f, -378.088f, 107.371f, 1.697f }
};

Position const Talon[8] =
{
    { -6.561f, -376.156f, 75.623f, 2.017f },
    { -27.041f, -329.757f, 57.953f, 2.402f },

    { -93.998f, -338.753f, 67.583f, 1.239f },
    { -92.066f, -296.570f, 59.674f, 0.459f },

    { -85.828f, -218.517f, 71.189f, 5.014f },
    { -82.602f, -254.543f, 61.894f, 5.922f },

    { 35.679f, -260.996f, 67.902f, 3.880f },
    { 8.355f, -286.534f, 56.162f, 2.984f }
};

Position const ClawTalon[2] =
{
    { -27.773f, -191.712f, 83.280f, 4.769f },
    { -65.413f, -351.496f, 72.721f, 1.356f }
};

Position const Feather[1] =
{
    { 0.760f, -305.456f, 53.5113f, 5.597f }
};

Position const Tornado[101] =
{
    { -40.268f, -272.739f, 55.382f, 4.191f },
    { -37.955f, -289.301f, 55.673f, 3.386f },
    { -54.435f, -291.899f, 56.181f, 1.705f },
    { -54.891f, -276.776f, 55.919f, 6.064f },

    { -59.618f, -271.323f, 56.323f, 5.165f },
    { -63.114f, -285.496f, 56.309f, 5.699f },
    { -55.805f, -298.918f, 56.146f, 6.174f },
    { -38.599f, -304.341f, 55.907f, 1.018f },
    { -23.701f, -296.092f, 54.847f, 1.646f },
    { -21.894f, -278.830f, 54.687f, 2.840f },
    { -34.524f, -269.420f, 54.227f, 4.628f }, // add new waypoints
    { -46.989f, -267.882f, 54.944f, 3.237f },

    { -24.139f, -300.716f, 53.326f, 3.793f },
    { -37.279f, -314.646f, 55.623f, 2.773f },
    { -61.806f, -308.852f, 56.871f, 2.259f },
    { -75.187f, -287.070f, 56.577f, 1.324f },
    { -69.767f, -265.741f, 56.780f, 0.574f },
    { -50.085f, -253.181f, 55.990f, 5.919f },
    { -30.882f, -256.869f, 55.081f, 5.621f }, // add new waypoints
    { -17.917f, -272.053f, 53.752f, 5.295f },
    { -13.356f, -287.956f, 52.856f, 3.237f },

    { -16.950f, -244.304f, 55.931f, 5.302f },
    { 0.441f, -273.298f, 53.492f, 4.435f },
    { -2.772f, -312.061f, 53.672f, 3.524f },
    { -36.467f, -326.278f, 55.770f, 2.361f },
    { -67.491f, -317.809f, 59.693f, 1.976f },
    { -87.615f, -290.200f, 56.189f, 1.430f },
    { -63.684f, -261.048f, 55.496f, 0.431f }, // add new waypoints

    { -90.258f, -253.685f, 58.907f, 6.280f },
    { -59.377f, -229.198f, 56.394f, 6.194f },
    { -10.620f, -230.829f, 55.906f, 5.181f },
    { 11.433f, -272.349f, 53.118f, 4.101f },
    { 6.917f, -318.777f, 52.964f, 3.492f },
    { -35.572f, -337.599f, 55.996f, 2.404f },
    { -43.962f, -339.027f, 54.999f, 3.038f }, // add new waypoints
    { -84.740f, -315.165f, 59.772f, 2.319f },

    { -49.891f, -276.776f, 55.919f, 6.064f },
    { -49.435f, -291.899f, 56.181f, 1.705f },
    { -32.955f, -289.301f, 55.673f, 3.386f },
    { -35.268f, -272.739f, 55.382f, 4.191f }, // add new waypoints 6

    { -21.894f, -278.830f, 54.687f, 2.840f },
    { -23.701f, -296.092f, 54.847f, 1.646f },
    { -38.599f, -304.341f, 55.907f, 1.018f },
    { -55.805f, -298.918f, 56.146f, 6.174f },
    { -63.114f, -285.496f, 56.309f, 5.699f },
    { -59.618f, -271.323f, 56.323f, 5.165f },
    { -41.602f, -269.599f, 54.693f, 6.025f }, // add new waypoints 7

    { -50.085f, -253.181f, 55.990f, 5.919f },
    { -69.767f, -265.741f, 56.780f, 0.574f },
    { -75.187f, -287.070f, 56.577f, 1.324f },
    { -61.806f, -308.852f, 56.871f, 2.259f },
    { -37.279f, -314.646f, 55.623f, 2.773f },
    { -12.605f, -304.404f, 54.111f, 3.453f }, // add new waypoints 8

    { -87.615f, -290.200f, 56.189f, 1.430f },
    { -67.491f, -317.809f, 59.693f, 1.976f },
    { -36.467f, -326.278f, 55.770f, 2.361f },
    { -2.772f, -312.061f, 53.672f, 3.524f },
    { 0.441f, -273.298f, 53.492f, 4.435f },
    { -16.950f, -244.304f, 55.931f, 5.302f },
    { -75.172f, -265.351f, 55.610f, 0.739f }, // add new waypoints 9
    { -49.074f, -246.013f, 55.002f, 0.182f },

    { -35.572f, -337.599f, 55.996f, 2.404f },
    { 6.917f, -318.777f, 52.964f, 3.492f },
    { 11.433f, -272.349f, 53.118f, 4.101f },
    { -10.620f, -230.829f, 55.906f, 5.181f },
    { -59.377f, -229.198f, 56.394f, 6.194f },
    { -90.258f, -253.685f, 58.907f, 6.280f }, // add new waypoints 10

    { -49.435f, -291.899f, 56.181f, 1.705f },
    { -49.891f, -276.776f, 55.919f, 6.064f },
    { -35.268f, -272.739f, 55.382f, 4.191f },
    { -32.955f, -289.301f, 55.673f, 3.386f }, // add new waypoints 11

    { -38.599f, -304.341f, 55.907f, 1.018f },
    { -23.701f, -296.092f, 54.847f, 1.646f },
    { -21.894f, -278.830f, 54.687f, 2.840f },
    { -59.618f, -271.323f, 56.323f, 5.165f },
    { -63.114f, -285.496f, 56.309f, 5.699f },
    { -55.805f, -298.918f, 56.146f, 6.174f }, // add new waypoints 12

    { -75.187f, -287.070f, 56.577f, 1.324f },
    { -69.767f, -265.741f, 56.780f, 0.574f },
    { -50.085f, -253.181f, 55.990f, 5.919f },
    { -12.605f, -304.404f, 54.111f, 3.453f },
    { -37.279f, -314.646f, 55.623f, 2.773f },
    { -61.806f, -308.852f, 56.871f, 2.259f }, // add new waypoints 13

    { -36.467f, -326.278f, 55.770f, 2.361f },
    { -67.491f, -317.809f, 59.693f, 1.976f },
    { -87.615f, -290.200f, 56.189f, 1.430f },
    { -16.950f, -244.304f, 55.931f, 5.302f },
    { 0.441f, -273.298f, 53.492f, 4.435f },
    { -2.772f, -312.061f, 53.672f, 3.524f }, // add new waypoints 14

    { 11.433f, -272.349f, 53.118f, 4.101f },
    { 6.917f, -318.777f, 52.964f, 3.492f },
    { -35.572f, -337.599f, 55.996f, 2.404f },
    { -90.258f, -253.685f, 58.907f, 6.280f },
    { -59.377f, -229.198f, 56.394f, 6.194f },
    { -10.620f, -230.829f, 55.906f, 5.181f },

    { -74.814f, -265.562f, 55.603f, 0.752f },
    { -55.637f, -250.917f, 55.153f, 0.579f },
    { -29.980f, -237.878f, 56.415f, 0.515f },
    { -53.657f, -227.827f, 55.529f, 3.927f },
    { -84.362f, -254.066f, 56.706f, 4.444f }
};

Position const SpawnVolcanos[11] =
{
    { 5.375f, -336.376f, 51.629f, 2.304f },
    { 9.478f, -331.562f, 51.387f, 2.304f },
    { 16.252f, -323.355f, 51.448f, 2.304f },
    { 19.871f, -320.852f, 51.960f, 2.304f },
    { 22.058f, -315.533f, 51.959f, 2.304f },
    { 28.059f, -307.899f, 51.958f, 2.304f },
    { 32.530f, -300.595f, 51.965f, 2.304f },

    { -103.034f, -294.838f, 56.158f, 2.304f },
    { -103.872f, -286.840f, 56.507f, 2.304f },
    { -103.593f, -280.863f, 56.531f, 2.304f },
    { -104.593f, -274.393f, 56.534f, 2.304f }
};

Position const StaghelmMainPos = {27.689f, -329.403f, 51.2989f, 2.484159f}; // Staghelm Main Position (Center Alysrazor)
Position const StaghelmFlyUpPos = {27.0f, -329.0f, 83.892f, 2.339993f};
Position const StaghelmFlyQuitPos = {100.629f, -403.324f, 130.258f, 5.486381f}; // Staghelm Fly Away Quit Pos (Fly to his Encounter Pos)
Position const StaghelmTakeOff = {27.0f, -329.0f, 58.382f, 2.311995f};

enum actions
{
    ACTION_MOVE_FROM_LEFT   = 0,
    ACTION_MOVE_FROM_RIGHT  = 1,
    ACTION_START_GAUNTLET,
    ACTION_DROP_FEATHER
};

enum Texts
{
    // Egg Pile
    EMOTE_CRACKING_EGGS = 0,    // The Molten Eggs begin to crack and splinter!

    // Majordomo
    SAY_MAJO_INTRO    = 0,
    SAY_MAJO_STEP_ONE = 1,
    SAY_MAJO_FINISH   = 2,

    // Alysrazor
    SAY_ALY_START     = 0,
    SAY_ALY_DEATH     = 1, // 24429 | The light... mustn't... burn out...
    SAY_ALY_KILLER_1  = 2, // 24430 | BURN!
    SAY_ALY_KILLER_2  = 3, // 24431 | For his Glory!
    SAY_ALY_TORNADO_1 = 4, // 24434 | These skies are MINE!
    SAY_ALY_TORNADO_2 = 5, // 24435 | I will burn you from the sky!
    SAY_ALY_BURNOUT   = 6, // 24436 | Fire... fire...
    SAY_ALY_REBORN    = 7, // 24437 | Reborn in flame!

    // Trash
    SAY_HELP_ALY      = 0,

    SAY_RAND_1        = 0,
    SAY_RAND_2        = 1,
    SAY_RAND_3        = 3,
    SAY_RAND_4        = 4
};

enum Spells
{
    SPELL_FIRESTORM = 99605,

    // Volcanos
    SPELL_VOLCANO_DUMMY = 98402,
    SPELL_VOLCANO_AURA = 98462,

    // Tornados
    SPELL_SUMMON_DMG = 99793,

    // Feather
    SPELL_COSMETIC = 99507,
    SPELL_CAST_ON_MOVE_VISUAL = 97128,

    // Firehawk
    SPELL_FIREHAWK_COSMETIC = 100712,
    SPELL_FIREHAWK_TRANSFORM_M = 99550,
    SPELL_FIREHAWK_TRANSFORM_F = 100350,
    SPELL_FIREHAWK_CLAWSHAPPER = 99923,
    SPELL_FIREHAWK_REMOVE_FORM = 99924,
    SPELL_IGNITION = 99919,
    SPELL_BRUSHFIRE = 98868,
    SPELL_FIEROBLAST = 101223,
    SPELL_FIREITUP = 100093,
    SPELL_BRUSHFIRE_VIS = 98884,

    // Hatchling
    SPELL_SATIATED = 99359,
    SPELL_HUNGRY = 99361,
    SPELL_TANTRUM = 99362,
    SPELL_IMPRINTED = 99389,
    SPELL_TAUNT = 99390,
    SPELL_DEBUFF = 100024,

    // Worm
    SPELL_LAVA_SPEW = 99335,

    // Blazing power
    SPELL_BLAZING_POWER = 99462,

    // Cloud
    SPELL_INCENDIARY_CLOUD = 99426,

    // Alysrazor
    SPELL_INDICATOR = 101410,
    SPELL_BLAZING_CLAW = 99843,
    SPELL_PASSIVE_BUF_FROM_FEATHER = 99461,
    SPELL_BURNOUT = 99432,
    SPELL_IGNITED = 99922,
    SPELL_SPARK = 99921,
    SPELL_ZERO_POWER = 72242,
    SPELL_FULL_POWER = 99504,
    SPELL_SUMMON_FEATHER = 99464,
    SPELL_MOLTING = 100698,

    // Alysrazor Gauntlet
    SPELL_ROOT_PLAYERS = 100559,
    SPELL_CAM_SHAKE    = 94955, // not the correct one, but thats wayne

    SPELL_FLY = 98619,
    SPELL_HARSH_WINDS = 100640,

    //molten egg
    SPELL_EGG_EXPLOSION = 99943,
    SPELL_SUMM_HATHING = 99723,

    //broodmother
    SPELL_BROODMOTHER_VIS = 99734,
    SPELL_BROODMOTHER_VIS1 = 100712,

    // Harbinger of Flame
    SPELL_FIRE_IT_UP = 100093,
    SPELL_FIEROBLAST_TRASH = 100094,
    SPELL_FIEROCLAST_BARRAGE = 100095,
    SPELL_FIRE_CHANNELING = 100109,

    // Blazing Monstrosity
    SPELL_RIDE_MONSTROSITY = 93970,
    SPELL_SHARE_HEALTH_LEFT = 101502,
    SPELL_SHARE_HEALTH_RIGHT = 101503,
    SPELL_SLEEP_ULTRA_HIGH_PRIORITY = 99480,
    SPELL_GENERIC_DUMMY_CAST = 100088,
    SPELL_LEFT_SIDE_SMACK_L = 100076,
    SPELL_RIGHT_SIDE_SMACK_L = 100078,
    SPELL_HEAD_BONK_L = 100080,
    SPELL_TICKLE_L = 100082,
    SPELL_KNOCKBACK_RIGHT = 100084,
    SPELL_KNOCKBACK_LEFT = 100085,
    SPELL_KNOCKBACK_FORWARD = 100086,
    SPELL_KNOCKBACK_BACK = 100087,
    SPELL_HEAD_BONK_R = 100089,
    SPELL_LEFT_SIDE_SMACK_R = 100090,
    SPELL_RIGHT_SIDE_SMACK_R = 100091,
    SPELL_TICKLE_R = 100092,
    SPELL_MOLTEN_BARRAGE_EFFECT_L = 100071,
    SPELL_MOLTEN_BARRAGE_LEFT = 100072,
    SPELL_MOLTEN_BARRAGE_RIGHT = 100073,
    SPELL_MOLTEN_BARRAGE_EFFECT_R = 100074,
    SPELL_MOLTEN_BARRAGE_VISUAL = 100075,
    SPELL_AGGRO_CLOSEST = 100462,
    SPELL_INVISIBILITY_AND_STEALTH_DETECTION = 18950,

    // Egg Pile
    SPELL_SUMMON_SMOULDERING_HATCHLING = 100096,
    SPELL_MOLTEN_EGG_TRASH_CALL_L = 100097,
    SPELL_MOLTEN_EGG_TRASH_CALL_R = 100098,
    SPELL_ALYSRAZOR_COSMETIC_EGG_XPLOSION = 100099
};

#define SPELL_SHARE_HEALTH          (me->GetEntry() == NPC_BLAZING_MONSTROSITY_LEFT ? SPELL_SHARE_HEALTH_LEFT : SPELL_SHARE_HEALTH_RIGHT)
#define SPELL_MOLTEN_BARRAGE        (me->GetEntry() == NPC_BLAZING_MONSTROSITY_LEFT ? SPELL_MOLTEN_BARRAGE_LEFT : SPELL_MOLTEN_BARRAGE_RIGHT)
#define SPELL_MOLTEN_BARRAGE_EFFECT (me->GetEntry() == NPC_BLAZING_MONSTROSITY_LEFT ? SPELL_MOLTEN_BARRAGE_EFFECT_L : SPELL_MOLTEN_BARRAGE_EFFECT_R)

enum Phase
{
    PHASE_NONE = 0,

    PHASE_JUMP = 1, PHASE_START_MOVING = 2, PHASE_AIR = 3, PHASE_GROUND = 4, PHASE_TORNADO = 5
};

enum Events
{
    EVENT_START_ENCOUNTER = 1,

    // Moving
    EVENT_MOVE_TO_START_OF_TOP = 2,
    EVENT_MOVE_TO_END_OF_TOP = 3,
    EVENT_MOVE_TO_LEFT_1 = 4,
    EVENT_MOVE_TO_LEFT_2 = 5,
    EVENT_MOVE_TO_LEFT_3 = 6,
    EVENT_MOVE_TO_LEFT_4 = 7,
    EVENT_MOVE_TO_LEFT_5 = 8,
    EVENT_MOVE_TO_RIGHT_1 = 9,
    EVENT_MOVE_TO_RIGHT_2 = 10,
    EVENT_MOVE_TO_RIGHT_3 = 11,
    EVENT_MOVE_TO_RIGHT_4 = 12,
    EVENT_MOVE_TO_RIGHT_5 = 13,
    EVENT_MOVE_TO_END_CENTER = 14,
    EVENT_MOVE_TO_END_START = 15,
    EVENT_MOVE_TO_LEFT_N_1 = 16,
    EVENT_MOVE_TO_LEFT_N_2 = 17,
    EVENT_MOVE_TO_LEFT_N_3 = 18,
    EVENT_MOVE_TO_LEFT_N_4 = 19,
    EVENT_MOVE_TO_LEFT_N_5 = 20,
    EVENT_MOVE_TO_RIGHT_N_1 = 21,
    EVENT_MOVE_TO_RIGHT_N_2 = 22,
    EVENT_MOVE_TO_RIGHT_N_3 = 23,
    EVENT_MOVE_TO_RIGHT_N_4 = 24,
    EVENT_MOVE_TO_RIGHT_N_5 = 25,

    EVENT_MOVE_TORNADOS_1 = 26,
    EVENT_MOVE_TORNADOS_2 = 27,
    EVENT_MOVE_TORNADOS_3 = 28,
    EVENT_MOVE_TORNADOS_4 = 29,

    EVENT_MOVE_TO_TORNADO = 30,

    // Need for combat
    EVENT_ZONE_COMBAT = 31,

    // Phase
    EVENT_PHASE_2_TORNADOS_START = 32,
    EVENT_PHASE_2_TORNADOS_ENDS = 33,

    EVENT_INCENDIARY_CLOUD = 34,
    EVENT_HARSH_WINDS = 35,

    // Hatchling
    EVENT_EAT_WORM = 36,
    EVENT_HUNGRY = 37,
    EVENT_DEBUFF = 38,

    // Lava worm
    EVENT_CALC_ORIENT = 39,
    EVENT_SUMMON_WORMS = 40,

    EVENT_SUMMON_BROODMOTHER = 41,

    // Egg
    EVENT_EGG_EXPLOSION = 42,
    EVENT_SUMMON_HATCHING = 43,
    EVENT_DESPAWN = 44,

    // Clawshaper
    EVENT_SUMMON_DRUIDS = 45,
    EVENT_START_IGNITION = 46,
    EVENT_START_COMBAT = 47,
    EVENT_CHECK_ENERGY = 48,

    EVENT_START_FIEROBLAST = 49,
    EVENT_START_BRUSHFIRE = 50,
    EVENT_TALK_DURING_ENCOUNTER = 51,

    EVENT_SUMMON_TALON = 52,

    // Blazing Monstrosity
    EVENT_START_SPITTING = 1,
    EVENT_CONTINUE_SPITTING = 2,

    // Harbinger of Flame
    EVENT_FIEROBLAST = 1,
    EVENT_FIEROCLAST_BARRAGE = 2,

    // Egg Pile
    EVENT_SUMMON_SMOULDERING_HATCHLING = 1,

    // Alysrazor Gauntlet
    EVENT_ROOT_PLAYERS   = 1,
    EVENT_MOVE_CENTER    = 2,
    EVENT_TALK_SHIT      = 3,
    EVENT_TALK_SHIT_1    = 4,
    EVENT_TALK_SHIT_2    = 5,
    EVENT_TRANSFORM_HAWK = 6,
    EVENT_FLY_UP         = 7,
    EVENT_FLYAWAY        = 8,
};

enum MiscData
{
    MODEL_INVISIBLE_STALKER = 11686,
    MODEL_FIREHAWK = 38013,
    ANIM_KIT_BIRD_WAKE = 1469,
    ANIM_KIT_BIRD_TURN = 1473,
};

class RespawnEggEvent: public BasicEvent
{
    public:
        explicit RespawnEggEvent(Creature* egg) :
                _egg(egg)
        {
        }

        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            _egg->RestoreDisplayId();
            return true;
        }

    private:
        Creature* _egg;
};

class MoltenEggCheck
{
    public:
        explicit MoltenEggCheck(Creature* pile) :
                _eggPile(pile)
        {
        }

        bool operator()(Unit* object) const
        {
            if (object->GetEntry() != NPC_MOLTEN_EGG_TRASH)
                return false;

            if (object->GetDisplayId() != object->GetNativeDisplayId())
                return false;

            if (_eggPile->GetDistance2d(object) > 20.0f)
                return false;
            return true;
        }

    private:
        Creature* _eggPile;
};

class TrashRespawnWorker
{
    public:
        void operator()(Creature* creature) const
        {
            switch (creature->GetEntry())
            {
                case NPC_BLAZING_MONSTROSITY_LEFT:
                case NPC_BLAZING_MONSTROSITY_RIGHT:
                case NPC_EGG_PILE:
                case NPC_HARBINGER_OF_FLAME:
                case NPC_MOLTEN_EGG_TRASH:
                    if (!creature->isAlive())
                        creature->Respawn(true);
                    break;
                case NPC_SMOULDERING_HATCHLING:
                    creature->DespawnOrUnsummon();
                    break;
            }
        }
};

static void AlysrazorTrashEvaded(Creature* creature)
{
    TrashRespawnWorker check;
    Trinity::CreatureWorker<TrashRespawnWorker> worker(creature, check);
    creature->VisitNearbyGridObject(SIZE_OF_GRIDS, worker);
}

class npc_harbinger_of_flame: public CreatureScript
{
    public:
        npc_harbinger_of_flame() :
                CreatureScript("npc_harbinger_of_flame")
        {
        }

        struct npc_harbinger_of_flameAI: public ScriptedAI
        {
                npc_harbinger_of_flameAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                }

                void EnterCombat(Unit* /*target*/)
                {
                    if (Creature* bird = ObjectAccessor::GetCreature(*me,
                            me->GetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT)))
                        DoZoneInCombat(bird, 200.0f);

                    me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                    _events.Reset();
                    _events.ScheduleEvent(EVENT_FIEROBLAST, 1);
                    _events.ScheduleEvent(EVENT_FIEROCLAST_BARRAGE, 6000);
                }

                void JustReachedHome()
                {
//                    AlysrazorTrashEvaded(me);
                }

                void MoveInLineOfSight(Unit* unit)
                {
                    if (me->isInCombat())
                        return;

                    if (!unit->isCharmedOwnedByPlayerOrPlayer())
                        return;

                    ScriptedAI::MoveInLineOfSight(unit);
                }

                void UpdateAI(uint32 const diff)
                {
                    if (!me->isInCombat())
                        if (!me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                            if (Creature* fireBird = me->FindNearestCreature(
                                    (me->GetHomePosition().GetPositionY() > -275.0f ?
                                            NPC_BLAZING_MONSTROSITY_LEFT : NPC_BLAZING_MONSTROSITY_RIGHT), 100.0f))
                                DoCast(fireBird, SPELL_FIRE_CHANNELING);

                    if (!UpdateVictim())
                        return;

                    _events.Update(diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    while (uint32 eventId = _events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_FIEROBLAST:
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, false,
                                        -SPELL_RIDE_MONSTROSITY))
                                    DoCast(target, SPELL_FIEROBLAST_TRASH);
                                _events.RescheduleEvent(EVENT_FIEROBLAST, 500);
                                break;
                            case EVENT_FIEROCLAST_BARRAGE:
                                DoCastAOE(SPELL_FIEROCLAST_BARRAGE);
                                _events.ScheduleEvent(EVENT_FIEROCLAST_BARRAGE, urand(9000, 12000));
                                break;
                        }
                    }
                    DoMeleeAttackIfReady();
                }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_harbinger_of_flameAI(creature);
        }
};

class npc_blazing_monstrosity: public CreatureScript
{
    public:
        npc_blazing_monstrosity() :
                CreatureScript("npc_blazing_monstrosity")
        {
        }

        struct npc_blazing_monstrosityAI: public PassiveAI
        {
                npc_blazing_monstrosityAI(Creature* creature) :
                        PassiveAI(creature), _summons(creature)
                {
                }

                void EnterEvadeMode()
                {
                    _summons.DespawnAll();
                    _events.Reset();
                    PassiveAI::EnterEvadeMode();
                }

                void JustDied(Unit* /*killer*/)
                {
                    _summons.DespawnAll();
                    me->DespawnOrUnsummon(5000);
                    _events.Reset();
                }

                void JustReachedHome()
                {
//                    AlysrazorTrashEvaded(me);
                }

                void EnterCombat(Unit* /*target*/)
                {
                    DoZoneInCombat();
                    me->RemoveAurasDueToSpell(SPELL_SLEEP_ULTRA_HIGH_PRIORITY);
                    me->PlayOneShotAnimKit(ANIM_KIT_BIRD_WAKE);
                    _events.Reset();
                    _events.ScheduleEvent(EVENT_START_SPITTING, 6000);
                    _events.ScheduleEvent(EVENT_CONTINUE_SPITTING, 9000);
                }

                void DespawnVehicles(uint32 entry)
                {
                    std::list<Creature*> creatures;
                    GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);
                    if (creatures.empty())
                        return;
                    for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                        (*iter)->DespawnOrUnsummon();
                }

                void PassengerBoarded(Unit* passenger, int8 /*seat*/, bool apply)
                {
                    if (!apply)
                        return;

                    // Our passenger is another vehicle (boardable by players)
                    DoCast(passenger, SPELL_SHARE_HEALTH, true);
                    passenger->setFaction(35);
                    passenger->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                    Movement::MoveSplineInit init(passenger);
                    init.DisableTransportPathTransformations();
                    init.MoveTo(0.6654003f, 0.0f, 1.9815f);
                    init.SetFacing(0.0f);
                    init.Launch();
                }

                void JustSummoned(Creature* summon)
                {
                    _summons.Summon(summon);
                }

                void SummonedCreatureDespawn(Creature* summon)
                {
                    _summons.Despawn(summon);
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim())
                        return;

                    if (Creature* lefthawk = me->FindNearestCreature(NPC_BLAZING_MONSTROSITY_LEFT, 20, false))
                        if (lefthawk->isDead())
                            DespawnVehicles(NPC_BLAZING_MONSTROSITY_VEHICLE_L);

                    if (Creature* righthawk = me->FindNearestCreature(NPC_BLAZING_MONSTROSITY_RIGHT, 20, false))
                        if (righthawk->isDead())
                            DespawnVehicles(NPC_BLAZING_MONSTROSITY_VEHICLE_R);

                    _events.Update(diff);

                    while (uint32 eventId = _events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_START_SPITTING:
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, false,
                                        -SPELL_RIDE_MONSTROSITY))
                                    DoCast(target, SPELL_MOLTEN_BARRAGE);
                                break;
                            case EVENT_CONTINUE_SPITTING:
                                DoCastAOE(SPELL_MOLTEN_BARRAGE_EFFECT);
                                if (Creature* egg = me->FindNearestCreature(NPC_EGG_PILE, 100.0f))
                                    egg->AI()->DoAction(me->GetEntry());
                                break;
                        }
                    }
                }

            private:
                SummonList _summons;
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_blazing_monstrosityAI(creature);
        }
};

class npc_molten_barrage: public CreatureScript
{
    public:
        npc_molten_barrage() :
                CreatureScript("npc_molten_barrage")
        {
        }

        struct npc_molten_barrageAI: public NullCreatureAI
        {
                npc_molten_barrageAI(Creature* creature) :
                        NullCreatureAI(creature)
                {
                }

                void AttackStart(Unit* target)
                {
                    if (target)
                        me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f, MOTION_SLOT_IDLE);
                }

                void IsSummonedBy(Unit* /*summoner*/)
                {
                    DoCastAOE(SPELL_AGGRO_CLOSEST, true);
                    DoCast(me, SPELL_MOLTEN_BARRAGE_VISUAL);
                    DoCast(me, SPELL_INVISIBILITY_AND_STEALTH_DETECTION, true);
                }

                void MovementInform(uint32 movementType, uint32 /*pointId*/)
                {
                    if (movementType != EFFECT_MOTION_TYPE)
                        return;

                    DoCastAOE(SPELL_AGGRO_CLOSEST);
                    me->ClearUnitState(UNIT_STATE_CANNOT_TURN);
                }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_molten_barrageAI(creature);
        }
};

class npc_egg_pile: public CreatureScript
{
    public:
        npc_egg_pile() :
                CreatureScript("npc_egg_pile")
        {
        }

        struct npc_egg_pileAI: public CreatureAI
        {
                npc_egg_pileAI(Creature* creature) :
                        CreatureAI(creature)
                {
                }

                void AttackStart(Unit* /*target*/)
                {
                }

                void Reset()
                {
                    me->SetReactState(REACT_PASSIVE);
                    _events.Reset();
                    _callHatchlingSpell = 0;
                }

                void JustDied(Unit* /*killer*/)
                {
                    _events.Reset();
                    std::list<Creature*> eggs;
                    GetCreatureListWithEntryInGrid(eggs, me, NPC_MOLTEN_EGG_TRASH, 20.0f);
                    for (std::list<Creature*>::const_iterator itr = eggs.begin(); itr != eggs.end(); ++itr)
                        (*itr)->CastSpell(*itr, SPELL_ALYSRAZOR_COSMETIC_EGG_XPLOSION, TRIGGERED_FULL_MASK);

                    DoCast(me, SPELL_ALYSRAZOR_COSMETIC_EGG_XPLOSION, true);
                }

                void JustReachedHome()
                {
//                    AlysrazorTrashEvaded(me);
                }

                void DoAction(int32 const action)
                {
                    if (action != NPC_BLAZING_MONSTROSITY_LEFT && action != NPC_BLAZING_MONSTROSITY_RIGHT)
                        return;

                    if (action == NPC_BLAZING_MONSTROSITY_LEFT)
                        Talk(EMOTE_CRACKING_EGGS);

                    _callHatchlingSpell =
                            (action == NPC_BLAZING_MONSTROSITY_LEFT) ?
                                    SPELL_MOLTEN_EGG_TRASH_CALL_L : SPELL_MOLTEN_EGG_TRASH_CALL_R;
                    DoZoneInCombat();
                    _events.Reset();
                    _events.ScheduleEvent(EVENT_SUMMON_SMOULDERING_HATCHLING, 1);
                }

                void UpdateAI(uint32 const diff)
                {
                    if (!UpdateVictim())
                        return;

                    _events.Update(diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    while (uint32 eventId = _events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_SUMMON_SMOULDERING_HATCHLING:
                            {
                                std::list<Creature*> eggs;
                                MoltenEggCheck check(me);
                                Trinity::CreatureListSearcher<MoltenEggCheck> searcher(me, eggs, check);
                                me->VisitNearbyGridObject(20.0f, searcher);
                                if (!eggs.empty())
                                {
                                    Creature* egg = Trinity::Containers::SelectRandomContainerElement(eggs);
                                    egg->CastSpell(egg, SPELL_SUMMON_SMOULDERING_HATCHLING, TRIGGERED_FULL_MASK);
                                    egg->SetDisplayId(MODEL_INVISIBLE_STALKER);
                                    egg->m_Events.AddEvent(new RespawnEggEvent(egg), egg->m_Events.CalculateTime(5000));
                                }

                                if (_callHatchlingSpell)
                                    DoCastAOE(_callHatchlingSpell, true);
                                _events.ScheduleEvent(EVENT_SUMMON_SMOULDERING_HATCHLING, urand(6000, 10000));
                                break;
                            }
                            default:
                                break;
                        }
                    }
                    DoMeleeAttackIfReady();
                }

            private:
                EventMap _events;
                uint32 _callHatchlingSpell;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_egg_pileAI(creature);
        }
};

class spell_alysrazor_cosmetic_egg_xplosion: public SpellScriptLoader
{
    public:
        spell_alysrazor_cosmetic_egg_xplosion() :
                SpellScriptLoader("spell_alysrazor_cosmetic_egg_xplosion")
        {
        }

        class spell_alysrazor_cosmetic_egg_xplosion_SpellScript: public SpellScript
        {
                PrepareSpellScript(spell_alysrazor_cosmetic_egg_xplosion_SpellScript)
                ;

                bool Validate(SpellInfo const* /*spellInfo*/)
                {
                    if (!sCreatureDisplayInfoStore.LookupEntry(MODEL_INVISIBLE_STALKER))
                        return false;
                    return true;
                }

                void HandleExplosion(SpellEffIndex effIndex)
                {
                    PreventHitDefaultEffect(effIndex);
                    GetHitUnit()->SetDisplayId(MODEL_INVISIBLE_STALKER);
                    if (Creature* creature = GetHitCreature())
                        creature->DespawnOrUnsummon(4000);
                }

                void Register()
                {
                    OnEffectHitTarget +=
                            SpellEffectFn(spell_alysrazor_cosmetic_egg_xplosion_SpellScript::HandleExplosion, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_alysrazor_cosmetic_egg_xplosion_SpellScript();
        }
};

class spell_alysrazor_turn_monstrosity: public SpellScriptLoader
{
    public:
        spell_alysrazor_turn_monstrosity() :
                SpellScriptLoader("spell_alysrazor_turn_monstrosity")
        {
        }

        class spell_alysrazor_turn_monstrosity_SpellScript: public SpellScript
        {
                PrepareSpellScript(spell_alysrazor_turn_monstrosity_SpellScript)
                ;

                bool Validate(SpellInfo const* /*spellInfo*/)
                {
                    if (!sSpellMgr->GetSpellInfo(SPELL_GENERIC_DUMMY_CAST))
                    return false;
                    if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_RIGHT))
                    return false;
                    if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_LEFT))
                    return false;
                    if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_FORWARD))
                    return false;
                    if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_BACK))
                    return false;
                    return true;
                }

                void KnockBarrage(SpellEffIndex effIndex)
                {
                    PreventHitDefaultEffect(effIndex);
                    GetHitUnit()->GetMotionMaster()->MoveIdle();
                    if (TempSummon* summ = GetHitUnit()->ToTempSummon())
                    if (Unit* summoner = summ->GetSummoner())
                    GetHitUnit()->CastSpell(summoner, SPELL_GENERIC_DUMMY_CAST, TRIGGERED_FULL_MASK);

                    float angle = 0.0f;

                    if (Unit* bird = GetCaster()->GetVehicleBase())
                    {
                        bird->SetInFront(GetHitUnit());
                        angle = bird->GetOrientation();
                    }

                    uint32 spellId = 0;
                    switch (GetSpellInfo()->Id)
                    {
                        case SPELL_RIGHT_SIDE_SMACK_R:
                        case SPELL_RIGHT_SIDE_SMACK_L:
                        spellId = SPELL_KNOCKBACK_RIGHT;
                        angle -= M_PI * 0.5f;
                        break;
                        case SPELL_LEFT_SIDE_SMACK_R:
                        case SPELL_LEFT_SIDE_SMACK_L:
                        spellId = SPELL_KNOCKBACK_LEFT;
                        angle += M_PI * 0.5f;
                        break;
                        case SPELL_HEAD_BONK_R:
                        case SPELL_HEAD_BONK_L:
                        spellId = SPELL_KNOCKBACK_FORWARD;
                        break;
                        case SPELL_TICKLE_R:
                        case SPELL_TICKLE_L:
                        spellId = SPELL_KNOCKBACK_BACK;
                        angle -= M_PI;
                        break;
                    }

                    // Cannot wait for object update to process facing spline, it's needed in next spell cast
                    GetHitUnit()->SetOrientation(angle);
                    GetHitUnit()->SetFacingTo(angle);
                    GetHitUnit()->AddUnitState(UNIT_STATE_CANNOT_TURN);
                    GetHitUnit()->CastSpell(GetHitUnit(), spellId, TRIGGERED_FULL_MASK);
                }

                void TurnBird(SpellEffIndex effIndex)
                {
                    PreventHitDefaultEffect(effIndex);
                    GetHitUnit()->PlayOneShotAnimKit(ANIM_KIT_BIRD_TURN);
                }

                void Register()
                {
                    OnEffectHitTarget += SpellEffectFn(spell_alysrazor_turn_monstrosity_SpellScript::KnockBarrage, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                    OnEffectHitTarget += SpellEffectFn(spell_alysrazor_turn_monstrosity_SpellScript::TurnBird, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
                }
            };

            SpellScript* GetSpellScript() const
            {
                return new spell_alysrazor_turn_monstrosity_SpellScript();
            }
        };

class spell_alysrazor_aggro_closest: public SpellScriptLoader
{
    public:
        spell_alysrazor_aggro_closest() :
                SpellScriptLoader("spell_alysrazor_aggro_closest")
        {
        }

        class spell_alysrazor_aggro_closest_SpellScript: public SpellScript
        {
                PrepareSpellScript(spell_alysrazor_aggro_closest_SpellScript)
                ;

                bool Load()
                {
                    return GetCaster()->GetTypeId() == TYPEID_UNIT;
                }

                void HandleEffect(SpellEffIndex effIndex)
                {
                    PreventHitDefaultEffect(effIndex);
                    float curThreat = GetCaster()->getThreatManager().getThreat(GetHitUnit(), true);
                    GetCaster()->getThreatManager().addThreat(GetHitUnit(),
                            -curThreat + 50000.0f / std::min(1.0f, GetCaster()->GetDistance(GetHitUnit())));
                }

                void UpdateThreat()
                {
                    GetCaster()->ClearUnitState(UNIT_STATE_CASTING);
                    GetCaster()->GetAI()->AttackStart(GetCaster()->ToCreature()->SelectVictim());
                }

                void Register()
                {
                    OnEffectHitTarget +=
                            SpellEffectFn(spell_alysrazor_aggro_closest_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
                    AfterCast += SpellCastFn(spell_alysrazor_aggro_closest_SpellScript::UpdateThreat);
                }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_alysrazor_aggro_closest_SpellScript();
        }
};

class spell_alysrazor_fieroblast: public SpellScriptLoader
{
    public:
        spell_alysrazor_fieroblast() :
                SpellScriptLoader("spell_alysrazor_fieroblast")
        {
        }

        class spell_alysrazor_fieroblast_SpellScript: public SpellScript
        {
                PrepareSpellScript(spell_alysrazor_fieroblast_SpellScript)
                ;

                bool Validate(SpellInfo const* /*spellInfo*/)
                {
                    if (!sSpellMgr->GetSpellInfo(SPELL_FIRE_IT_UP))
                    return false;
                    return true;
                }

                void FireItUp()
                {
                    GetCaster()->CastSpell(GetCaster(), SPELL_FIRE_IT_UP, TRIGGERED_FULL_MASK);
                }

                void Register()
                {
                    AfterCast += SpellCastFn(spell_alysrazor_fieroblast_SpellScript::FireItUp);
                }
            };

            SpellScript* GetSpellScript() const
            {
                return new spell_alysrazor_fieroblast_SpellScript();
            }
        };

class mob_molten_feather: public CreatureScript // 53089
{
    public:
        mob_molten_feather() :
                CreatureScript("mob_molten_feather")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_molten_featherAI(creature);
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            if (Creature* alysrazor = creature->FindNearestCreature(NPC_ALYSRAZOR, 5000.0f))
                player->CastSpell(player, SPELL_CAST_ON_MOVE_VISUAL, true);
            else
                player->SummonCreature_OP(NPC_ALYSRAZOR, SpawnPos[0]);

            creature->DespawnOrUnsummon();
            return true;
        }

        struct mob_molten_featherAI: public ScriptedAI
        {
                mob_molten_featherAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                    DoCast(me, SPELL_COSMETIC);
                }
        };
};

class mob_incendiary_cloud: public CreatureScript // 53541
{
    public:
        mob_incendiary_cloud() :
                CreatureScript("mob_incendiary_cloud")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_incendiary_cloudAI(creature);
        }

        struct mob_incendiary_cloudAI: public ScriptedAI
        {
                mob_incendiary_cloudAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                    creature->SetDisplayId(11686);
                }

                uint32 timer;

                void IsSummonedBy(Unit* summoner)
                {
                    DoCast(me, SPELL_INCENDIARY_CLOUD);
                    timer = 10000;
                }

                void UpdateAI(const uint32 diff)
                {
                    if (timer <= diff)
                        me->DespawnOrUnsummon();
                    else
                        timer -= diff;
                }
        };
};

class mob_blazing_power: public CreatureScript // 53554
{
    public:
        mob_blazing_power() : CreatureScript("mob_blazing_power") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_blazing_powerAI(creature);
        }

        struct mob_blazing_powerAI: public ScriptedAI
        {
                mob_blazing_powerAI(Creature* creature) : ScriptedAI(creature)
                {
                    creature->SetDisplayId(11686);
                }

                bool despawn;
                uint32 timer;

                void IsSummonedBy(Unit* summoner)
                {
                    DoCast(me, SPELL_BLAZING_POWER);
                    timer = 10000;
                }

                void UpdateAI(const uint32 diff)
                {
                    me->GetMotionMaster()->MovePoint(0, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());

                    if (timer <= diff)
                        me->DespawnOrUnsummon();
                    else
                        timer -= diff;
                }
        };
};

class npc_alysrazor_volcano: public CreatureScript // 53158
{
    public:
        npc_alysrazor_volcano() :
                CreatureScript("npc_alysrazor_volcano")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_alysrazor_volcanoAI(creature);
        }

        struct npc_alysrazor_volcanoAI: public ScriptedAI
        {
                npc_alysrazor_volcanoAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                    creature->SetDisplayId(11686);
                }

                bool started;
                uint32 timerAur;

                void Reset()
                {
                    started = false;
                }

                void IsSummonedBy(Unit* summoner)
                {
                    summoner->CastSpell(me, SPELL_VOLCANO_DUMMY, false);
                    started = true;
                    timerAur = 2000;
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!started || me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    if (timerAur <= diff)
                    {
                        if (!me->HasAura(SPELL_VOLCANO_AURA))
                            me->CastSpell(me, SPELL_VOLCANO_AURA, true);
                    }
                    else
                        timerAur -= diff;
                }
        };
};

class npc_voracious_hatchling: public CreatureScript // 53509
{
    public:
        npc_voracious_hatchling() :
                CreatureScript("npc_voracious_hatchling")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_voracious_hatchlingAI(creature);
        }

        struct npc_voracious_hatchlingAI: public ScriptedAI
        {
                npc_voracious_hatchlingAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                }

                EventMap events;

                void IsSummonedBy(Unit* summoner)
                {
                    me->ModifyAuraState(AURA_STATE_UNKNOWN22, true);
                    if (Unit* FirstTarget = me->FindNearestPlayer(300.0f, true))
                    {
                        me->AI()->AttackStart(FirstTarget);
                        DoCast(FirstTarget, SPELL_IMPRINTED);
                        FirstTarget->CastSpell(me, SPELL_TAUNT, false);
                        events.ScheduleEvent(EVENT_EAT_WORM, 1000);
                        events.ScheduleEvent(EVENT_HUNGRY, 9000);
                        events.ScheduleEvent(EVENT_DEBUFF, 15000);
                        me->AI()->AttackStart(FirstTarget);
                    }
                }

                void JustDied(Unit* /*killer*/)
                {
                    me->DespawnOrUnsummon(5000);
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_DEBUFF:
                            {
                                DoCast(me, SPELL_DEBUFF);
                                events.ScheduleEvent(EVENT_DEBUFF, 60000);
                            }
                            case EVENT_EAT_WORM:
                            {
                                if (Creature* worm = me->FindNearestCreature(53520, 5.0f, true))
                                {
                                    worm->DespawnOrUnsummon();
                                    DoCast(me, SPELL_SATIATED);
                                    if (me->HasAura(SPELL_HUNGRY))
                                        me->RemoveAura(SPELL_HUNGRY);
                                    if (me->HasAura(SPELL_TANTRUM))
                                        me->RemoveAura(SPELL_TANTRUM);
                                }
                                events.ScheduleEvent(EVENT_EAT_WORM, 1000);
                                break;
                            }
                            case EVENT_HUNGRY:
                            {
                                if (!me->HasAura(SPELL_SATIATED) && !me->HasAura(SPELL_HUNGRY))
                                {
                                    DoCast(me, SPELL_HUNGRY);
                                    events.ScheduleEvent(EVENT_HUNGRY, 9000);
                                }
                                else
                                    events.ScheduleEvent(EVENT_HUNGRY, 2000);
                                break;
                            }
                        }
                    }

                    DoMeleeAttackIfReady();
                }
        };
};

class npc_plumb_lava_worm: public CreatureScript // 53520
{
    public:
        npc_plumb_lava_worm() :
                CreatureScript("npc_plumb_lava_worm")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_plumb_lava_wormAI(creature);
        }

        struct npc_plumb_lava_wormAI: public ScriptedAI
        {
                npc_plumb_lava_wormAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                    started = false;
                }

                bool started;
                uint32 timerAur, castTimer;

                void IsSummonedBy(Unit* summoner)
                {
                    me->SetReactState(REACT_PASSIVE);
                    started = true;
                    timerAur = urand(1000, 5000);
                    castTimer = timerAur + 4000;
                }

                void JustDied(Unit* /*killer*/)
                {
                    me->DespawnOrUnsummon(5000);
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!started)
                        return;
                    // TO DO : Change orient.
                    if (castTimer <= diff)
                    {
                        DoCast(me, SPELL_LAVA_SPEW);
                        castTimer = urand(5000, 8000);
                    }
                    else
                        castTimer -= diff;

                    if (timerAur <= diff)
                    {
                        if (me->GetOrientation() >= 6.2f)
                            me->SetFacingTo(0.0f);
                        else
                            me->SetFacingTo(me->GetOrientation() + 0.10f);

                        me->SendMovementFlagUpdate();
                        timerAur = 200;

                    }
                    else
                        timerAur -= diff;

                }
        };
};

class npc_blazing_broodmother: public CreatureScript // 53680
{
    public:
        npc_blazing_broodmother() :
                CreatureScript("npc_blazing_broodmother")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_blazing_broodmotherAI(creature);
        }

        struct npc_blazing_broodmotherAI: public npc_escortAI
        {
                npc_blazing_broodmotherAI(Creature* c) :
                        npc_escortAI(c)
                {
                }

                void IsSummonedBy(Unit* summoner)
                {
                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                    DoCast(me, SPELL_BROODMOTHER_VIS);
                    me->SetReactState(REACT_PASSIVE);
                    //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                    me->SetCanFly(true);
                    SetDespawnAtFar(false);
                    if (me->GetPositionX() > 0)
                        InitLeftBirdWaypoints();
                    else
                        InitRightBirdWaypoints();
                    Start();
                }

                void InitLeftBirdWaypoints()
                {
                    AddWaypoint(1, -32.901f, -272.019f, 105.0f, 1000); //left egg pos z+5
                    AddWaypoint(2, 46.930f, -207.560f, 90.000f); //left bird point to despawn
                }

                void InitRightBirdWaypoints()
                {
                    AddWaypoint(1, -44.463f, -285.802f, 105.0f, 1000); //right egg pos z+5
                    AddWaypoint(2, -28.813f, -378.088f, 90.371f); //right bird point to despawn
                }

                void WaypointReached(uint32 point)
                {
                    switch (point)
                    {
                        case 1:
                            me->SummonCreature_OP(53681, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                            break;
                        case 2:
                            me->DisappearAndDie();
                            break;
                    }
                }

                void UpdateAI(const uint32 diff)
                {
                    npc_escortAI::UpdateAI(diff);
                }
        };
};

class npc_blazing_talon_clawshaper: public CreatureScript // 53734
{
    public:
        npc_blazing_talon_clawshaper() :
                CreatureScript("npc_blazing_talon_clawshaper")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_blazing_talon_clawshaperAI(creature);
        }

        struct npc_blazing_talon_clawshaperAI: public npc_escortAI
        {
                npc_blazing_talon_clawshaperAI(Creature* c) :
                        npc_escortAI(c)
                {
                    me->SetReactState(REACT_DEFENSIVE);
                }

                EventMap events;

                void IsSummonedBy(Unit* summoner)
                {
                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->InterruptNonMeleeSpells(false);

                    me->SetCanFly(true);
                    me->SetSpeed(MOVE_FLIGHT, 1.5f);
                    SetDespawnAtFar(false);
                    if (me->GetPositionX() > -35)
                        InitLeftBirdWaypoints();
                    else
                        InitRightBirdWaypoints();
                    Start();
                }

                void JustDied(Unit* /*killer*/)
                {
                    me->DespawnOrUnsummon(5000);
                }

                void InitLeftBirdWaypoints()
                {
                    AddWaypoint(1, -34.850f, -240.583f, 77.014f, 5000);
                }

                void InitRightBirdWaypoints()
                {
                    AddWaypoint(1, -55.794f, -325.271f, 77.766f, 5000);
                }

                void WaypointReached(uint32 point)
                {
                    switch (point)
                    {
                        case 1:
                            me->SetReactState(REACT_AGGRESSIVE);
                            DoCast(me, SPELL_FIREHAWK_CLAWSHAPPER);
                            me->SetCanFly(false);
                            me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                            me->RemoveUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                            me->GetMotionMaster()->MoveFall();
                            events.ScheduleEvent(EVENT_START_COMBAT, 700);
                            break;
                        case 2:
                            me->DespawnOrUnsummon();
                            break;
                    }
                }

                void UpdateAI(const uint32 diff)
                {
                    npc_escortAI::UpdateAI(diff);

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_START_COMBAT:
                                if (Unit* nearTarget = me->SelectNearestTarget(5000.0f))
                                    me->AI()->AttackStart(nearTarget);

                                events.ScheduleEvent(EVENT_START_IGNITION, 500);
                                events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
                                break;

                            case EVENT_START_IGNITION:
                                if (Creature* alysrazor = me->FindNearestCreature(NPC_ALYSRAZOR, 5000.0f))
                                    if (alysrazor->GetPower(POWER_ENERGY) < 50 && !me->HasUnitState(UNIT_STATE_CASTING))
                                    {
                                        me->StopMoving();
                                        DoCast(alysrazor, SPELL_IGNITION);
                                        Talk(SAY_HELP_ALY);
                                    }

                                events.ScheduleEvent(EVENT_START_IGNITION, 7000);
                                break;

                            case EVENT_CHECK_ENERGY:
                                if (Creature* alysrazor = me->FindNearestCreature(NPC_ALYSRAZOR, 5000.0f))
                                {
                                    if (alysrazor->GetPower(POWER_ENERGY) >= 50)
                                    {
                                        DoCast(me, SPELL_FIREHAWK_REMOVE_FORM);
                                        me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                                        me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                                        me->SetCanFly(true);
                                        me->AttackStop();
                                        me->SetReactState(REACT_PASSIVE);
                                        me->InterruptNonMeleeSpells(false);
                                        AddWaypoint(2, ClawTalon[me->GetPositionX() > -35 ? 0 : 1].GetPositionX(),
                                                ClawTalon[me->GetPositionX() > -35 ? 0 : 1].GetPositionY(),
                                                ClawTalon[me->GetPositionX() > -35 ? 0 : 1].GetPositionZ(), 2000);
                                    }
                                    else
                                        events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
                                }
                                else
                                    me->DespawnOrUnsummon();
                                break;
                        }
                    }
                }
        };
};

class npc_blazing_talon: public CreatureScript // 53896
{
    public:
        npc_blazing_talon() :
                CreatureScript("npc_blazing_talon")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_blazing_talonAI(creature);
        }

        struct npc_blazing_talonAI: public npc_escortAI
        {
                npc_blazing_talonAI(Creature* c) : npc_escortAI(c) { }

                EventMap events;
                uint8 waypoint;

                void IsSummonedBy(Unit* summoner)
                {
                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                    me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->InterruptNonMeleeSpells(false);

                    me->SetCanFly(true);
                    SetDespawnAtFar(false);
                    for (uint8 i = 0; i < 4; ++i)
                    {
                        uint8 tal = 0;

                        if (i == 0)
                            tal = 0;
                        else if (i == 1)
                            tal = 2;
                        else if (i == 2)
                            tal = 4;
                        else if (i == 3)
                            tal = 6;

                        if (Talon[tal].GetPositionX() == me->GetPositionX())
                            waypoint = ++tal;
                    }
                    InitBirdWaypoints();
                    Start();
                }

                void JustDied(Unit* /*killer*/)
                {
                    me->DespawnOrUnsummon(5000);
                }

                void InitBirdWaypoints()
                {
                    AddWaypoint(1, Talon[waypoint].GetPositionX(), Talon[waypoint].GetPositionY(),
                            Talon[waypoint].GetPositionZ(), 3000);
                }

                void WaypointReached(uint32 point)
                {
                    switch (point)
                    {
                        case 1:
                            me->SetReactState(REACT_AGGRESSIVE);
                            DoCast(me, urand(0, 1) == 0 ? SPELL_FIREHAWK_TRANSFORM_M : SPELL_FIREHAWK_TRANSFORM_F);
                            me->GetMotionMaster()->MoveFall();

                            events.ScheduleEvent(EVENT_START_COMBAT, 500);

                            me->SetCanFly(false);
                            me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, 0x02);
                            me->RemoveUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                            break;
                    }
                }

                void UpdateAI(const uint32 diff)
                {
                    npc_escortAI::UpdateAI(diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_START_COMBAT:
                                if (Unit* nearTarget = me->SelectNearestTarget(5000.0f))
                                    me->AI()->AttackStart(nearTarget);
                                events.ScheduleEvent(urand(0, 1) == 0 ? EVENT_START_FIEROBLAST : EVENT_START_BRUSHFIRE, 500);
                                events.ScheduleEvent(EVENT_TALK_DURING_ENCOUNTER, 5000);
                                break;
                            case EVENT_START_FIEROBLAST:
                                DoCast(me, SPELL_FIEROBLAST);
                                events.ScheduleEvent(EVENT_START_BRUSHFIRE, 3000);
                                break;
                            case EVENT_START_BRUSHFIRE:
                                if (Unit* tempTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 500.0f, true))
                                    DoCast(tempTarget, SPELL_BRUSHFIRE);
                                events.ScheduleEvent(urand(0, 1) == 0 ? EVENT_START_FIEROBLAST : EVENT_START_BRUSHFIRE, 3000);
                                break;
                            case EVENT_TALK_DURING_ENCOUNTER:
                                Talk(RAND(SAY_RAND_1,SAY_RAND_2,SAY_RAND_3,SAY_RAND_4));
                                events.ScheduleEvent(EVENT_TALK_DURING_ENCOUNTER, 20000);
                                break;
                        }
                    }
                }
        };
};

class npc_brushfire: public CreatureScript // 53372
{
    public:
        npc_brushfire() : CreatureScript("npc_brushfire") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_brushfireAI(creature);
        }

        struct npc_brushfireAI: public ScriptedAI
        {
                npc_brushfireAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                    started = false;
                    needJump = false;
                    creature->SetDisplayId(11686);
                }

                bool started, needJump;
                uint32 timerMove, jump, timerDespawn;

                void IsSummonedBy(Unit* summoner)
                {
                    me->SetFacingTo(urand(0, 6));
                    DoCast(me, SPELL_BRUSHFIRE_VIS);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    started = true;
                    needJump = true;
                    jump = 500;
                    timerMove = 1000;
                    timerDespawn = 20000;
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!started)
                        return;

                    if (jump <= diff && needJump)
                    {
                        me->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), 60.0f, 200, 8);
                        needJump = false;
                    }
                    else
                        jump -= diff;

                    if (timerMove <= diff) // move forward
                    {
                        me->GetMotionMaster()->MovePoint(0, me->GetPositionX() + cos(me->GetOrientation()) * 35,
                                me->GetPositionY() + sin(me->GetOrientation()) * 35, 58.0f);
                    }
                    else
                        timerMove -= diff;

                    if (timerDespawn <= diff) // move forward
                    {
                        me->DespawnOrUnsummon();
                    }
                    else
                        timerDespawn -= diff;
                }
        };
};

class npc_fiery_tornado: public CreatureScript // 53698
{
    public:
        npc_fiery_tornado() :
                CreatureScript("npc_fiery_tornado")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_fiery_tornadoAI(creature);
        }

        struct npc_fiery_tornadoAI: public npc_escortAI
        {
                npc_fiery_tornadoAI(Creature* c) :
                        npc_escortAI(c)
                {
                    c->SetDisplayId(11686);
                }

                uint32 numb;

                void IsSummonedBy(Unit* summoner)
                {
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                    me->SetCanFly(true);
                    SetDespawnAtFar(false);
                    for (uint8 i = 0; i < 15; ++i)
                    {
                        uint8 tal = 0;

                        if (i == 0)
                            tal = 0;
                        else if (i == 1)
                            tal = 4;
                        else if (i == 2)
                            tal = 20;
                        else if (i == 3)
                            tal = 27;
                        else if (i == 4)
                            tal = 35;
                        else if (i == 5)
                            tal = 41;
                        else if (i == 6)
                            tal = 48;
                        else if (i == 7)
                            tal = 54;
                        else if (i == 8)
                            tal = 62;
                        else if (i == 8)
                            tal = 68;
                        else if (i == 9)
                            tal = 74;
                        else if (i == 10)
                            tal = 80;
                        else if (i == 11)
                            tal = 86;
                        else if (i == 12)
                            tal = 92;
                        else if (i == 13)
                            tal = 98;
                        else if (i == 14)
                            tal = 109;

                        if (Tornado[tal].GetPositionX() == me->GetPositionX())
                        {
                            numb = tal;
                            break;
                        }
                    }
                    InitWaypoints();
                    Start();
                }

                void InitWaypoints()
                {
                    if (numb == 0)
                    {
                        AddWaypoint(1, Tornado[0].GetPositionX(), Tornado[0].GetPositionY(), Tornado[0].GetPositionZ());
                        AddWaypoint(2, Tornado[1].GetPositionX(), Tornado[1].GetPositionY(), Tornado[1].GetPositionZ());
                        AddWaypoint(3, Tornado[2].GetPositionX(), Tornado[2].GetPositionY(), Tornado[2].GetPositionZ());
                        AddWaypoint(4, Tornado[3].GetPositionX(), Tornado[3].GetPositionY(), Tornado[3].GetPositionZ());
                    }
                    else if (numb == 4)
                    {
                        AddWaypoint(1, Tornado[11].GetPositionX(), Tornado[11].GetPositionY(),
                                Tornado[11].GetPositionZ());
                        AddWaypoint(2, Tornado[10].GetPositionX(), Tornado[10].GetPositionY(),
                                Tornado[10].GetPositionZ());
                        AddWaypoint(3, Tornado[9].GetPositionX(), Tornado[9].GetPositionY(), Tornado[9].GetPositionZ());
                        AddWaypoint(4, Tornado[8].GetPositionX(), Tornado[8].GetPositionY(), Tornado[8].GetPositionZ());
                        AddWaypoint(5, Tornado[7].GetPositionX(), Tornado[7].GetPositionY(), Tornado[7].GetPositionZ());
                        AddWaypoint(6, Tornado[6].GetPositionX(), Tornado[6].GetPositionY(), Tornado[6].GetPositionZ());
                        AddWaypoint(7, Tornado[5].GetPositionX(), Tornado[5].GetPositionY(), Tornado[5].GetPositionZ());
                        AddWaypoint(8, Tornado[4].GetPositionX(), Tornado[4].GetPositionY(), Tornado[4].GetPositionZ());
                    }
                    else if (numb == 20)
                    {
                        AddWaypoint(1, Tornado[12].GetPositionX(), Tornado[12].GetPositionY(),
                                Tornado[12].GetPositionZ());
                        AddWaypoint(2, Tornado[13].GetPositionX(), Tornado[13].GetPositionY(),
                                Tornado[13].GetPositionZ());
                        AddWaypoint(3, Tornado[14].GetPositionX(), Tornado[14].GetPositionY(),
                                Tornado[14].GetPositionZ());
                        AddWaypoint(4, Tornado[15].GetPositionX(), Tornado[15].GetPositionY(),
                                Tornado[15].GetPositionZ());
                        AddWaypoint(5, Tornado[16].GetPositionX(), Tornado[16].GetPositionY(),
                                Tornado[16].GetPositionZ());
                        AddWaypoint(6, Tornado[17].GetPositionX(), Tornado[17].GetPositionY(),
                                Tornado[17].GetPositionZ());
                        AddWaypoint(7, Tornado[18].GetPositionX(), Tornado[18].GetPositionY(),
                                Tornado[18].GetPositionZ());
                        AddWaypoint(8, Tornado[19].GetPositionX(), Tornado[19].GetPositionY(),
                                Tornado[19].GetPositionZ());
                        AddWaypoint(9, Tornado[20].GetPositionX(), Tornado[20].GetPositionY(),
                                Tornado[20].GetPositionZ());
                    }
                    else if (numb == 27)
                    {
                        AddWaypoint(1, Tornado[27].GetPositionX(), Tornado[27].GetPositionY(),
                                Tornado[27].GetPositionZ());
                        AddWaypoint(2, Tornado[26].GetPositionX(), Tornado[26].GetPositionY(),
                                Tornado[26].GetPositionZ());
                        AddWaypoint(3, Tornado[25].GetPositionX(), Tornado[25].GetPositionY(),
                                Tornado[25].GetPositionZ());
                        AddWaypoint(4, Tornado[24].GetPositionX(), Tornado[24].GetPositionY(),
                                Tornado[24].GetPositionZ());
                        AddWaypoint(5, Tornado[23].GetPositionX(), Tornado[23].GetPositionY(),
                                Tornado[23].GetPositionZ());
                        AddWaypoint(6, Tornado[22].GetPositionX(), Tornado[22].GetPositionY(),
                                Tornado[22].GetPositionZ());
                        AddWaypoint(7, Tornado[21].GetPositionX(), Tornado[21].GetPositionY(),
                                Tornado[21].GetPositionZ());
                    }
                    else if (numb == 35)
                    {
                        AddWaypoint(1, Tornado[28].GetPositionX(), Tornado[28].GetPositionY(),
                                Tornado[28].GetPositionZ());
                        AddWaypoint(2, Tornado[29].GetPositionX(), Tornado[29].GetPositionY(),
                                Tornado[29].GetPositionZ());
                        AddWaypoint(3, Tornado[30].GetPositionX(), Tornado[30].GetPositionY(),
                                Tornado[30].GetPositionZ());
                        AddWaypoint(4, Tornado[31].GetPositionX(), Tornado[31].GetPositionY(),
                                Tornado[31].GetPositionZ());
                        AddWaypoint(5, Tornado[32].GetPositionX(), Tornado[32].GetPositionY(),
                                Tornado[32].GetPositionZ());
                        AddWaypoint(6, Tornado[33].GetPositionX(), Tornado[33].GetPositionY(),
                                Tornado[33].GetPositionZ());
                        AddWaypoint(7, Tornado[34].GetPositionX(), Tornado[34].GetPositionY(),
                                Tornado[34].GetPositionZ());
                        AddWaypoint(8, Tornado[35].GetPositionX(), Tornado[35].GetPositionY(),
                                Tornado[35].GetPositionZ());
                    }
                    else if (numb == 41)
                    {
                        AddWaypoint(1, Tornado[41].GetPositionX(), Tornado[41].GetPositionY(),
                                Tornado[41].GetPositionZ());
                        AddWaypoint(2, Tornado[40].GetPositionX(), Tornado[40].GetPositionY(),
                                Tornado[40].GetPositionZ());
                        AddWaypoint(3, Tornado[39].GetPositionX(), Tornado[39].GetPositionY(),
                                Tornado[39].GetPositionZ());
                        AddWaypoint(4, Tornado[38].GetPositionX(), Tornado[38].GetPositionY(),
                                Tornado[38].GetPositionZ());
                        AddWaypoint(5, Tornado[37].GetPositionX(), Tornado[37].GetPositionY(),
                                Tornado[37].GetPositionZ());
                        AddWaypoint(6, Tornado[36].GetPositionX(), Tornado[36].GetPositionY(),
                                Tornado[36].GetPositionZ());
                    }
                    else if (numb == 48)
                    {
                        AddWaypoint(1, Tornado[42].GetPositionX(), Tornado[42].GetPositionY(),
                                Tornado[42].GetPositionZ());
                        AddWaypoint(2, Tornado[43].GetPositionX(), Tornado[43].GetPositionY(),
                                Tornado[43].GetPositionZ());
                        AddWaypoint(3, Tornado[44].GetPositionX(), Tornado[44].GetPositionY(),
                                Tornado[44].GetPositionZ());
                        AddWaypoint(4, Tornado[45].GetPositionX(), Tornado[45].GetPositionY(),
                                Tornado[45].GetPositionZ());
                        AddWaypoint(5, Tornado[46].GetPositionX(), Tornado[46].GetPositionY(),
                                Tornado[46].GetPositionZ());
                        AddWaypoint(6, Tornado[47].GetPositionX(), Tornado[47].GetPositionY(),
                                Tornado[47].GetPositionZ());
                        AddWaypoint(7, Tornado[48].GetPositionX(), Tornado[48].GetPositionY(),
                                Tornado[48].GetPositionZ());
                    }
                    else if (numb == 54)
                    {
                        AddWaypoint(1, Tornado[54].GetPositionX(), Tornado[54].GetPositionY(),
                                Tornado[54].GetPositionZ());
                        AddWaypoint(2, Tornado[53].GetPositionX(), Tornado[53].GetPositionY(),
                                Tornado[53].GetPositionZ());
                        AddWaypoint(3, Tornado[52].GetPositionX(), Tornado[52].GetPositionY(),
                                Tornado[52].GetPositionZ());
                        AddWaypoint(4, Tornado[51].GetPositionX(), Tornado[51].GetPositionY(),
                                Tornado[51].GetPositionZ());
                        AddWaypoint(5, Tornado[50].GetPositionX(), Tornado[50].GetPositionY(),
                                Tornado[50].GetPositionZ());
                        AddWaypoint(6, Tornado[49].GetPositionX(), Tornado[49].GetPositionY(),
                                Tornado[49].GetPositionZ());
                    }
                    else if (numb == 62)
                    {
                        AddWaypoint(1, Tornado[55].GetPositionX(), Tornado[55].GetPositionY(),
                                Tornado[55].GetPositionZ());
                        AddWaypoint(2, Tornado[56].GetPositionX(), Tornado[56].GetPositionY(),
                                Tornado[56].GetPositionZ());
                        AddWaypoint(3, Tornado[57].GetPositionX(), Tornado[57].GetPositionY(),
                                Tornado[57].GetPositionZ());
                        AddWaypoint(4, Tornado[58].GetPositionX(), Tornado[58].GetPositionY(),
                                Tornado[58].GetPositionZ());
                        AddWaypoint(5, Tornado[59].GetPositionX(), Tornado[59].GetPositionY(),
                                Tornado[59].GetPositionZ());
                        AddWaypoint(6, Tornado[60].GetPositionX(), Tornado[60].GetPositionY(),
                                Tornado[60].GetPositionZ());
                        AddWaypoint(7, Tornado[61].GetPositionX(), Tornado[61].GetPositionY(),
                                Tornado[61].GetPositionZ());
                        AddWaypoint(8, Tornado[62].GetPositionX(), Tornado[62].GetPositionY(),
                                Tornado[62].GetPositionZ());
                    }
                    else if (numb == 68)
                    {
                        AddWaypoint(1, Tornado[68].GetPositionX(), Tornado[68].GetPositionY(),
                                Tornado[68].GetPositionZ());
                        AddWaypoint(2, Tornado[67].GetPositionX(), Tornado[67].GetPositionY(),
                                Tornado[67].GetPositionZ());
                        AddWaypoint(3, Tornado[66].GetPositionX(), Tornado[66].GetPositionY(),
                                Tornado[66].GetPositionZ());
                        AddWaypoint(4, Tornado[65].GetPositionX(), Tornado[65].GetPositionY(),
                                Tornado[65].GetPositionZ());
                        AddWaypoint(5, Tornado[64].GetPositionX(), Tornado[64].GetPositionY(),
                                Tornado[64].GetPositionZ());
                        AddWaypoint(6, Tornado[63].GetPositionX(), Tornado[63].GetPositionY(),
                                Tornado[63].GetPositionZ());
                    }
                    else if (numb == 74)
                    {
                        AddWaypoint(1, Tornado[69].GetPositionX(), Tornado[69].GetPositionY(),
                                Tornado[69].GetPositionZ());
                        AddWaypoint(2, Tornado[70].GetPositionX(), Tornado[70].GetPositionY(),
                                Tornado[70].GetPositionZ());
                        AddWaypoint(3, Tornado[71].GetPositionX(), Tornado[71].GetPositionY(),
                                Tornado[71].GetPositionZ());
                        AddWaypoint(4, Tornado[72].GetPositionX(), Tornado[72].GetPositionY(),
                                Tornado[72].GetPositionZ());
                        AddWaypoint(5, Tornado[73].GetPositionX(), Tornado[73].GetPositionY(),
                                Tornado[73].GetPositionZ());
                        AddWaypoint(6, Tornado[74].GetPositionX(), Tornado[74].GetPositionY(),
                                Tornado[74].GetPositionZ());
                    }
                    else if (numb == 80)
                    {
                        AddWaypoint(1, Tornado[80].GetPositionX(), Tornado[80].GetPositionY(),
                                Tornado[80].GetPositionZ());
                        AddWaypoint(2, Tornado[79].GetPositionX(), Tornado[79].GetPositionY(),
                                Tornado[79].GetPositionZ());
                        AddWaypoint(3, Tornado[78].GetPositionX(), Tornado[78].GetPositionY(),
                                Tornado[78].GetPositionZ());
                        AddWaypoint(4, Tornado[77].GetPositionX(), Tornado[77].GetPositionY(),
                                Tornado[77].GetPositionZ());
                        AddWaypoint(5, Tornado[76].GetPositionX(), Tornado[76].GetPositionY(),
                                Tornado[76].GetPositionZ());
                        AddWaypoint(6, Tornado[75].GetPositionX(), Tornado[75].GetPositionY(),
                                Tornado[75].GetPositionZ());
                    }
                    else if (numb == 86)
                    {
                        AddWaypoint(1, Tornado[81].GetPositionX(), Tornado[81].GetPositionY(),
                                Tornado[81].GetPositionZ());
                        AddWaypoint(2, Tornado[82].GetPositionX(), Tornado[82].GetPositionY(),
                                Tornado[82].GetPositionZ());
                        AddWaypoint(3, Tornado[83].GetPositionX(), Tornado[83].GetPositionY(),
                                Tornado[83].GetPositionZ());
                        AddWaypoint(4, Tornado[84].GetPositionX(), Tornado[84].GetPositionY(),
                                Tornado[84].GetPositionZ());
                        AddWaypoint(5, Tornado[85].GetPositionX(), Tornado[85].GetPositionY(),
                                Tornado[85].GetPositionZ());
                        AddWaypoint(6, Tornado[86].GetPositionX(), Tornado[86].GetPositionY(),
                                Tornado[86].GetPositionZ());
                    }
                    else if (numb == 92)
                    {
                        AddWaypoint(1, Tornado[92].GetPositionX(), Tornado[92].GetPositionY(),
                                Tornado[92].GetPositionZ());
                        AddWaypoint(2, Tornado[91].GetPositionX(), Tornado[91].GetPositionY(),
                                Tornado[91].GetPositionZ());
                        AddWaypoint(3, Tornado[90].GetPositionX(), Tornado[90].GetPositionY(),
                                Tornado[90].GetPositionZ());
                        AddWaypoint(4, Tornado[89].GetPositionX(), Tornado[89].GetPositionY(),
                                Tornado[89].GetPositionZ());
                        AddWaypoint(5, Tornado[88].GetPositionX(), Tornado[88].GetPositionY(),
                                Tornado[88].GetPositionZ());
                        AddWaypoint(6, Tornado[87].GetPositionX(), Tornado[87].GetPositionY(),
                                Tornado[87].GetPositionZ());
                    }
                    else if (numb == 98)
                    {
                        AddWaypoint(1, Tornado[93].GetPositionX(), Tornado[93].GetPositionY(),
                                Tornado[93].GetPositionZ());
                        AddWaypoint(2, Tornado[94].GetPositionX(), Tornado[94].GetPositionY(),
                                Tornado[94].GetPositionZ());
                        AddWaypoint(3, Tornado[95].GetPositionX(), Tornado[95].GetPositionY(),
                                Tornado[95].GetPositionZ());
                        AddWaypoint(4, Tornado[96].GetPositionX(), Tornado[96].GetPositionY(),
                                Tornado[96].GetPositionZ());
                        AddWaypoint(5, Tornado[97].GetPositionX(), Tornado[97].GetPositionY(),
                                Tornado[97].GetPositionZ());
                        AddWaypoint(6, Tornado[98].GetPositionX(), Tornado[98].GetPositionY(),
                                Tornado[98].GetPositionZ());
                    }
                    else if (numb == 104)
                    {
                        AddWaypoint(1, Tornado[104].GetPositionX(), Tornado[104].GetPositionY(),
                                Tornado[104].GetPositionZ());
                        AddWaypoint(2, Tornado[103].GetPositionX(), Tornado[103].GetPositionY(),
                                Tornado[103].GetPositionZ());
                        AddWaypoint(3, Tornado[102].GetPositionX(), Tornado[102].GetPositionY(),
                                Tornado[102].GetPositionZ());
                        AddWaypoint(4, Tornado[101].GetPositionX(), Tornado[101].GetPositionY(),
                                Tornado[101].GetPositionZ());
                        AddWaypoint(5, Tornado[100].GetPositionX(), Tornado[100].GetPositionY(),
                                Tornado[100].GetPositionZ());
                        AddWaypoint(6, Tornado[99].GetPositionX(), Tornado[99].GetPositionY(),
                                Tornado[99].GetPositionZ());
                    }
                    else if (numb == 109)
                    {
                        AddWaypoint(1, Tornado[105].GetPositionX(), Tornado[105].GetPositionY(),
                                Tornado[105].GetPositionZ());
                        AddWaypoint(2, Tornado[106].GetPositionX(), Tornado[106].GetPositionY(),
                                Tornado[106].GetPositionZ());
                        AddWaypoint(3, Tornado[107].GetPositionX(), Tornado[107].GetPositionY(),
                                Tornado[107].GetPositionZ());
                        AddWaypoint(4, Tornado[108].GetPositionX(), Tornado[108].GetPositionY(),
                                Tornado[108].GetPositionZ());
                        AddWaypoint(5, Tornado[109].GetPositionX(), Tornado[109].GetPositionY(),
                                Tornado[109].GetPositionZ());
                    }
                }

                void WaypointReached(uint32 point)
                {
                    if ((point == 4 && numb == 0) || (point == 6))
                        InitWaypoints();
                }

                void UpdateAI(const uint32 diff)
                {
                    npc_escortAI::UpdateAI(diff);
                }
        };
};

class npc_molten_egg: public CreatureScript // 53681
{
    public:
        npc_molten_egg() :
                CreatureScript("npc_molten_egg")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_molten_eggAI(creature);
        }

        struct npc_molten_eggAI: public ScriptedAI
        {
                npc_molten_eggAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                    started = false;
                }

                EventMap events;
                bool started;

                void IsSummonedBy(Unit* summoner)
                {
                    me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), 56.00f, me->GetOrientation());
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    events.ScheduleEvent(EVENT_EGG_EXPLOSION, 3500);
                    started = true;
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!started)
                        return;

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_EGG_EXPLOSION:
                                DoCast(me, SPELL_EGG_EXPLOSION);
                                events.ScheduleEvent(EVENT_SUMMON_HATCHING, 5000);
                                break;

                            case EVENT_SUMMON_HATCHING:
                                DoCast(me, SPELL_SUMM_HATHING);
                                events.ScheduleEvent(EVENT_DESPAWN, 600);
                                break;

                            case EVENT_DESPAWN:
                                me->DespawnOrUnsummon();
                                break;
                        }
                    }
                }
        };
};

class boss_alysrazor: public CreatureScript
{
    public:
        boss_alysrazor() :
                CreatureScript("boss_alysrazor")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_alysrazorAI(creature);
        }

        struct boss_alysrazorAI: public BossAI
        {
                boss_alysrazorAI(Creature* creature) : BossAI(creature, DATA_ALYSRAZAR)
                {
                    instance = creature->GetInstanceScript();

                    //ASSERT(creature->GetVehicleKit()); // Power.
                    me->SetMaxPower(POWER_ENERGY, 100);
                    me->SetPower(POWER_ENERGY, 100);
                    phase = PHASE_NONE;
                }

                InstanceScript* instance;
                EventMap events;
                uint8 waypoint, phase, LastTalon;
                bool isNeedJump;

                void Reset()
                {
                    if (instance)
                        instance->SetBossState(DATA_ALYSRAZAR, NOT_STARTED);

                    events.Reset();
                    isNeedJump = false;

                    me->SetReactState(REACT_AGGRESSIVE);

                    _Reset();
                }

                void EnterEvadeMode()
                {
                    Reset();

                    if (instance)
                    {
                        instance->SetBossState(DATA_ALYSRAZAR, FAIL);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                    }

                    DespawnMinions();
                    RemoveEncounterAuras();

                    me->DespawnOrUnsummon();

                    me->SummonCreature_OP(NPC_MOLTEN_FEATHER, Feather[0]);

                    _EnterEvadeMode();
                }

                inline void DespawnMinions()
                {
                    DespawnCreatures(NPC_VOLCANO_FIRE_BUNNY);
                    DespawnCreatures(NPC_MOLTEN_EGG);
                    DespawnCreatures(NPC_BLAZING_BROODMOTHER);
                    DespawnCreatures(NPC_VORACIOUS_HATCHLING);
                    DespawnCreatures(NPC_FIERY_VORTEX);
                    DespawnCreatures(NPC_FIERY_TORNADO);
                }

                void DespawnCreatures(uint32 entry)
                {
                    std::list<Creature*> creatures;
                    GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                    if (creatures.empty())
                        return;

                    for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                        (*iter)->DespawnOrUnsummon();
                }

                void EnterCombat(Unit* /*who*/)
                {
                    EnterAir();
                    Talk(SAY_ALY_START);

                    if (instance)
                    {
                        instance->SetBossState(DATA_ALYSRAZAR, IN_PROGRESS);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
                    }

                    DoCast(me, SPELL_INDICATOR);

                    _EnterCombat();
                }

                void KilledUnit(Unit* /*victim*/)
                {
                    Talk(RAND(SAY_ALY_KILLER_1, SAY_ALY_KILLER_2));
                }

                void EnterGround()
                {
                    me->RemoveUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                    me->SetDisableGravity(false);
                    me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                    me->SetHover(false);
                }

                void EnterAir()
                {
                    me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
                    me->SetDisableGravity(true);
                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                    me->SetHover(true);
                }

                void IsSummonedBy(Unit* summoner)
                {

                if (GameObject* volcano = instance->instance->GetGameObject(instance->GetData64(DATA_ALYSRAZOR_VOLCANO)))
                {
                    volcano->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                    volcano->setActive(true);
                }

                    phase = PHASE_JUMP;
                    isNeedJump = true;
                    me->SetReactState(REACT_PASSIVE);
                    DoZoneInCombat();
                    events.ScheduleEvent(EVENT_ZONE_COMBAT, 1000);
                }

                void CancelMove()
                {
                    events.CancelEvent(EVENT_MOVE_TO_START_OF_TOP);
                    events.CancelEvent(EVENT_MOVE_TO_END_OF_TOP);
                    events.CancelEvent(EVENT_MOVE_TO_LEFT_1);
                    events.CancelEvent(EVENT_MOVE_TO_LEFT_2);
                    events.CancelEvent(EVENT_MOVE_TO_LEFT_3);
                    events.CancelEvent(EVENT_MOVE_TO_LEFT_4);
                    events.CancelEvent(EVENT_MOVE_TO_LEFT_5);
                    events.CancelEvent(EVENT_MOVE_TO_RIGHT_1);
                    events.CancelEvent(EVENT_MOVE_TO_RIGHT_2);
                    events.CancelEvent(EVENT_MOVE_TO_RIGHT_3);
                    events.CancelEvent(EVENT_MOVE_TO_RIGHT_4);
                    events.CancelEvent(EVENT_MOVE_TO_RIGHT_5);
                    events.CancelEvent(EVENT_MOVE_TO_END_CENTER);
                    events.CancelEvent(EVENT_MOVE_TO_END_START);
                    events.CancelEvent(EVENT_MOVE_TO_LEFT_N_1);
                    events.CancelEvent(EVENT_MOVE_TO_LEFT_N_2);
                    events.CancelEvent(EVENT_MOVE_TO_LEFT_N_3);
                    events.CancelEvent(EVENT_MOVE_TO_LEFT_N_4);
                    events.CancelEvent(EVENT_MOVE_TO_LEFT_N_5);
                    events.CancelEvent(EVENT_MOVE_TO_RIGHT_N_1);
                    events.CancelEvent(EVENT_MOVE_TO_RIGHT_N_2);
                    events.CancelEvent(EVENT_MOVE_TO_RIGHT_N_3);
                    events.CancelEvent(EVENT_MOVE_TO_RIGHT_N_4);
                    events.CancelEvent(EVENT_MOVE_TO_RIGHT_N_5);
                    events.CancelEvent(EVENT_MOVE_TORNADOS_1);
                    events.CancelEvent(EVENT_MOVE_TORNADOS_2);
                    events.CancelEvent(EVENT_MOVE_TORNADOS_3);
                    events.CancelEvent(EVENT_MOVE_TORNADOS_4);
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    if (phase == PHASE_GROUND && me->GetPower(POWER_ENERGY) >= 50 && !me->HasAura(SPELL_IGNITED))
                    {
                        if (me->HasAura(SPELL_BURNOUT))
                            me->RemoveAura(SPELL_BURNOUT);
                        if (me->HasAura(SPELL_SPARK))
                            me->RemoveAura(SPELL_SPARK);
                        DoCast(me, SPELL_IGNITED);
                        DoCast(me, SPELL_BLAZING_CLAW);
                        Talk(SAY_ALY_REBORN);
                        RemoveAllFeathers();
                        EnterAir();
                        me->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 10, 200, 2);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->AI()->AttackStart(me->SelectVictim());
                    }

                    if (phase == PHASE_GROUND && me->GetPower(POWER_ENERGY) >= 100 && me->HasAura(SPELL_IGNITED))
                    {
                        phase = PHASE_JUMP;
                        LastTalon = 4;
                        me->RemoveAura(SPELL_IGNITED);
                        if (me->HasAura(SPELL_BLAZING_CLAW))
                            me->RemoveAura(SPELL_BLAZING_CLAW);
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->InterruptNonMeleeSpells(false);
                        DoCast(me, SPELL_FULL_POWER);
                        events.ScheduleEvent(EVENT_PHASE_2_TORNADOS_START, 195000);
                        events.ScheduleEvent(EVENT_MOVE_TO_LEFT_1, 1000);
                        events.ScheduleEvent(EVENT_SUMMON_BROODMOTHER, 25000);
                        events.ScheduleEvent(EVENT_SUMMON_WORMS, 50000);
                        for (uint8 i = 0; i < 2; ++i)
                            events.ScheduleEvent(EVENT_SUMMON_TALON, i == 0 ? urand(5000, 10000) : urand(8000, 13000));
                    }

                    if (phase == PHASE_JUMP && isNeedJump)
                    {
                        isNeedJump = false;
                        me->GetMotionMaster()->MoveJump(SpawnPos[1].GetPositionX(), SpawnPos[1].GetPositionY(),
                                SpawnPos[1].GetPositionZ(), 250, 10);
                        EnterAir();
                        events.ScheduleEvent(EVENT_START_ENCOUNTER, 1000);
                    }

                    if (phase == PHASE_AIR || phase == PHASE_TORNADO)
                        me->GetMotionMaster()->MovePoint(0, SpawnPos[waypoint].GetPositionX(),
                                SpawnPos[waypoint].GetPositionY(), SpawnPos[waypoint].GetPositionZ());

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_START_ENCOUNTER:
                                for (uint8 i = 0; i < 11; ++i)
                                    me->SummonCreature_OP(53158, SpawnVolcanos[i].GetPositionX(),
                                            SpawnVolcanos[i].GetPositionY(), SpawnVolcanos[i].GetPositionZ());
                                DoCast(me, SPELL_FIRESTORM);
                                events.ScheduleEvent(EVENT_PHASE_2_TORNADOS_START, 195000); // 5000 perfect for testings
                                events.ScheduleEvent(EVENT_MOVE_TO_START_OF_TOP, 500);
                                events.ScheduleEvent(EVENT_INCENDIARY_CLOUD, 15000);
                                events.ScheduleEvent(EVENT_SUMMON_BROODMOTHER, 25000);
                                events.ScheduleEvent(EVENT_SUMMON_WORMS, 50000);
                                for (uint8 i = 0; i < 2; ++i)
                                    events.ScheduleEvent(EVENT_SUMMON_TALON,
                                            i == 0 ? urand(5000, 10000) : urand(8000, 13000));
                                LastTalon = 4;
                                break;

                            case EVENT_ZONE_COMBAT:
                                SetPlayersInCombat();
                                events.ScheduleEvent(EVENT_ZONE_COMBAT, 1000);
                                break;

                            case EVENT_INCENDIARY_CLOUD:
                                if (phase == PHASE_AIR)
                                {
                                    me->SummonCreature_OP(53541, me->GetPositionX() - urand(5, 15),
                                            me->GetPositionY() - urand(-5, -15),
                                            me->GetPositionZ() > 120.0f ? me->GetPositionZ() : 120.0f);
                                    me->SummonCreature_OP(53554, me->GetPositionX() + urand(25, 35),
                                            me->GetPositionY() + urand(-25, -35),
                                            me->GetPositionZ() > 120.0f ? me->GetPositionZ() : 120.0f,
                                            me->GetOrientation());
                                }
                                events.ScheduleEvent(EVENT_INCENDIARY_CLOUD, 5000);
                                break;

                            case EVENT_MOVE_TO_START_OF_TOP:
                                waypoint = 2;
                                phase = PHASE_AIR;
                                events.ScheduleEvent(EVENT_MOVE_TO_END_OF_TOP, 9000);
                                break;

                            case EVENT_SUMMON_WORMS:
                                for (uint8 i = 0; i < 4; ++i)
                                    me->SummonCreature_OP(53520, WormsPos[i]);
                                events.ScheduleEvent(EVENT_SUMMON_WORMS, 60000);
                                break;

                            case EVENT_SUMMON_TALON:
                                me->SummonCreature_OP(53896, Talon[SelectTalon()]);
                                events.ScheduleEvent(EVENT_SUMMON_TALON, urand(40000, 45000));
                                break;

                            case EVENT_SUMMON_BROODMOTHER:
                                for (uint8 i = 0; i < 2; ++i)
                                    me->SummonCreature_OP(53680, BirdsPos[i]);
                                break;

                            case EVENT_MOVE_TO_END_OF_TOP:
                                DoCast(me, SPELL_BLAZING_CLAW);
                                DoCast(me, SPELL_MOLTING);
                                waypoint = 3;
                                events.ScheduleEvent(EVENT_MOVE_TO_LEFT_1, 12000);
                                break;

                            case EVENT_MOVE_TO_LEFT_1:
                                if (me->HasAura(SPELL_BLAZING_CLAW))
                                    me->RemoveAura(SPELL_BLAZING_CLAW);
                                phase = PHASE_AIR;
                                waypoint = 4;
                                events.ScheduleEvent(EVENT_MOVE_TO_LEFT_2, 5200);
                                break;

                            case EVENT_MOVE_TO_LEFT_2:
                                waypoint = 5;
                                events.ScheduleEvent(EVENT_MOVE_TO_LEFT_3, 5200);
                                break;

                            case EVENT_MOVE_TO_LEFT_3:
                                waypoint = 6;
                                events.ScheduleEvent(EVENT_MOVE_TO_LEFT_4, 5200);
                                break;

                            case EVENT_MOVE_TO_LEFT_4:
                                waypoint = 7;
                                events.ScheduleEvent(EVENT_MOVE_TO_LEFT_5, 5200);
                                break;

                            case EVENT_MOVE_TO_LEFT_5:
                                waypoint = 8;
                                events.ScheduleEvent(EVENT_MOVE_TO_RIGHT_1, 5200);
                                break;

                            case EVENT_MOVE_TO_RIGHT_1:
                                waypoint = 9;
                                events.ScheduleEvent(EVENT_MOVE_TO_RIGHT_2, 5200);
                                break;

                            case EVENT_MOVE_TO_RIGHT_2:
                                waypoint = 10;
                                events.ScheduleEvent(EVENT_MOVE_TO_RIGHT_3, 5200);
                                break;

                            case EVENT_MOVE_TO_RIGHT_3:
                                waypoint = 11;
                                events.ScheduleEvent(EVENT_MOVE_TO_RIGHT_4, 5000);
                                break;

                            case EVENT_MOVE_TO_RIGHT_4:
                                waypoint = 12;
                                events.ScheduleEvent(EVENT_MOVE_TO_RIGHT_5, 5000);
                                break;

                            case EVENT_MOVE_TO_RIGHT_5:
                                waypoint = 13;
                                events.ScheduleEvent(EVENT_MOVE_TO_END_CENTER, 5000);
                                break;

                            case EVENT_MOVE_TO_END_CENTER:
                                waypoint = 14;
                                events.ScheduleEvent(EVENT_MOVE_TO_END_START, 10000);
                                break;

                            case EVENT_MOVE_TO_END_START:
                                DoCast(me, SPELL_BLAZING_CLAW);
                                DoCast(me, SPELL_MOLTING);
                                waypoint = 15;
                                events.ScheduleEvent(EVENT_MOVE_TO_LEFT_N_1, 15000);
                                break;

                            case EVENT_MOVE_TO_LEFT_N_1:
                                if (me->HasAura(SPELL_BLAZING_CLAW))
                                    me->RemoveAura(SPELL_BLAZING_CLAW);
                                waypoint = 16;
                                events.ScheduleEvent(EVENT_MOVE_TO_LEFT_N_2, 5000);
                                break;

                            case EVENT_MOVE_TO_LEFT_N_2:
                                waypoint = 17;
                                events.ScheduleEvent(EVENT_MOVE_TO_LEFT_N_3, 5000);
                                break;
                            case EVENT_MOVE_TO_LEFT_N_3:
                                waypoint = 18;
                                events.ScheduleEvent(EVENT_MOVE_TO_LEFT_N_4, 5000);
                                break;

                            case EVENT_MOVE_TO_LEFT_N_4:
                                waypoint = 19;
                                events.ScheduleEvent(EVENT_MOVE_TO_LEFT_N_5, 5000);
                                break;

                            case EVENT_MOVE_TO_LEFT_N_5:
                                waypoint = 20;
                                events.ScheduleEvent(EVENT_MOVE_TO_RIGHT_N_1, 5000);
                                break;

                            case EVENT_MOVE_TO_RIGHT_N_1:
                                waypoint = 21;
                                events.ScheduleEvent(EVENT_MOVE_TO_RIGHT_N_2, 5200);
                                break;

                            case EVENT_MOVE_TO_RIGHT_N_2:
                                waypoint = 22;
                                events.ScheduleEvent(EVENT_MOVE_TO_RIGHT_N_3, 5200);
                                break;

                            case EVENT_MOVE_TO_RIGHT_N_3:
                                waypoint = 23;
                                events.ScheduleEvent(EVENT_MOVE_TO_RIGHT_N_4, 5200);
                                break;

                            case EVENT_MOVE_TO_RIGHT_N_4:
                                waypoint = 24;
                                events.ScheduleEvent(EVENT_MOVE_TO_RIGHT_N_5, 5200);
                                break;

                            case EVENT_MOVE_TO_RIGHT_N_5:
                                waypoint = 25;
                                events.ScheduleEvent(EVENT_MOVE_TO_START_OF_TOP, 500);
                                break;

                            case EVENT_PHASE_2_TORNADOS_START:
                                events.CancelEvent(EVENT_SUMMON_WORMS);
                                events.CancelEvent(EVENT_SUMMON_TALON);
                                if (me->HasAura(SPELL_BLAZING_CLAW))
                                    me->RemoveAura(SPELL_BLAZING_CLAW);
                                me->SummonCreature_OP(53693, FallPos[0].GetPositionX(), FallPos[0].GetPositionY(), FallPos[0].GetPositionZ());
                                Talk(RAND(SAY_ALY_TORNADO_1, SAY_ALY_TORNADO_2));
                                waypoint = 26;
                                phase = PHASE_TORNADO;
                                CancelMove();
                                events.ScheduleEvent(EVENT_MOVE_TORNADOS_1, 5000);
                                events.ScheduleEvent(EVENT_MOVE_TO_TORNADO, 18000);
                                events.ScheduleEvent(EVENT_PHASE_2_TORNADOS_ENDS, 22000);
                                break;

                            case EVENT_HARSH_WINDS:
                                CastHarshOnPlayers();
                                events.ScheduleEvent(EVENT_HARSH_WINDS, 2000);
                                break;

                            case EVENT_MOVE_TORNADOS_1:
                                DespawnCreatures(NPC_MOLTEN_FEATHER);
                                RemoveFly();
                                waypoint = 27;
                                events.ScheduleEvent(EVENT_HARSH_WINDS, 2000);
                                events.ScheduleEvent(EVENT_MOVE_TORNADOS_2, 4000);
                                break;

                            case EVENT_MOVE_TORNADOS_2:
                                waypoint = 28;
                                events.ScheduleEvent(EVENT_MOVE_TORNADOS_3, 4000);
                                break;

                            case EVENT_MOVE_TORNADOS_3:
                                waypoint = 29;
                                events.ScheduleEvent(EVENT_MOVE_TORNADOS_4, 4000);
                                break;

                            case EVENT_MOVE_TORNADOS_4:
                                waypoint = 30;
                                events.ScheduleEvent(EVENT_MOVE_TORNADOS_1, 4000);
                                break;

                            case EVENT_SUMMON_DRUIDS:
                                for (uint8 i = 0; i < 2; ++i)
                                    me->SummonCreature_OP(53734, ClawTalon[i]);
                                break;

                            case EVENT_PHASE_2_TORNADOS_ENDS:
                                events.CancelEvent(EVENT_HARSH_WINDS);
                                CancelMove();
                                DespawnCreatures(53693);
                                DespawnCreatures(53698);
                                phase = PHASE_GROUND;
                                DoCast(me, SPELL_BURNOUT);
                                DoCast(me, SPELL_SPARK);
                                me->SetPower(POWER_ENERGY, 0);
                                DoCast(me, SPELL_ZERO_POWER);
                                Talk(SAY_ALY_BURNOUT);
                                me->GetMotionMaster()->MoveJump(FallPos[0].GetPositionX(), FallPos[0].GetPositionY(),
                                        FallPos[0].GetPositionZ(), 100, 4);
                                events.ScheduleEvent(EVENT_SUMMON_DRUIDS, 500);
                                break;

                            default:
                                break;
                        }
                    }

                    DoMeleeAttackIfReady();
                }

                int32 SelectTalon()
                {
                    uint8 talon = urand(0, 3);

                    if (LastTalon != 4)
                        while (LastTalon == talon)
                            talon = urand(0, 3);

                    LastTalon = talon;

                    if (talon == 0)
                        return 0;
                    else if (talon == 1)
                        return 2;
                    else if (talon == 2)
                        return 4;
                    else if (talon == 3)
                        return 6;
                    else
                        return 6;
                }

                void CastHarshOnPlayers()
                {
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    if (!PlayerList.isEmpty())
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (Creature* tornado = me->FindNearestCreature(53693, 5000.0f))
                                if (i->getSource()->GetDistance(tornado) > 60.0f)
                                    me->AddAura(SPELL_HARSH_WINDS, i->getSource());
                }

                void SetPlayersInCombat()
                {
                    uint8 players = 0;
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    if (!PlayerList.isEmpty())
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (Player *player = i->getSource())
                                if (player->isAlive())
                                {
                                    ++players;
                                    player->SetInCombatWith(me->ToUnit());
                                }
                    if (players == 0)
                        EnterEvadeMode();
                }

                void RemoveFly()
                {
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    if (!PlayerList.isEmpty())
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (i->getSource()->HasAura(SPELL_FLY))
                                i->getSource()->RemoveAura(SPELL_FLY);
                }

                void RemoveAllFeathers()
                {
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    if (!PlayerList.isEmpty())
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (i->getSource()->HasAura(SPELL_CAST_ON_MOVE_VISUAL))
                                i->getSource()->RemoveAura(SPELL_CAST_ON_MOVE_VISUAL);
                }

                void RemoveEncounterAuras()
                {
                    Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                    if (!PlayerList.isEmpty())
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            if (i->getSource()->HasAura(SPELL_FLY))
                                i->getSource()->RemoveAura(SPELL_FLY);
                            if (i->getSource()->HasAura(SPELL_INDICATOR))
                                i->getSource()->RemoveAura(SPELL_INDICATOR);
                            if (i->getSource()->HasAura(SPELL_CAST_ON_MOVE_VISUAL))
                                i->getSource()->RemoveAura(SPELL_CAST_ON_MOVE_VISUAL);
                            if (i->getSource()->HasAura(SPELL_IMPRINTED))
                                i->getSource()->RemoveAura(SPELL_IMPRINTED);
                        }
                }

                void JustDied(Unit* /*killer*/)
                {
                    me->RemoveAllAuras();
                    RemoveEncounterAuras();
                    Talk(SAY_ALY_DEATH);
                    if (instance)
                    {
                        instance->SetBossState(DATA_ALYSRAZAR, DONE);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                    }

                    _JustDied();
                }
        };
};

class npc_fier_tornado: public CreatureScript // 53158
{
    public:
        npc_fier_tornado() :
                CreatureScript("npc_fier_tornado")
        {
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_fier_tornadoAI(creature);
        }

        struct npc_fier_tornadoAI: public ScriptedAI
        {
                npc_fier_tornadoAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                    creature->SetDisplayId(11686);
                    started = false;
                    needSummon = false;
                }

                bool started, needSummon;
                uint32 timerSummon;

                void IsSummonedBy(Unit* summoner)
                {
                    started = true;
                    DoCast(me, SPELL_SUMMON_DMG);
                    timerSummon = 5000;
                    needSummon = true;
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!started)
                        return;

                    if (timerSummon <= diff && needSummon)
                    {
                        for (uint8 i = 0; i < 15; ++i)
                        {
                            uint8 tal = 0;

                            if (i == 0)
                                tal = 0;
                            else if (i == 1)
                                tal = 4;
                            else if (i == 2)
                                tal = 20;
                            else if (i == 3)
                                tal = 27;
                            else if (i == 4)
                                tal = 35;
                            else if (i == 5)
                                tal = 41;
                            else if (i == 6)
                                tal = 48;
                            else if (i == 7)
                                tal = 54;
                            else if (i == 8)
                                tal = 62;
                            else if (i == 8)
                                tal = 68;
                            else if (i == 9)
                                tal = 74;
                            else if (i == 10)
                                tal = 80;
                            else if (i == 11)
                                tal = 86;
                            else if (i == 12)
                                tal = 92;
                            else if (i == 13)
                                tal = 98;
                            else if (i == 14)
                                tal = 109;

                            me->SummonCreature_OP(53698, Tornado[tal]);
                        }
                        needSummon = false;
                    }
                    else
                        timerSummon -= diff;
                }
        };
};

class spell_molthen_feater: public SpellScriptLoader
{
    public:
        spell_molthen_feater() :
                SpellScriptLoader("spell_molthen_feater")
        {
        }

        class spell_molthen_feater_AuraScript: public AuraScript
        {
                PrepareAuraScript(spell_molthen_feater_AuraScript)
                ;

                void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
                {
                    GetTarget()->SetAltPower(0);
                    GetTarget()->SetPower(POWER_ALTERNATE_POWER, 0);

                    for (uint8 i = 0; i < 10; i++)
                        if (GetTarget()->HasAura(98761 + i))
                            GetTarget()->RemoveAura(98761 + i);
                }

                void Register()
                {
                    AfterEffectRemove +=
                            AuraEffectRemoveFn(spell_molthen_feater_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_INCREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_molthen_feater_AuraScript();
        }
};

class spell_fieroblast: public SpellScriptLoader
{
    public:
        spell_fieroblast() :
                SpellScriptLoader("spell_fieroblast")
        {
        }

        class spell_fieroblast_AuraScript: public AuraScript
        {
                PrepareAuraScript(spell_fieroblast_AuraScript)
                ;

                void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
                {
                    if (GetCaster())
                        GetCaster()->AddAura(SPELL_FIREITUP, GetCaster());
                }

                void Register()
                {
                    OnEffectApply +=
                            AuraEffectApplyFn(spell_fieroblast_AuraScript::OnApply, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_fieroblast_AuraScript();
        }
};

class spell_molthen: public SpellScriptLoader
{
    public:
        spell_molthen() :
                SpellScriptLoader("spell_molthen")
        {
        }

        class spell_molthen_AuraScript: public AuraScript
        {
                PrepareAuraScript(spell_molthen_AuraScript)
                ;

                void OnPeriodic(AuraEffect const* /*aurEff*/)
                {
                    if (GetTarget())
                        GetTarget()->SummonCreature_OP(NPC_MOLTEN_FEATHER, GetTarget()->GetPositionX() - urand(5, 30),
                                GetTarget()->GetPositionY() - urand(-5, -30), 56.500f);
                }

                void Register()
                {
                    OnEffectPeriodic +=
                            AuraEffectPeriodicFn(spell_molthen_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_molthen_AuraScript();
        }
};

class spell_hatchling_debuff: public SpellScriptLoader
{
    public:
        spell_hatchling_debuff() :
                SpellScriptLoader("spell_hatchling_debuff")
        {
        }

        class spell_hatchling_debuff_AuraScript: public AuraScript
        {
                PrepareAuraScript(spell_hatchling_debuff_AuraScript)
                ;

                void PeriodicTick(AuraEffect const* /*aurEff*/)
                {
                    if (GetTarget()->HealthBelowPct(51) && GetTarget()->HasAura(SPELL_DEBUFF))
                        GetTarget()->RemoveAura(SPELL_DEBUFF);
                }

                void Register()
                {
                    OnEffectPeriodic +=
                            AuraEffectPeriodicFn(spell_hatchling_debuff_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_hatchling_debuff_AuraScript();
        }
};

class mob_aly_gauntlet_stalker: public CreatureScript
{
    public:
        mob_aly_gauntlet_stalker() : CreatureScript("mob_aly_gauntlet_stalker") { }

        struct mob_aly_gauntlet_stalkerAI: public ScriptedAI
        {
                mob_aly_gauntlet_stalkerAI(Creature* creature) : ScriptedAI(creature) { }

                void Reset()
                {
                    detect = false;
                }

                void MoveInLineOfSight(Unit* who)
                {
                    if (who && who->GetTypeId() == TYPEID_PLAYER)

                        if (!detect && me->GetExactDist(who) <= 20.0f)
                        {
                            detect = true;
                            ScriptedAI::MoveInLineOfSight(who);
                            if (Creature* strangle = me->FindNearestCreature(NPC_MAJORDOMUS_GAUNTLET, 35.0f, true))
                                strangle->AI()->DoAction(ACTION_START_GAUNTLET);
                        }
                }
            private:
                bool detect;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_aly_gauntlet_stalkerAI(creature);
        }
};

// ToDo: Include find the correct spell for (Kill all druids) to remove the hack KillAllDruidUnits

class mob_strangle_aly_gauntlet: public CreatureScript
{
    public:
        mob_strangle_aly_gauntlet() : CreatureScript("mob_strangle_aly_gauntlet") { }

        struct mob_strangle_aly_gauntletAI: public ScriptedAI
        {
                mob_strangle_aly_gauntletAI(Creature* creature) : ScriptedAI(creature), _isGauntletInProgress(false)
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetReactState(REACT_DEFENSIVE);
//                    me->GetMotionMaster()->MoveRandom(5.0f);
                }

                void Reset()
                {
                    _isGauntletInProgress= false;
                }

                void EnterCombat(Unit* /*who*/) { }

                void DoAction(int32 const action)
                {
                    switch (action)
                    {
                        case ACTION_START_GAUNTLET:
                            _isGauntletInProgress= true;
                            me->setActive(true);
                            events.ScheduleEvent(EVENT_ROOT_PLAYERS, 500);
                            break;
                        case ACTION_DROP_FEATHER:
                            _isGauntletInProgress= true;
                            me->SummonCreature(NPC_MOLTEN_FEATHER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                            break;
                        default:
                            break;
                    }
                }

                void KillAllDruidUnits(uint32 entry)
                {
                    std::list<Creature*> creatures;
                    GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);
                    if (creatures.empty())
                        return;
                    for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    {
                        (*iter)->setDeathState(JUST_DIED);
                        (*iter)->DespawnOrUnsummon(10000);
                    }
                }

                void UpdateAI(const uint32 diff)
                {
                    if (!UpdateVictim() && !_isGauntletInProgress)
                        return;

                    events.Update(diff);

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    if (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_ROOT_PLAYERS:
                                Talk(SAY_MAJO_INTRO);
                                me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
//                                me->GetMotionMaster()->MoveIdle();
                                DoCastAOE(SPELL_ROOT_PLAYERS);
                                events.ScheduleEvent(EVENT_MOVE_CENTER, 8000);
                                break;
                            case EVENT_MOVE_CENTER:
                                me->GetMotionMaster()->MovePoint(0, StaghelmMainPos);
                                events.ScheduleEvent(EVENT_TALK_SHIT, 5000);
                                break;
                            case EVENT_TALK_SHIT:
                                Talk(SAY_MAJO_STEP_ONE);
                                me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                events.ScheduleEvent(EVENT_TALK_SHIT_1, 6000);
                                break;
                            case EVENT_TALK_SHIT_1:
                                // KILL UNITS | need correct spell
                                DoCast(me, SPELL_CAM_SHAKE, false);
                                KillAllDruidUnits(NPC_TALON_DRUID);
                                events.ScheduleEvent(EVENT_TALK_SHIT_2, 4000);
                                break;
                            case EVENT_TALK_SHIT_2:
                                me->SetDisplayId(MODEL_FIREHAWK);
                                events.ScheduleEvent(EVENT_TRANSFORM_HAWK, 4000);
                                break;
                            case EVENT_TRANSFORM_HAWK:
                                Talk(SAY_MAJO_FINISH);
                                me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                                me->SetCanFly(true);
                                me->SetDisableGravity(true);
                                me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                                me->GetMotionMaster()->MoveTakeoff(0, StaghelmTakeOff);
                                events.ScheduleEvent(EVENT_FLY_UP, 4000);
                                break;
                            case EVENT_FLY_UP:
                                DoAction(ACTION_DROP_FEATHER);
                                me->SetSpeed(MOVE_FLIGHT, 1.5f, true);
                                me->GetMotionMaster()->MovePoint(0, StaghelmFlyUpPos);
                                events.ScheduleEvent(EVENT_FLYAWAY, 4000);
                                break;
                            case EVENT_FLYAWAY:
                                me->SetSpeed(MOVE_FLIGHT, 3.5f, true);
                                me->GetMotionMaster()->MovePoint(0, StaghelmFlyQuitPos);
                                me->DespawnOrUnsummon(15000);
                                break;
                        }
                    }
                }
            private:
                EventMap events;
                bool _isGauntletInProgress;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new mob_strangle_aly_gauntletAI(creature);
        }
};

void AddSC_boss_alysrazor()
{
    new npc_harbinger_of_flame();
    new npc_blazing_monstrosity();
    new npc_molten_barrage();
    new npc_egg_pile();
    new spell_alysrazor_cosmetic_egg_xplosion();
    new spell_alysrazor_turn_monstrosity();
    new spell_alysrazor_aggro_closest();
    new spell_alysrazor_fieroblast();
    new mob_molten_feather();
    new mob_incendiary_cloud();
    new boss_alysrazor();
    new npc_alysrazor_volcano();
    new npc_fier_tornado();
    new spell_molthen_feater();
    new spell_molthen();
    new mob_blazing_power();
    new npc_plumb_lava_worm();
    new npc_blazing_broodmother();
    new npc_molten_egg();
    new npc_voracious_hatchling();
    new spell_hatchling_debuff();
    new npc_blazing_talon_clawshaper();
    new npc_blazing_talon();
    new npc_brushfire();
    new spell_fieroblast();
    new npc_fiery_tornado();
    new mob_aly_gauntlet_stalker();
    new mob_strangle_aly_gauntlet();
}
