//////////////////////////////////////////////////////////////////////////
//
// SneezyMUD - All rights reserved, SneezyMUD Coding Team
//
// spells.h
//
//////////////////////////////////////////////////////////////////////////


#ifndef __SPELLS_H
#define __SPELLS_H

enum spellNumT {
     DAMAGE_RIPPED_OUT_HEART = -58,
     DAMAGE_DISEMBOWLED_VR = -57,
     DAMAGE_NORMAL = -56,
     DAMAGE_CAVED_SKULL = -55,
     DAMAGE_BEHEADED = -54,
     DAMAGE_DISEMBOWLED_HR = -53,
     DAMAGE_STOMACH_WOUND = -52,
     DAMAGE_HACKED = -51,
     DAMAGE_IMPALE = -50,
     DAMAGE_STARVATION = -49,
     DAMAGE_FALL = -48,
     DAMAGE_HEMORRAGE = -47,
     DAMAGE_DROWN = -46,
     DAMAGE_DRAIN = -45,
     DAMAGE_DISRUPTION = -44,
     DAMAGE_SUFFOCATION = -43,
     DAMAGE_RAMMED = -42,
     DAMAGE_WHIRLPOOL = -41,
     DAMAGE_ELECTRIC = -40,
     DAMAGE_ACID = -39,
     DAMAGE_GUST = -38,
     DAMAGE_EATTEN = -37,
     DAMAGE_KICK_HEAD = -36,
     DAMAGE_KICK_SOLAR = -35,
     DAMAGE_HEADBUTT_THROAT = -34,
     DAMAGE_HEADBUTT_BODY = -33,
     DAMAGE_HEADBUTT_CROTCH = -32,
     DAMAGE_HEADBUTT_LEG = -31,
     DAMAGE_HEADBUTT_FOOT = -30,
     DAMAGE_HEADBUTT_JAW = -29,
     DAMAGE_TRAP_SLEEP = -28,
     DAMAGE_TRAP_TELEPORT = -27,
     DAMAGE_TRAP_FIRE = -26,
     DAMAGE_TRAP_POISON = -25,
     DAMAGE_TRAP_ACID = -24,
     DAMAGE_TRAP_TNT = -23,
     DAMAGE_TRAP_ENERGY = -22,
     DAMAGE_TRAP_BLUNT = -21,
     DAMAGE_TRAP_PIERCE = -20,
     DAMAGE_TRAP_SLASH = -19,
     DAMAGE_TRAP_FROST = -18,
     DAMAGE_TRAP_DISEASE = -17,
     DAMAGE_ARROWS = -16,
     DAMAGE_FIRE = -15,
     DAMAGE_FROST = -14,
     DAMAGE_HEADBUTT_SKULL = -13,
     DAMAGE_COLLISION = -12,
     DAMAGE_KICK_SHIN = -11,
     DAMAGE_KNEESTRIKE_FOOT = -10,
     DAMAGE_KNEESTRIKE_SHIN = -9,
     DAMAGE_KNEESTRIKE_KNEE = -8,
     DAMAGE_KNEESTRIKE_THIGH = -7,
     DAMAGE_KNEESTRIKE_CROTCH = -6,
     DAMAGE_KNEESTRIKE_SOLAR = -5,
     DAMAGE_KNEESTRIKE_CHIN = -4,
     DAMAGE_KNEESTRIKE_FACE = -3,
     DAMAGE_KICK_SIDE = -2,
     // keep all fake numbers before here

     // this is the only "fake" number a spell should use
     // that is, a potion with only 1 (of 3) spells should set other 2 to this
     // it should always be the highest of the fake numbers, and 1 less than
     // the first spell
     TYPE_UNDEFINED = -1,

     // this is the start of real spells
     // start of mage
     SPELL_GUST = 0,
     SPELL_SLING_SHOT,
     SPELL_GUSHER,
     SPELL_HANDS_OF_FLAME,
     SPELL_MYSTIC_DARTS,
     SPELL_FLARE,
     SPELL_SORCERERS_GLOBE,
     SPELL_FAERIE_FIRE,
     SPELL_ILLUMINATE,
     SPELL_DETECT_MAGIC,
     SPELL_STUNNING_ARROW,
     SPELL_MATERIALIZE,
     SPELL_PROTECTION_FROM_EARTH,
     SPELL_PROTECTION_FROM_AIR,
     SPELL_PROTECTION_FROM_FIRE,
     SPELL_PROTECTION_FROM_WATER,
     SPELL_PROTECTION_FROM_ELEMENTS,
     SPELL_PEBBLE_SPRAY,
     SPELL_ARCTIC_BLAST,
     SPELL_COLOR_SPRAY,
     SPELL_INFRAVISION,
     SPELL_IDENTIFY,
     SPELL_POWERSTONE,
     SPELL_FAERIE_FOG,
     SPELL_TELEPORT,
     SPELL_SENSE_LIFE,
     SPELL_CALM,
     SPELL_ACCELERATE,
     SPELL_DUST_STORM,
     SPELL_LEVITATE,
     SPELL_FEATHERY_DESCENT,
     SPELL_STEALTH,
     SPELL_GRANITE_FISTS,
     SPELL_ICY_GRIP,
     SPELL_GILLS_OF_FLESH,
     SPELL_TELEPATHY,
     SPELL_FEAR,
     SPELL_SLUMBER,
     SPELL_CONJURE_EARTH,
     SPELL_CONJURE_AIR,
     SPELL_CONJURE_FIRE,
     SPELL_CONJURE_WATER,
     SPELL_DISPEL_MAGIC,
     SPELL_ENHANCE_WEAPON,
     SPELL_GALVANIZE,
     SPELL_DETECT_INVISIBLE,
     SPELL_DISPEL_INVISIBLE,
     SPELL_TORNADO,
     SPELL_SAND_BLAST,
     SPELL_ICE_STORM,
     SPELL_BLAST_OF_FURY,
     SPELL_ACID_BLAST,
     SPELL_FIREBALL,
     SPELL_FARLOOK,
     SPELL_FALCON_WINGS,
     SPELL_INVISIBILITY,
     SPELL_ENSORCER,
     SPELL_EYES_OF_FERTUMAN,
     SPELL_COPY,
     SPELL_HASTE,
     SPELL_IMMOBILIZE,
     SPELL_SUFFOCATE,
     SPELL_FLY,
     SPELL_ANTIGRAVITY,
     SPELL_DIVINATION,
     SPELL_SHATTER,
     SPELL_SPONTANEOUS_GENERATION,
     SPELL_METEOR_SWARM,
     SPELL_LAVA_STREAM,
     SPELL_DEATH_MIST,
     SPELL_STONE_SKIN,
     SPELL_TRAIL_SEEK,
     SPELL_INFERNO,
     SPELL_HELLFIRE,
     SPELL_FLAMING_FLESH,
     SPELL_FLAMING_SWORD,
     SPELL_ENERGY_DRAIN,
     SPELL_ATOMIZE,
     SPELL_ANIMATE,
     SPELL_BIND,
     SPELL_FUMBLE,
     SPELL_TRUE_SIGHT,
     SPELL_CLOUD_OF_CONCEALMENT,
     SPELL_POLYMORPH,
     SPELL_SILENCE,
     SPELL_WATERY_GRAVE,
     SPELL_TSUNAMI,
     SPELL_BREATH_OF_SARAHAGE,
     SPELL_PLASMA_MIRROR,
     SPELL_GARMULS_TAIL,
     SPELL_ETHER_GATE,
     SPELL_KNOT,

     // end of mage
     // start of cleric

     SPELL_HEAL_LIGHT,
     SPELL_HARM_LIGHT,
     SPELL_CREATE_FOOD,
     SPELL_CREATE_WATER,
     SPELL_ARMOR,
     SPELL_BLESS,
     SPELL_CLOT,
     SPELL_RAIN_BRIMSTONE,
     SPELL_HEAL_SERIOUS,
     SPELL_HARM_SERIOUS,
     SPELL_STERILIZE,
     SPELL_EXPEL,
     SPELL_CURE_DISEASE,
     SPELL_CURSE,
     SPELL_REMOVE_CURSE,
     SPELL_CURE_POISON,
     SPELL_HEAL_CRITICAL,
     SPELL_SALVE,
     SPELL_POISON,
     SPELL_HARM_CRITICAL,
     SPELL_INFECT,
     SPELL_REFRESH,
     SPELL_NUMB,
     SPELL_DISEASE,
     SPELL_FLAMESTRIKE,
     SPELL_PLAGUE_LOCUSTS,
     SPELL_CURE_BLINDNESS,
     SPELL_SUMMON,
     SPELL_HEAL,
     SPELL_PARALYZE_LIMB,
     SPELL_WORD_OF_RECALL,
     SPELL_HARM,
     SPELL_BLINDNESS,
     SPELL_PILLAR_SALT,
     SPELL_EARTHQUAKE,
     SPELL_CALL_LIGHTNING,
     SPELL_SPONTANEOUS_COMBUST,
     SPELL_BLEED,
     SPELL_PARALYZE,
     SPELL_BONE_BREAKER,
     SPELL_WITHER_LIMB,
     SPELL_SANCTUARY,
     SPELL_CURE_PARALYSIS,
     SPELL_SECOND_WIND,
     SPELL_HEROES_FEAST,
     SPELL_ASTRAL_WALK,
     SPELL_PORTAL,
     SPELL_HEAL_FULL,
     SPELL_HEAL_CRITICAL_SPRAY,
     SPELL_HEAL_SPRAY,
     SPELL_HEAL_FULL_SPRAY,
     SPELL_RESTORE_LIMB,
     SPELL_KNIT_BONE,
     SPELL_RELIVE,

     // end of cleric

     // start of shaman
     SPELL_FLATULENCE,
     SPELL_ENLIVEN,
     SPELL_BLOOD_BOIL,
     SPELL_STUPIDITY,
     SPELL_CELERITE,
     SPELL_CREATE_WOOD_GOLEM,
     SPELL_CREATE_ROCK_GOLEM,
     SPELL_CREATE_IRON_GOLEM,
     SPELL_CREATE_DIAMOND_GOLEM,
     SPELL_ENTHRALL_SPECTRE,
     SPELL_ENTHRALL_GHAST,
     SPELL_ENTHRALL_GHOUL,
     SPELL_ENTHRALL_DEMON,
     SPELL_DEATHWAVE,
     SPELL_DISTORT,
     SPELL_SOUL_TWIST,
     SPELL_SQUISH,
     SPELL_CARDIAC_STRESS,
     SPELL_LEGBA,
     SPELL_DJALLA,
     SPELL_SENSE_LIFE_SHAMAN,
     SPELL_DETECT_SHADOW,
     SPELL_RAZE,
     SPELL_INTIMIDATE,
     SPELL_ROMBLER,
     SPELL_CHRISM,
     SPELL_CHEVAL,
     SPELL_HYPNOSIS,
     SPELL_LICH_TOUCH,
     SPELL_SHADOW_WALK,
     SPELL_CLARITY,
     SPELL_AQUALUNG,
     SPELL_AQUATIC_BLAST,
     SPELL_THORNFLESH,
     SPELL_SHIELD_OF_MISTS,
     SPELL_DANCING_BONES,
     SPELL_CONTROL_UNDEAD,
     SPELL_RESURRECTION,
     SPELL_VOODOO,
     SPELL_VAMPIRIC_TOUCH,
     SPELL_LIFE_LEECH,
     SPELL_CHASE_SPIRIT,
     SPELL_CLEANSE,
     SPELL_HEALING_GRASP,
     SPELL_EMBALM,

     // end of shaman

     // start of ranger
     SPELL_ROOT_CONTROL,
     SPELL_LIVING_VINES,
     SPELL_STICKS_TO_SNAKES,
     SPELL_STORMY_SKIES,
     SPELL_TREE_WALK,
     SPELL_SHAPESHIFT,
  SPELL_EARTHMAW,
  SPELL_CREEPING_DOOM,
  SPELL_FERAL_WRATH,
  SPELL_SKY_SPIRIT,
     // end of ranger

     // start of deikhan
     SPELL_HEAL_LIGHT_DEIKHAN,
     SPELL_ARMOR_DEIKHAN,
     SPELL_BLESS_DEIKHAN,
     SPELL_EXPEL_DEIKHAN,
     SPELL_CLOT_DEIKHAN,
     SPELL_RAIN_BRIMSTONE_DEIKHAN,
     SPELL_STERILIZE_DEIKHAN,
     SPELL_REMOVE_CURSE_DEIKHAN,
     SPELL_CURSE_DEIKHAN,
     SPELL_INFECT_DEIKHAN,
     SPELL_CURE_DISEASE_DEIKHAN,
     SPELL_CREATE_FOOD_DEIKHAN,
     SPELL_CREATE_WATER_DEIKHAN,
     SPELL_HEAL_SERIOUS_DEIKHAN,
     SPELL_CURE_POISON_DEIKHAN,
     SPELL_POISON_DEIKHAN,
     SPELL_HARM_SERIOUS_DEIKHAN,
     SPELL_HEAL_CRITICAL_DEIKHAN,
     SPELL_HARM_CRITICAL_DEIKHAN,
     SPELL_HARM_LIGHT_DEIKHAN,
     SPELL_HEROES_FEAST_DEIKHAN,
     SPELL_REFRESH_DEIKHAN,
     SPELL_SYNOSTODWEOMER,
     SPELL_SALVE_DEIKHAN,
     SPELL_HARM_DEIKHAN,
     SPELL_NUMB_DEIKHAN,
     SPELL_EARTHQUAKE_DEIKHAN,
     SPELL_CALL_LIGHTNING_DEIKHAN,
     // end of deikhan
     

     //  END OF SPELLS, START OF SKILLS

     
     // start of warrior
// KEEP KICK AS FIRST SKILL, OR MODIFY MIN_SKILL AND MAX_SPELL BELOW
     SKILL_KICK,
     SKILL_BASH,
     SKILL_TRIP,
     SKILL_HEADBUTT,
     SKILL_RESCUE,
     SKILL_BLACKSMITHING,
     SKILL_DISARM,
     SKILL_PARRY_WARRIOR,
     SKILL_BERSERK,
     SKILL_SWITCH_OPP,
     SKILL_BODYSLAM,
     SKILL_SPIN,
     SKILL_KNEESTRIKE,
     SKILL_SHOVE,
     SKILL_RETREAT,
     SKILL_GRAPPLE,
     SKILL_STOMP,
     SKILL_BRAWL_AVOIDANCE,
     SKILL_DOORBASH,
     SKILL_DEATHSTROKE,
     SKILL_DUAL_WIELD,
     SKILL_POWERMOVE,
     SKILL_TRANCE_OF_BLADES,
     SKILL_WEAPON_RETENTION,
     SKILL_BLACKSMITHING_ADVANCED,
     SKILL_CLOSE_QUARTERS_FIGHTING,
     SKILL_RIPOSTE,
     SKILL_TAUNT,

     // end of warrior

     // start of mage
     SKILL_SCRIBE,
     SKILL_REPAIR_MAGE,
     // end of mage
     
     // start of cleric
     SKILL_REPAIR_CLERIC,
     // end of cleric
     
     // start of ranger
     SKILL_TRANSFORM_LIMB,
     SKILL_BEAST_SOOTHER,
     SKILL_BEFRIEND_BEAST,
     SKILL_TRANSFIX,
     SKILL_BUTCHER,
     SKILL_BEAST_SUMMON,
     SKILL_BARKSKIN,
     SKILL_BEAST_CHARM,
     SKILL_APPLY_HERBS,
  // SKILL_REPAIR_RANGER,
     // end of ranger
     // start of deikhan

     SKILL_KICK_DEIKHAN,
     SKILL_CHIVALRY,
     SKILL_BASH_DEIKHAN,
     SKILL_RESCUE_DEIKHAN,
     SKILL_SMITE,
     SKILL_CHARGE,
     SKILL_DISARM_DEIKHAN,
     SKILL_SWITCH_DEIKHAN,
     SKILL_RETREAT_DEIKHAN,
     SKILL_SHOVE_DEIKHAN,
     SKILL_RIDE,
     SKILL_CALM_MOUNT,
     SKILL_TRAIN_MOUNT,
     SKILL_ADVANCED_RIDING,
     SKILL_RIDE_DOMESTIC,
     SKILL_RIDE_NONDOMESTIC,
     SKILL_RIDE_WINGED,
     SKILL_RIDE_EXOTIC,
     SKILL_LAY_HANDS,
     SKILL_REPAIR_DEIKHAN,


     // end of deikhan
     // start of monk

     SKILL_YOGINSA,
     SKILL_CINTAI,
     SKILL_OOMLAT,
     SKILL_KICK_MONK,
     SKILL_ADVANCED_KICKING,
     SKILL_DISARM_MONK,
     SKILL_GROUNDFIGHTING,
     SKILL_CHOP,
     SKILL_SPRINGLEAP,
     SKILL_DUFALI,
     SKILL_RETREAT_MONK,
     SKILL_SNOFALTE,
     SKILL_COUNTER_MOVE,
     SKILL_SWITCH_MONK,
     SKILL_JIRIN,
     SKILL_KUBO,
     SKILL_CATFALL,
     SKILL_WOHLIN,
     SKILL_VOPLAT,
     SKILL_BLINDFIGHTING,
     SKILL_CHI,
     SKILL_QUIV_PALM,
     SKILL_CRIT_HIT,
     SKILL_FEIGN_DEATH,
     SKILL_BLUR,
     SKILL_HURL,
     SKILL_SHOULDER_THROW,
     SKILL_IRON_FIST,
     SKILL_IRON_FLESH,
     SKILL_IRON_SKIN,
     SKILL_IRON_BONES,
     SKILL_IRON_MUSCLES,
     SKILL_IRON_LEGS,
     SKILL_IRON_WILL,
     SKILL_REPAIR_MONK,
     SKILL_CHAIN_ATTACK,
     SKILL_CATLEAP,
     SKILL_DEFENESTRATE,
     SKILL_BONEBREAK,

     // end of monk
     // start of thief

     SKILL_SWINDLE,
     SKILL_SNEAK,
     SKILL_STABBING,
     SKILL_RETREAT_THIEF,
     SKILL_KICK_THIEF,
     SKILL_PICK_LOCK,
     SKILL_BACKSTAB,
     SKILL_THROATSLIT,
     SKILL_SEARCH,
     SKILL_SPY,
     SKILL_SWITCH_THIEF,
     SKILL_STEAL,
     SKILL_DETECT_TRAP,
     SKILL_SUBTERFUGE,
     SKILL_DISARM_TRAP,
     SKILL_CUDGEL,
     SKILL_HIDE,
     SKILL_POISON_WEAPON,
     SKILL_DISGUISE,
     SKILL_DODGE_THIEF,
     SKILL_GARROTTE,
     SKILL_SET_TRAP_CONT,
     SKILL_SET_TRAP_DOOR,
     SKILL_SET_TRAP_MINE,
     SKILL_SET_TRAP_GREN,
     SKILL_SET_TRAP_ARROW,
     SKILL_DUAL_WIELD_THIEF,
     SKILL_DISARM_THIEF,
     SKILL_COUNTER_STEAL,
     SKILL_REPAIR_THIEF,
     SKILL_PLANT,
     SKILL_CONCEALMENT,
     SKILL_TRACK,

     // end of thief
     // start of shaman
     SKILL_RITUALISM,
     SKILL_SACRIFICE,
     SKILL_BREW,
     SKILL_TURN,
     SKILL_REPAIR_SHAMAN,
     
     // end of shaman
  
     // start of psionics
     SKILL_PSITELEPATHY,
     SKILL_TELE_SIGHT,
     SKILL_TELE_VISION,
     SKILL_MIND_FOCUS,
     SKILL_PSI_BLAST,
     SKILL_MIND_THRUST,
     SKILL_PSYCHIC_CRUSH, 
     SKILL_KINETIC_WAVE,
     SKILL_MIND_PRESERVATION,
     SKILL_TELEKINESIS,
     SKILL_PSIDRAIN,

     // end of psionics

     // start of generic

     SKILL_SIGN,
     SKILL_SWIM,
     SKILL_CONS_UNDEAD,
     SKILL_CONS_VEGGIE,
     SKILL_CONS_DEMON,
     SKILL_CONS_ANIMAL,
     SKILL_CONS_REPTILE,
     SKILL_CONS_PEOPLE,
     SKILL_CONS_GIANT,
     SKILL_CONS_OTHER,
     SKILL_READ_MAGIC,
     SKILL_BANDAGE,
     SKILL_CLIMB,
     SKILL_FAST_HEAL,
     SKILL_EVALUATE,
     SKILL_TACTICS,
     SKILL_DISSECT,
     SKILL_DEFENSE,
     SKILL_OFFENSE,
     SKILL_WHITTLE,
     SKILL_WIZARDRY,
     SKILL_MEDITATE,
     SKILL_DEVOTION,
     SKILL_PENANCE,
     SKILL_SLASH_PROF,
     SKILL_PIERCE_PROF,
     SKILL_BLUNT_PROF,
     SKILL_BAREHAND_PROF,
     SKILL_SLASH_SPEC,
     SKILL_BLUNT_SPEC,
     SKILL_PIERCE_SPEC,
     SKILL_BAREHAND_SPEC,
     SKILL_RANGED_SPEC,
     SKILL_RANGED_PROF,
     SKILL_FAST_LOAD,
     SKILL_SHARPEN,
     SKILL_DULL,
     SKILL_ATTUNE,
     SKILL_STAVECHARGE,
     SKILL_ALCOHOLISM,
     SKILL_FISHING,
     SKILL_LOGGING,
     SKILL_ADVANCED_DEFENSE,
     SKILL_MANA,
     SKILL_MEND,
     SKILL_FORAGE,
     SKILL_SEEKWATER,
     SKILL_SKIN,
     SKILL_DIVINATION,
     SKILL_ENCAMP,
     SKILL_HIKING,
     SKILL_FISHLORE,
     // end of generic

     // keep this as the last of the true skills
     MAX_SKILL,

     // put some fake damage types here

     // TYPE_MIN_HIT defines as first one here
     TYPE_HIT,
     TYPE_BLUDGEON,   // weap # : 7;
     TYPE_WHIP,   // weap # : 2;
     TYPE_CRUSH,   // weap # : 6;
     TYPE_SMASH,   // weap # : 4;
     TYPE_SMITE,   // weap # : 25;
     TYPE_PUMMEL,   // weap # : 12;
     TYPE_FLAIL,   // weap # : 13;
     TYPE_BEAT,   // weap # : 14;
     TYPE_THRASH,   // weap # : 15;
     TYPE_THUMP,   // weap # : 16;
     TYPE_WALLOP,   // weap # : 17;
     TYPE_BATTER,   // weap # : 18;
     TYPE_STRIKE,   // weap # : 19;
     TYPE_CLUB,   // weap # : 20;
     TYPE_POUND,   // weap # : 22;
     TYPE_PIERCE,   // weap # : 11;
     TYPE_BITE,   // weap # :9;
     TYPE_STING,   // weap # : 10;
     TYPE_STAB,   // weap # : 1;
     TYPE_THRUST,   // weap # : 23;
     TYPE_SPEAR,   // weap # : 24;
     TYPE_BEAK,   // weap # : 26;
     TYPE_SLASH,   // weap # : 3;
     TYPE_CLAW,   // weap # :8;
     TYPE_CLEAVE,   // weap # :5;
     TYPE_SLICE,   // weap # : 21;
     TYPE_AIR,   // weap # : 27;
     TYPE_EARTH,   // weap # : 28;
     TYPE_FIRE,   // weap # : 29;
     TYPE_WATER,   // weap # : 30;
     TYPE_BEAR_CLAW,   // weap # : 31;
     TYPE_KICK,   // monk melee kick
     TYPE_MAUL,   // yet another blunt type
     TYPE_SHOOT,
     TYPE_CANNON,

     // keep this as the last of the "weapon" damage types
     TYPE_MAX_HIT,  

     // FIRST_TRANFORMED_LIMB defines as the first one here
     AFFECT_TRANSFORMED_HANDS,
     AFFECT_TRANSFORMED_ARMS,
     AFFECT_TRANSFORMED_LEGS,
     AFFECT_TRANSFORMED_HEAD,
     AFFECT_TRANSFORMED_NECK,
     // keep this guy as last transformed
     LAST_TRANSFORMED_LIMB,

     // FIRST_BREATH_WEAPON defines as here, so careful of order
     SPELL_FIRE_BREATH,
     SPELL_CHLORINE_BREATH,
     SPELL_FROST_BREATH,
     SPELL_ACID_BREATH,
     SPELL_LIGHTNING_BREATH,
     SPELL_DUST_BREATH,
     LAST_BREATH_WEAPON,

     // these represent oddball affects, mostly used for affectData stuff
     AFFECT_DUMMY,
     AFFECT_DRUNK,
     AFFECT_NEWBIE,
     AFFECT_SKILL_ATTEMPT,
     AFFECT_FREE_DEATHS,
     AFFECT_TEST_FIGHT_MOB,
     AFFECT_DRUG,
     AFFECT_PET,
     AFFECT_CHARM,
     AFFECT_THRALL,
     AFFECT_ORPHAN_PET,
     AFFECT_DISEASE,
     AFFECT_COMBAT,
     AFFECT_PLAYERKILL,
     AFFECT_PLAYERLOOT,
     AFFECT_HORSEOWNED,
     AFFECT_GROWTH_POTION,
     AFFECT_WARY,
     AFFECT_DEFECTED,
     AFFECT_OFFER,
     AFFECT_OBJECT_USED,
     AFFECT_WAS_INDOORS,
     AFFECT_BITTEN_BY_VAMPIRE,
     AFFECT_IMMORTAL_BLESSING,
     AFFECT_PEEL_BLESSING,
     AFFECT_ANGUS_BLESSING,
     AFFECT_DAMESCENA_BLESSING,
     AFFECT_JESUS_BLESSING,
     AFFECT_VASCO_BLESSING,
     AFFECT_CORAL_BLESSING,
     AFFECT_BUMP_BLESSING,
     AFFECT_MAROR_BLESSING,
     AFFECT_DASH_BLESSING,
     AFFECT_DEIRDRE_BLESSING,
     AFFECT_GARTHAGK_BLESSING,
     AFFECT_MERCURY_BLESSING,
     AFFECT_METROHEP_BLESSING,
	 
     LAST_ODDBALL_AFFECT,
// DO NOT MODIFY THIS, AFFECTS SIZE OF CHARFILE
     ABSOLUTE_MAX_SKILL=900
};
const spellNumT MIN_SPELL = spellNumT(TYPE_UNDEFINED+1);
const spellNumT MAX_SPELL = spellNumT(SKILL_KICK); // 1 more than last spell
const spellNumT MIN_SKILL = spellNumT(SKILL_KICK - 1); // 1 less than 1st skill
const spellNumT TYPE_MIN_HIT = TYPE_HIT;
const spellNumT FIRST_TRANSFORMED_LIMB = AFFECT_TRANSFORMED_HANDS;
const spellNumT FIRST_BREATH_WEAPON = SPELL_FIRE_BREATH;
const spellNumT FIRST_ODDBALL_AFFECT = AFFECT_DUMMY;

extern spellNumT & operator++ (spellNumT &, int);
extern spellNumT & operator-= (spellNumT &, spellNumT);

#if 0
     SPELL_FIND_FAMILIAR,
     SKILL_BUTCHER,   // not coded;
     SPELL_DETECT_POISON,   // NOT CODED;
     SPELL_DETECT_POISON_DEIKHAN,   // not coded;
     SKILL_HOLY_WEAPONS,   // not coded;
     SPELL_HOLY_LIGHT,   // not coded;
     SPELL_CHAIN_LIGHTNING, // not coded
     SPELL_HAIL_STORM,   // not coded;
     SPELL_HOLOCAUST,   // not coded;
     SPELL_HARM_FULL,   // not coded (maybe good);
     SPELL_HARM_CRITICAL_SPRAY,   // not coded;
     SPELL_HARM_SPRAY,   // not coded;
     SPELL_HARM_FULL_SPRAY,   // not coded;
     SPELL_SYNO_CASTER,
     SKILL_THRUST,
     SKILL_SPEAR,
     SKILL_DEFEND,
     SKILL_THROW,
     SKILL_CASTING,
     SKILL_PRAYING,
     SKILL_MASS_FORAGE,
     SKILL_TAN,
#endif


#endif

