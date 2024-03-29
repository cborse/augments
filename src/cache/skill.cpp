#include "cache.h"

const Skill Cache::skills[SKILL_COUNT] = {
    {
        .id = SKILL_NONE,
        .name = "NONE",
        .core = false,
        .desc1 = "",
        .desc2 = "",
    }, {
        .id = SKILL_FULL_SIGHT,
        .name = "FULL SIGHT",
        .core = true,
        .desc1 = "User's accuracy stat increases",
        .desc2 = "by 10%.",
    }, {
        .id = SKILL_FULL_VISION,
        .name = "FULL VISION",
        .core = true,
        .desc1 = "User's evastion stat increases",
        .desc2 = "by 10%.",
    }, {
        .id = SKILL_FULL_CHOKE,
        .name = "FULL CHOKE",
        .core = true,
        .desc1 = "Linear actions have increased",
        .desc2 = "power; spread actions have ",
        .desc3 = "decreased power.",
    }, {
        .id = SKILL_CYLINDER,
        .name = "CYLINDER",
        .core = true,
        .desc1 = "Spread actions have increased",
        .desc2 = "power; linear actions have",
        .desc3 = "decreased power.",
    }, {
        .id = SKILL_DETECT,
        .name = "DETECT",
        .core = true,
        .desc1 = "User and opponent become visible",
        .desc2 = "if within a 1 ring radius from",
        .desc3 = "eachother.",
    }, {
        .id = SKILL_SCREEN_STRENGTH,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Strength action absored.",
    }, {
        .id = SKILL_SCREEN_GROUND,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Ground action absored.",
    }, {
        .id = SKILL_SCREEN_WATER,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Water action absored.",
    }, {
        .id = SKILL_SCREEN_ICE,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Ice action absored.",
    }, {
        .id = SKILL_SCREEN_CHEMICAL,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Chemical action absored.",
    }, {
        .id = SKILL_SCREEN_METAL,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Metal action absored.",
    }, {
        .id = SKILL_SCREEN_STONE,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Stone action absored.",
    }, {
        .id = SKILL_SCREEN_SOLAR,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Solar action absored.",
    }, {
        .id = SKILL_SCREEN_PSYCHE,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Psyche action absored.",
    }, {
        .id = SKILL_SCREEN_WIND,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Wind action absored.",
    }, {
        .id = SKILL_SCREEN_ELECTRIC,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Electric action absored.",
    }, {
        .id = SKILL_SCREEN_SPIRIT,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Spirit action absorbed.",
    }, {
        .id = SKILL_SCREEN_FIRE,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Fire action absored.",
    }, {
        .id = SKILL_SCREEN_ILLUSION,
        .name = "SCREEN",
        .core = true,
        .desc1 = "Creature takes 5% less damage",
        .desc2 = "from any Illusion acction",
        .desc3 = "absored.",
    }, {
        .id = SKILL_REPLENISH,
        .name = "REPLENISH",
        .core = true,
        .desc1 = "Increases users Energy by 5% of ",
        .desc2 = "max at the end of each turn.",
    }, {
        .id = SKILL_RENEW,
        .name = "RENEW",
        .core = true,
        .desc1 = "Increases users Energy by 10% of",
        .desc2 = "max at the end of each turn;",
        .desc3 = "lowers Creatures Movement Speed.",
    }, {
        .id = SKILL_STEADY,
        .name = "STEADY",
        .core = true,
        .desc1 = "User can only move 1 tile per",
        .desc2 = "turn but uses no Energy when",
        .desc3 = "moving position.",
    }, {
        .id = SKILL_RETAIN_IP,
        .name = "RETAIN I.P.",
        .core = true,
        .desc1 = "Increases Inner Power stat by 50%",
        .desc2 = "but user cannot use their last",
        .desc3 = "available action.",
    }, {
        .id = SKILL_RETAIN_ID,
        .name = "RETAIN I.D.",
        .core = true,
        .desc1 = "Increases Inner Defence stat by",
        .desc2 = "50% but user cannot use their",
        .desc3 = "last available action.",
    }, {
        .id = SKILL_RETAIN_OP,
        .name = "RETAIN O.P.",
        .core = true,
        .desc1 = "Increases Outer Power stat by 50%",
        .desc2 = "but user cannot use their last",
        .desc3 = "available action.",
    }, {
        .id = SKILL_RETAIN_OD,
        .name = "RETAIN O.D.",
        .core = true,
        .desc1 = "Increases Outer Defence stat by",
        .desc2 = "50% but user cannot use their",
        .desc3 = "last available action.",
    }, {
        .id = SKILL_RETAIN_MS,
        .name = "RETAIN M.S.",
        .core = true,
        .desc1 = "Increases Movement Speed stat by",
        .desc2 = "50% but user cannot use their",
        .desc3 = "last available action.",
    }, {
        .id = SKILL_RETAIN_AS,
        .name = "RETAIN A.S.",
        .core = true,
        .desc1 = "Increases Action Speed stat by",
        .desc2 = "50% but user cannot use their",
        .desc3 = "last available action.",
    }, {
        .id = SKILL_RETAIN_S,
        .name = "RETAIN S",
        .core = true,
        .desc1 = "Increases Stamina stat by 50%",
        .desc2 = "but user cannot use their last",
        .desc3 = "available action.",
    }, {
        .id = SKILL_RETAIN_A,
        .name = "RETAIN A",
        .core = true,
        .desc1 = "Increases Accuracy stat by 50%",
        .desc2 = "but user cannot use their last",
        .desc3 = "available action.",
    }, {
        .id = SKILL_RETAIN_E,
        .name = "RETAIN E",
        .core = true,
        .desc1 = "Increases Evasion stat by 50%",
        .desc2 = "but user cannot use their last",
        .desc3 = "available action.",
    }, {
        .id = SKILL_EXPERT,
        .name = "EXPERT",
        .core = true,
        .desc1 = "Increases action power by 25% if",
        .desc2 = "it is the same type as the user.",
    }, {
        .id = SKILL_STEALTHY,
        .name = "STEALTHY",
        .core = true,
        .desc1 = "Creature remains hidden if they",
        .desc2 = "eliminate their foe.",
    }, {
        .id = SKILL_LUCKY,
        .name = "LUCKY",
        .core = false,
        .desc1 = "Increases Evasion stat by 100%",
        .desc2 = "when the Creature is stationary.",
    }, {
        .id = SKILL_EFFECTIVE,
        .name = "EFFECTIVE",
        .core = false,
        .desc1 = "Action always hits at maximum",
        .desc2 = "power.",
    }, {
        .id = SKILL_PRECISE,
        .name = "PRECISE",
        .core = false,
        .desc1 = "Action cannot miss.",
        .desc2 = "",
    }, {
        .id = SKILL_ORIGAMI,
        .name = "ORIGAMI",
        .core = false,
        .desc1 = "Increases Evasion stat by 50%.",
        .desc2 = "",
    }, {
        .id = SKILL_ERRATIC,
        .name = "ERRATIC",
        .core = false,
        .desc1 = "Increases Evasion stat by 100%",
        .desc2 = "when the Creature is moving",
        .desc3 = "position.",
    }, {
        .id = SKILL_DECOY,
        .name = "DECOY",
        .core = false,
        .desc1 = "Creature has a 25% chance of ",
        .desc2 = "completely avoiding incoming",
        .desc3 = "actions.",
    }, {
        .id = SKILL_AGILITY,
        .name = "AGILITY",
        .core = false,
        .desc1 = "Creature ignores any increased",
        .desc2 = "change to the opponent's Evasion",
        .desc3 = "stat.",
    }, {
        .id = SKILL_POCKET,
        .name = "POCKET",
        .core = false,
        .desc1 = "Accuracy and Evasion stats ",
        .desc2 = "increase by 25% when opponent is",
        .desc3 = "in adjacent tile.",
    }, {
        .id = SKILL_EQUANIMITY,
        .name = "EQUANIMITY",
        .core = false,
        .desc1 = "Creature's action cannot miss",
        .desc2 = "when the opponent has low health.",
    }, {
        .id = SKILL_RIFLED,
        .name = "RIFLED",
        .core = false,
        .desc1 = "Creature's Accuracy stat ",
        .desc2 = "increases by 200% when using  ",
        .desc3 = "cannon actions.",
    }, {
        .id = SKILL_BRILLIANT,
        .name = "BRILLIANT",
        .core = false,
        .desc1 = "Increases Evasion stat by 200%",
        .desc2 = "when the Creature is moving",
        .desc3 = "position; Creature is detected.",
    }, {
        .id = SKILL_SCARE_SPRING,
        .name = "SCARE SPRING",
        .core = false,
        .desc1 = "Creature jumps high in the air",
        .desc2 = "when frightened and avoids ",
        .desc3 = "incoming action.",
    }, {
        .id = SKILL_LONG_CLAW,
        .name = "LONG CLAW",
        .core = false,
        .desc1 = "Power increases by 25% for ",
        .desc2 = "slashing actions.",
    }, {
        .id = SKILL_JAWS,
        .name = "JAWS",
        .core = false,
        .desc1 = "Power increases by 25% for ",
        .desc2 = "biting actions.",
    }, {
        .id = SKILL_KNUCKLES,
        .name = "KNUCKLES",
        .core = false,
        .desc1 = "Power increases by 25% for ",
        .desc2 = "punching actions.",
    }, {
        .id = SKILL_BIG_PAW,
        .name = "BIG PAW",
        .core = false,
        .desc1 = "Power increases by 25% for ",
        .desc2 = "crushing actions.",
    }, {
        .id = SKILL_MAWS,
        .name = "MAWS",
        .core = false,
        .desc1 = "Power increases by 25% for jet",
        .desc2 = "actions.",
    }, {
        .id = SKILL_ELASTIC,
        .name = "ELASTIC",
        .core = false,
        .desc1 = "Offensive action covers double",
        .desc2 = "in distance.",
    }, {
        .id = SKILL_GLIDE_EJECT,
        .name = "GLIDE EJECT",
        .core = false,
        .desc1 = "User moves 3 tiles backward when",
        .desc2 = "hit by a super-effective action.",
    }, {
        .id = SKILL_EQUALITY,
        .name = "EQUALITY",
        .core = false,
        .desc1 = "User gets a primary action bonus",
        .desc2 = "for its secondary type.",
    }, {
        .id = SKILL_WIND_WISPER,
        .name = "WIND WISPER",
        .core = false,
        .desc1 = "Power of Spirit-type actions is",
        .desc2 = "increased by 25%.",
    }, {
        .id = SKILL_QUICK_PAW,
        .name = "QUICK PAW",
        .core = false,
        .desc1 = "Every action used will have ",
        .desc2 = "maximum Action speed.",
    }, {
        .id = SKILL_BUCK_TEETH,
        .name = "BUCK TEETH",
        .core = false,
        .desc1 = "Biting actions can cause critical",
        .desc2 = "damage.",
    }, {
        .id = SKILL_BRAWLER,
        .name = "BRAWLER",
        .core = false,
        .desc1 = "Power of Strength-type actions is",
        .desc2 = "increased by 25%.",
    }, {
        .id = SKILL_RUBBER,
        .name = "RUBBER",
        .core = false,
        .desc1 = "Chance that any incoming action",
        .desc2 = "will be redirected at the ",
        .desc3 = "attacker.",
    }, {
        .id = SKILL_FLUFFY,
        .name = "FLUFFY",
        .core = false,
        .desc1 = "Creature takes 50% less damage ",
        .desc2 = "from actions that make contact.",
    }, {
        .id = SKILL_JELLY,
        .name = "JELLY",
        .core = false,
        .desc1 = "Creature takes 75% less damage",
        .desc2 = "from actions that make contact;",
        .desc3 = "user cannot use contact actions.",
    }, {
        .id = SKILL_POINTY,
        .name = "POINTY",
        .core = false,
        .desc1 = "Creature's pointy body causes",
        .desc2 = "damage to the opponent when there",
        .desc3 = "is contact.",
    }, {
        .id = SKILL_GOO,
        .name = "GOO",
        .core = false,
        .desc1 = "Opponent's Speed stat lowers",
        .desc2 = "when there is contact.",
    }, {
        .id = SKILL_DENSITY,
        .name = "DENSITY",
        .core = false,
        .desc1 = "Creature cannot be damaged by",
        .desc2 = "contact actions.",
    }, {
        .id = SKILL_IRON_ARMOUR,
        .name = "IRON ARMOUR",
        .core = false,
        .desc1 = "Creature takes reduced damage",
        .desc2 = "from contact actions; users Speed",
        .desc3 = "& Stamina stats are lowered.",
    }, {
        .id = SKILL_WHET_STONE,
        .name = "WHET STONE",
        .core = false,
        .desc1 = "Creature's Outer Power increases",
        .desc2 = "by 25% when hit by a Metal-type",
        .desc3 = "action.",
    }, {
        .id = SKILL_SUPERCOOLED,
        .name = "SUPERCOOLED",
        .core = false,
        .desc1 = "Contact with this Creature may",
        .desc2 = "cause freezing.",
    }, {
        .id = SKILL_CHARGED,
        .name = "CHARGED",
        .core = false,
        .desc1 = "Contact with this Creature may",
        .desc2 = "cause paralysis.",
    }, {
        .id = SKILL_STINGERS,
        .name = "STINGERS",
        .core = false,
        .desc1 = "Contact with this Creature may",
        .desc2 = "cause paralysis.",
    }, {
        .id = SKILL_ALERT,
        .name = "ALERT",
        .core = false,
        .desc1 = "User can detect any Creatures",
        .desc2 = "within the immediate vicinity.",
    }, {
        .id = SKILL_OBSERVANT,
        .name = "OBSERVANT",
        .core = false,
        .desc1 = "User can detect any Creatures",
        .desc2 = "within the vicinity.",
    }, {
        .id = SKILL_VIGILANCE,
        .name = "VIGILANCE",
        .core = false,
        .desc1 = "User can detect any Creatures ",
        .desc2 = "within the area.",
    }, {
        .id = SKILL_VANTAGE,
        .name = "VANTAGE",
        .core = false,
        .desc1 = "User and opponents become easier",
        .desc2 = "to detect.",
    }, {
        .id = SKILL_SONAR,
        .name = "SONAR",
        .core = false,
        .desc1 = "User can detect any large",
        .desc2 = "Creatures within the vicinity.",
    }, {
        .id = SKILL_ECHOLOCATE,
        .name = "ECHOLOCATE",
        .core = false,
        .desc1 = "User can detect any small ",
        .desc2 = "Creatures within the vicinity.",
    }, {
        .id = SKILL_OPPORTUNIST,
        .name = "OPPORTUNIST",
        .core = false,
        .desc1 = "User can detect any seriously",
        .desc2 = "injured Creature.",
    }, {
        .id = SKILL_CLOUDY,
        .name = "CLOUDY",
        .core = false,
        .desc1 = "Creature's position can ",
        .desc2 = "spontaneously return to hidden.",
    }, {
        .id = SKILL_SNOW_COAT,
        .name = "SNOW COAT",
        .core = false,
        .desc1 = "Creature takes reduced damage",
        .desc2 = "from Ice-type actions.",
    }, {
        .id = SKILL_FURRY,
        .name = "FURRY",
        .core = false,
        .desc1 = "Creature takes reduced damage ",
        .desc2 = "from Ice-type actions.",
    }, {
        .id = SKILL_BLUBBER,
        .name = "BLUBBER",
        .core = false,
        .desc1 = "Creature takes reduced damage",
        .desc2 = "from Ice-type actions; Creatures",
        .desc3 = "Movement Speed stat is lowered.",
    }, {
        .id = SKILL_SUMMIT,
        .name = "SUMMIT",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Ice-type actions.",
    }, {
        .id = SKILL_HYDROPHOBIC,
        .name = "HYDROPHOBIC",
        .core = false,
        .desc1 = "Creature takes reduced damage ",
        .desc2 = "from Water-type actions.",
    }, {
        .id = SKILL_IRRIGATE,
        .name = "IRRIGATE",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Water-type actions and has",
        .desc3 = "boosted stats.",
    }, {
        .id = SKILL_SOAKED,
        .name = "SOAKED",
        .core = false,
        .desc1 = "Creature takes reduced damage",
        .desc2 = "from Water-type actions and has",
        .desc3 = "boosted stats.",
    }, {
        .id = SKILL_SOILED,
        .name = "SOILED",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Water-type actions and has a",
        .desc3 = "boosted stat.",
    }, {
        .id = SKILL_RETARDANT,
        .name = "RETARDANT",
        .core = false,
        .desc1 = "Creature takes reduced damage",
        .desc2 = "from Fire-type actions.",
    }, {
        .id = SKILL_FIREPROOF,
        .name = "FIREPROOF",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Fire-type actions and their",
        .desc3 = "effects.",
    }, {
        .id = SKILL_RUBBERIZED,
        .name = "RUBBERIZED",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Electric-type actions.",
    }, {
        .id = SKILL_INSULATED,
        .name = "INSULATED",
        .core = false,
        .desc1 = "Creature takes reduced damage",
        .desc2 = "from Electric-type actions.",
    }, {
        .id = SKILL_GROUNDED,
        .name = "GROUNDED",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Electric-type actions.",
    }, {
        .id = SKILL_INSENSIBLE,
        .name = "INSENSIBLE",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Psyche-type actions.",
    }, {
        .id = SKILL_CRYSTAL_BODY,
        .name = "CRYSTAL BODY",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Solar-type actions.",
    }, {
        .id = SKILL_SOLAR_SHIELD,
        .name = "SOLAR SHIELD",
        .core = false,
        .desc1 = "Creature takes reduced damage",
        .desc2 = "from Solar-type actions.",
    }, {
        .id = SKILL_GRANITE,
        .name = "GRANITE",
        .core = false,
        .desc1 = "Creature takes reduced damage",
        .desc2 = "from Watr-type and Wind-type",
        .desc3 = "actions.",
    }, {
        .id = SKILL_BALLOON,
        .name = "BALLOON",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Wind-type actions and is pushed",
        .desc3 = "to the end of the action cover.",
    }, {
        .id = SKILL_SAILS,
        .name = "SAILS",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Wind-type actions and has a",
        .desc3 = "boosted stat.",
    }, {
        .id = SKILL_LEVITATE,
        .name = "LEVITATE",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Ground-type actions.",
    }, {
        .id = SKILL_MEMBRANE,
        .name = "MEMBRANE",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Chemical-type actions.",
    }, {
        .id = SKILL_FILTER,
        .name = "FILTER",
        .core = false,
        .desc1 = "Creature is not affected by gas,",
        .desc2 = "smoke, or dust actions.",
    }, {
        .id = SKILL_LONG_NECK,
        .name = "LONG NECK",
        .core = false,
        .desc1 = "Creature avoids being hit by the",
        .desc2 = "full force of an action.",
    }, {
        .id = SKILL_ARMOUR_SUIT,
        .name = "ARMOUR SUIT",
        .core = false,
        .desc1 = "Creature only takes damage from",
        .desc2 = "super-effective actions; Speed",
        .desc3 = "stats are lowered.",
    }, {
        .id = SKILL_BONELESS,
        .name = "BONELESS",
        .core = false,
        .desc1 = "Creature is uneffected by any",
        .desc2 = "crushing actions.",
    }, {
        .id = SKILL_SCAVENGER,
        .name = "SCAVENGER",
        .core = false,
        .desc1 = "Creature gets double the increase",
        .desc2 = "from elimination perks.",
    }, {
        .id = SKILL_HARVEST,
        .name = "HARVEST",
        .core = false,
        .desc1 = "Any elimination perk attained ",
        .desc2 = "will bring the Creature's health",
        .desc3 = "back to maximum.",
    }, {
        .id = SKILL_VITALITY,
        .name = "VITALITY",
        .core = false,
        .desc1 = "Any elimination perk attained ",
        .desc2 = "will bring the Creature's energy",
        .desc3 = "back to maximum.",
    }, {
        .id = SKILL_AFTERLIFE,
        .name = "AFTERLIFE",
        .core = false,
        .desc1 = "The Creature's elimination perk",
        .desc2 = "will cause damage to the",
        .desc3 = "opponent.",
    }, {
        .id = SKILL_EFFICIENT,
        .name = "EFFICIENT",
        .core = false,
        .desc1 = "Creature uses less energy when",
        .desc2 = "attacking or moving position.",
    }, {
        .id = SKILL_ENDURANCE,
        .name = "ENDURANCE",
        .core = false,
        .desc1 = "Creature uses less energy when",
        .desc2 = "moving position.",
    }, {
        .id = SKILL_PRESSURE,
        .name = "PRESSURE",
        .core = false,
        .desc1 = "Opponent's use more energy when",
        .desc2 = "attacking.",
    }, {
        .id = SKILL_LOAD,
        .name = "LOAD",
        .core = false,
        .desc1 = "Creature recovers energy when hit",
        .desc2 = "by an Electric-type action.",
    }, {
        .id = SKILL_WINDMILL,
        .name = "WINDMILL",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Wind-type actions and recovers ",
        .desc3 = "the equivalent in energy.",
    }, {
        .id = SKILL_CHUBBYWEIGHT,
        .name = "CHUBBYWEIGHT",
        .core = false,
        .desc1 = "Creature recovers energy more",
        .desc2 = "quickly when energy is low.",
    }, {
        .id = SKILL_ADORABLE,
        .name = "ADORABLE",
        .core = false,
        .desc1 = "The Creature's adorableness",
        .desc2 = "causes a chance that the opponent",
        .desc3 = "will not attack.",
    }, {
        .id = SKILL_HYDRATE,
        .name = "HYDRATE",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Water-type actions and recovers",
        .desc3 = "the equivalent in health.",
    }, {
        .id = SKILL_SOAK,
        .name = "SOAK",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Water-type actions and recovers",
        .desc3 = "20% of max health.",
    }, {
        .id = SKILL_DURABLE,
        .name = "DURABLE",
        .core = false,
        .desc1 = "Creature cannot be eliminated",
        .desc2 = "from full health with one attack.",
    }, {
        .id = SKILL_PERSISTENT,
        .name = "PERSISTENT",
        .core = false,
        .desc1 = "Creature cannot be eliminated",
        .desc2 = "from full health in one turn.",
    }, {
        .id = SKILL_REGENERATE,
        .name = "REGENERATE",
        .core = false,
        .desc1 = "User recovers health each turn.",
        .desc2 = "",
    }, {
        .id = SKILL_OVERDRIVE,
        .name = "OVERDRIVE",
        .core = false,
        .desc1 = "Creature acts with full effort",
        .desc2 = "at the expense of their health.",
    }, {
        .id = SKILL_RESOLVED,
        .name = "RESOLVED",
        .core = false,
        .desc1 = "Creature has increased stats at",
        .desc2 = "the expnse of their health and",
        .desc3 = "energy.",
    }, {
        .id = SKILL_BLOODSUCKER,
        .name = "BLOODSUCKER",
        .core = false,
        .desc1 = "Creature converts 20% of the ",
        .desc2 = "damage dealt to the opponent into",
        .desc3 = "gained health.",
    }, {
        .id = SKILL_ROOTED,
        .name = "ROOTED",
        .core = false,
        .desc1 = "Creatures movement is limited to",
        .desc2 = "1-tile position per turn but",
        .desc3 = "increases Inner Defence stat.",
    }, {
        .id = SKILL_TORTOISE,
        .name = "TORTOISE",
        .core = false,
        .desc1 = "Creatures movement is limited to",
        .desc2 = "1-tile position per turn but",
        .desc3 = "increases Outer Defence stat.",
    }, {
        .id = SKILL_SEDATE,
        .name = "SEDATE",
        .core = false,
        .desc1 = "Creatures movement is limited to ",
        .desc2 = "2-tile positions per turn but",
        .desc3 = "increases both Defence stats.",
    }, {
        .id = SKILL_KINGLY,
        .name = "KINGLY",
        .core = false,
        .desc1 = "Opponents cannot move into a ",
        .desc2 = "1-ring radius of the Creature.",
    }, {
        .id = SKILL_RACER,
        .name = "RACER",
        .core = false,
        .desc1 = "Creature will always succeed in",
        .desc2 = "gaining position when competing",
        .desc3 = "for a tile.",
    }, {
        .id = SKILL_ROYAL_GUARD,
        .name = "ROYAL GUARD",
        .core = false,
        .desc1 = "Nothing can prevent the Creature",
        .desc2 = "from moving positions.",
    }, {
        .id = SKILL_EKRANOPLAN,
        .name = "EKRANOPLAN",
        .core = false,
        .desc1 = "Creature uses less energy and",
        .desc2 = "acts faster when moving position.",
    }, {
        .id = SKILL_RESILIENT,
        .name = "RESILIENT",
        .core = false,
        .desc1 = "Creatures Defence stats double",
        .desc2 = "when HP is at 25% of max.",
    }, {
        .id = SKILL_ADAPTABLE,
        .name = "ADAPTABLE",
        .core = false,
        .desc1 = "Creatures Inner Defnece stat",
        .desc2 = "doubles when HP is at 50% of max.",
    }, {
        .id = SKILL_ADAPTATION,
        .name = "ADAPTATION",
        .core = false,
        .desc1 = "All attacks taken are defended ",
        .desc2 = "using Outer Defence stat.",
    }, {
        .id = SKILL_ABSOLUTE,
        .name = "ABSOLUTE",
        .core = false,
        .desc1 = "Creature's stats cannot be",
        .desc2 = "lowered by any means.",
    }, {
        .id = SKILL_COMPETITVE,
        .name = "COMPETITVE",
        .core = false,
        .desc1 = "Outer Power stat increases to ",
        .desc2 = "match opponents.",
    }, {
        .id = SKILL_FLOW,
        .name = "FLOW",
        .core = false,
        .desc1 = "Eliminating an opponent increases",
        .desc2 = "Inner Power stat by 25%.",
    }, {
        .id = SKILL_ANTICIPATION,
        .name = "ANTICIPATION",
        .core = false,
        .desc1 = "Increased Action Speed when",
        .desc2 = "opponent and Creature are",
        .desc3 = "attacking on the same turn.",
    }, {
        .id = SKILL_HESITANT,
        .name = "HESITANT",
        .core = false,
        .desc1 = "Opponents hesitate when attacking",
        .desc2 = "this Creature in a 1-ring radius.",
    }, {
        .id = SKILL_EXPLOSIVE,
        .name = "EXPLOSIVE",
        .core = false,
        .desc1 = "Creature's Action Speed is ",
        .desc2 = "doubled when attacking opponents",
        .desc3 = "in close range.",
    }, {
        .id = SKILL_CAPACITOR,
        .name = "CAPACITOR",
        .core = false,
        .desc1 = "Creature's Speed stats increase",
        .desc2 = "when hit with an Electric-type",
        .desc3 = "action.",
    }, {
        .id = SKILL_FRIGHTENING,
        .name = "FRIGHTENING",
        .core = false,
        .desc1 = "Opponent's Inner Power stat is",
        .desc2 = "lowered if attacked by this",
        .desc3 = "Creature.",
    }, {
        .id = SKILL_TERRIFYING,
        .name = "TERRIFYING",
        .core = false,
        .desc1 = "Opponent's Outer Power stat is",
        .desc2 = "lowered if attacked by this",
        .desc3 = "Creature.",
    }, {
        .id = SKILL_TEMPER,
        .name = "TEMPER",
        .core = false,
        .desc1 = "Creature's Outer Defence stat ",
        .desc2 = "increases whenever they are",
        .desc3 = "attacked.",
    }, {
        .id = SKILL_MOODY,
        .name = "MOODY",
        .core = false,
        .desc1 = "Creature's Action Speed stat",
        .desc2 = "increases whenever they are ",
        .desc3 = "attacked.",
    }, {
        .id = SKILL_RELATIVITY,
        .name = "RELATIVITY",
        .core = false,
        .desc1 = "Opponent's Speed stats decrease",
        .desc2 = "the closer they are to this ",
        .desc3 = "Creature.",
    }, {
        .id = SKILL_MICROPHOBIA,
        .name = "MICROPHOBIA",
        .core = false,
        .desc1 = "Lowers Outer Power and Inner",
        .desc2 = "Defence stats of much larger",
        .desc3 = "opponents.",
    }, {
        .id = SKILL_FRENZIED,
        .name = "FRENZIED",
        .core = false,
        .desc1 = "Creature's Outer Power stat",
        .desc2 = "increases but Evasion stat lowers",
        .desc3 = "when the Creature has low health.",
    }, {
        .id = SKILL_BURDEN,
        .name = "BURDEN",
        .core = false,
        .desc1 = "If the Creature is the last",
        .desc2 = "remaining team member their Inner",
        .desc3 = "Power stat is maxed.",
    }, {
        .id = SKILL_CHARCOAL,
        .name = "CHARCOAL",
        .core = false,
        .desc1 = "All the Creature's stats increase",
        .desc2 = "when hit by a Fire-type action.",
    }, {
        .id = SKILL_GEAR_SHIFT,
        .name = "GEAR SHIFT",
        .core = false,
        .desc1 = "User swaps Action Speed stat",
        .desc2 = "with the opponent if opponent has",
        .desc3 = "a higher stat.",
    }, {
        .id = SKILL_SUPERCELL,
        .name = "SUPERCELL",
        .core = false,
        .desc1 = "Creature's Inner Power and Outer",
        .desc2 = "Power stats increase when hit by",
        .desc3 = "a Water-type action.",
    }, {
        .id = SKILL_LIFT,
        .name = "LIFT",
        .core = false,
        .desc1 = "Creature's Inner Power and Outer",
        .desc2 = "Power stats increase when hit by",
        .desc3 = "a Wind-type action.",
    }, {
        .id = SKILL_SUGAR_RUSH,
        .name = "SUGAR RUSH",
        .core = false,
        .desc1 = "Creature's Speed stats increase",
        .desc2 = "each turn of battle.",
    }, {
        .id = SKILL_FORTUNATE,
        .name = "FORTUNATE",
        .core = false,
        .desc1 = "If the Creature acts after an",
        .desc2 = "opponent, the opponent's attack",
        .desc3 = "will do 20% less damage.",
    }, {
        .id = SKILL_DIVERT,
        .name = "DIVERT",
        .core = false,
        .desc1 = "The Creature will intercept any",
        .desc2 = "uneffective close-range opponent",
        .desc3 = "actions directed at an ally.",
    }, {
        .id = SKILL_RECOMBINE,
        .name = "RECOMBINE",
        .core = false,
        .desc1 = "If the Creature eliminates an ",
        .desc2 = "opponent it will absorb the ",
        .desc3 = "opponent's highest stat.",
    }, {
        .id = SKILL_FIRE_HAZARD,
        .name = "FIRE HAZARD",
        .core = false,
        .desc1 = "Damage from Fire-type actions",
        .desc2 = "will cause continuous damage;",
        .desc3 = "Inner Power stat is maxed.",
    }, {
        .id = SKILL_STALKER,
        .name = "STALKER",
        .core = false,
        .desc1 = "Creature can use 3-tile movements",
        .desc2 = "without being detected.",
    }, {
        .id = SKILL_SHADOW,
        .name = "SHADOW",
        .core = false,
        .desc1 = "Creature can act without being",
        .desc2 = "detected.",
    }, {
        .id = SKILL_CONCEALED,
        .name = "CONCEALED",
        .core = false,
        .desc1 = "Creature remains hidden from",
        .desc2 = "detection actions or skills.",
    }, {
        .id = SKILL_CAMOUFLAGED,
        .name = "CAMOUFLAGED",
        .core = false,
        .desc1 = "Creature returns to hidden if it",
        .desc2 = "is stationary for one turn.",
    }, {
        .id = SKILL_CHAMELEON,
        .name = "CHAMELEON",
        .core = false,
        .desc1 = "Creature's position can never be",
        .desc2 = "detected.",
    }, {
        .id = SKILL_CURSED_CLOAK,
        .name = "CURSED CLOAK",
        .core = false,
        .desc1 = "If the Creature is hit by a",
        .desc2 = "Spiri-type action their position",
        .desc3 = "will return to hidden.",
    }, {
        .id = SKILL_DIRE_LUCK,
        .name = "DIRE LUCK",
        .core = false,
        .desc1 = "If this Creature is attacked the",
        .desc2 = "opponent will lose 10% of max ",
        .desc3 = "Heatlh and 30% of max Energy.",
    }, {
        .id = SKILL_GRIM_LUCK,
        .name = "GRIM LUCK",
        .core = false,
        .desc1 = "If this Creature is attacked the",
        .desc2 = "opponent will lose 10% of max ",
        .desc3 = "Health.",
    }, {
        .id = SKILL_AWFUL_LUCK,
        .name = "AWFUL LUCK",
        .core = false,
        .desc1 = "If this Creature is attacked the",
        .desc2 = "opponent will lose 30% of max ",
        .desc3 = "Energy.",
    }, {
        .id = SKILL_NESTING,
        .name = "NESTING",
        .core = false,
        .desc1 = "Defensive stats are increased",
        .desc2 = "when the Creature has higher",
        .desc3 = "health.",
    }, {
        .id = SKILL_SLYLY,
        .name = "SLYLY",
        .core = false,
        .desc1 = "Creature cannot be blocked from",
        .desc2 = "moving positions.",
    }, {
        .id = SKILL_MAZE,
        .name = "MAZE",
        .core = false,
        .desc1 = "If the Creature is detected there",
        .desc2 = "will be multiple illusions",
        .desc3 = "nearby.",
    }, {
        .id = SKILL_DESPAIR,
        .name = "DESPAIR",
        .core = false,
        .desc1 = "The opponent who detects this",
        .desc2 = "Creature will have all stats",
        .desc3 = "reduced.",
    }, {
        .id = SKILL_CORK,
        .name = "CORK",
        .core = false,
        .desc1 = "Creature is immune to damage from",
        .desc2 = "Water-type actions and Solar-type",
        .desc3 = "actions.",
    }, {
        .id = SKILL_CRACKEDSHELL,
        .name = "CRACKEDSHELL",
        .core = false,
        .desc1 = "If the user losses 50% of health",
        .desc2 = "from a contact action, defences",
        .desc3 = "reduce and speed stats max.",
    },
};
