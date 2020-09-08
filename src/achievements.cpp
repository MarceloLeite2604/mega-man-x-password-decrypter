#ifndef ACHIEVEMENTS_CPP
#define ACHIEVEMENTS_CPP

#include <array>
#include <ostream>

#include "constants.cpp"

using namespace std;

namespace mmxpd {
    enum Achievement : unsigned short {
        DEFEATED_ARMORED_ARMADILLO,
        DEFEATED_BOOMER_KWANGER,
        DEFEATED_CHILL_PENGUIN,
        DEFEATED_LAUNCH_OCTOPUS,
        DEFEATED_SPARK_MANDRILL,
        DEFEATED_STING_CHAMELEON,
        DEFEATED_STORM_EAGLE,
        DEFEATED_FLAME_MAMMOTH,
        ACQUIRED_HEART_TANK_ARMORED_ARMADILLO_STAGE,
        ACQUIRED_HEART_TANK_BOOMER_KWANGER_STAGE,
        ACQUIRED_HEART_TANK_CHILL_PENGUIN_STAGE,
        ACQUIRED_HEART_TANK_LAUNCH_OCTOPUS_STAGE,
        ACQUIRED_HEART_TANK_SPARK_MANDRILL_STAGE,
        ACQUIRED_HEART_TANK_STING_CHAMELEON_STAGE,
        ACQUIRED_HEART_TANK_STORM_EAGLE_STAGE,
        ACQUIRED_HEART_TANK_FLAME_MAMMOTH_STAGE,
        ACQUIRED_SUB_TANK_ARMORED_ARMADILLO_STAGE,
        ACQUIRED_SUB_TANK_SPARK_MANDRILL_STAGE,
        ACQUIRED_SUB_TANK_STORM_EAGLE_STAGE,
        ACQUIRED_SUB_TANK_FLAME_MAMMOTH_STAGE,
        ACQUIRED_BOOTS,
        ACQUIRED_ARMOR,
        ACQUIRED_MEGA_BUSTER,
        ACQUIRED_HELMET,
        _SIZE
    };

    ostream& operator<<(ostream& ostream, Achievement achievements)
    {
        switch(achievements)
        {
            case DEFEATED_ARMORED_ARMADILLO: 
                ostream << "Player has defeated Armored Armadillo.";
                break;
            case DEFEATED_BOOMER_KWANGER:
                ostream << "Player has defeated Boomer Kwanger.";
                break;
            case DEFEATED_CHILL_PENGUIN:
                ostream << "Player has defeated Chill Penguin.";
                break;
            case DEFEATED_LAUNCH_OCTOPUS:
                ostream << "Player has defeated Launch Octopus.";
                break;
            case DEFEATED_SPARK_MANDRILL:
                ostream << "Player has defeated Spark Mandrill.";
                break;
            case DEFEATED_STING_CHAMELEON:
                ostream << "Player has defeated Sting Chameleon.";
                break;
            case DEFEATED_STORM_EAGLE:
                ostream << "Player has defeated Storm Eagle.";
                break;
            case DEFEATED_FLAME_MAMMOTH:
                ostream << "Player has defeated Flame Mammoth.";
                break;
            case ACQUIRED_HEART_TANK_ARMORED_ARMADILLO_STAGE:
                ostream << "Player has acquired heart tank on Armored Armadillo stage.";
                break;
            case ACQUIRED_HEART_TANK_BOOMER_KWANGER_STAGE:
                ostream << "Player has acquired heart tank on Boomer Kwanger stage.";
                break;
            case ACQUIRED_HEART_TANK_CHILL_PENGUIN_STAGE:
                ostream << "Player has acquired heart tank on Chill Penguin stage.";
                break;
            case ACQUIRED_HEART_TANK_LAUNCH_OCTOPUS_STAGE:
                ostream << "Player has acquired heart tank on Launch Octopus stage.";
                break;
            case ACQUIRED_HEART_TANK_SPARK_MANDRILL_STAGE:
                ostream << "Player has acquired heart tank on Spark Mandrill stage.";
                break;
            case ACQUIRED_HEART_TANK_STING_CHAMELEON_STAGE:
                ostream << "Player has acquired heart tank on Sting Chameleon stage.";
                break;
            case ACQUIRED_HEART_TANK_STORM_EAGLE_STAGE:
                ostream << "Player has acquired heart tank on Storm Eagle stage.";
                break;
            case ACQUIRED_HEART_TANK_FLAME_MAMMOTH_STAGE:
                ostream << "Player has acquired heart tank on Flame Mammoth stage.";
                break;
            case ACQUIRED_SUB_TANK_ARMORED_ARMADILLO_STAGE:
                ostream << "Player has acquired sub tank on Armored Armadillo stage.";
                break;
            case ACQUIRED_SUB_TANK_SPARK_MANDRILL_STAGE:
                ostream << "Player has acquired sub tank on Spark Mandrill stage.";
                break;
            case ACQUIRED_SUB_TANK_STORM_EAGLE_STAGE:
                ostream << "Player has acquired sub tank on Storm Eagle stage.";
                break;
            case ACQUIRED_SUB_TANK_FLAME_MAMMOTH_STAGE:
                ostream << "Player has acquired sub tank on Flame Mammoth stage.";
                break;
            case ACQUIRED_BOOTS:
                ostream << "Player has acquired boots.";
                break;
            case ACQUIRED_ARMOR:
                ostream << "Player has acquired armor.";
                break;
            case ACQUIRED_MEGA_BUSTER:
                ostream << "Player has acquired mega buster.";
                break;
            case ACQUIRED_HELMET:
                ostream << "Player has acquired helmet.";
                break;
            default:
                ostream << "[UNRECOGNIZED ACHIEVEMENT!]";
        }

        return ostream;
    }
}
/*
enum AchievementsRealized {
    NONE,
    FIRST,
    SECOND,
    BOTH
};

typedef array<unsigned short, 2> achievements;

typedef array<array<achievements, PASSWORD_GRID_X_SIZE>, PASSWORD_GRID_Y_SIZE> achievementsPositions;

const achievementsPositions ACHIEVEMENTS_POSITIONS =
{{
    {{ // y: 0
        {{ // x: 0
            ACQUIRED_HEART_TANK_CHILL_PENGUIN_STAGE,
            ACQUIRED_SUB_TANK_ARMORED_ARMADILLO_STAGE
        }},
        {{ // x: 1
            DEFEATED_FLAME_MAMMOTH,
            ACQUIRED_HELMET
        }},
        {{ // x: 2
            ACQUIRED_HEART_TANK_FLAME_MAMMOTH_STAGE,
            ACQUIRED_SUB_TANK_FLAME_MAMMOTH_STAGE
        }},
        {{ // x: 3
            DEFEATED_STORM_EAGLE,
            ACQUIRED_HEART_TANK_STORM_EAGLE_STAGE
        }}
    }},
    {{ // y: 1
        {{ // x: 0
            DEFEATED_LAUNCH_OCTOPUS,
            ACQUIRED_ARMOR
        }},
        {{ // x: 1
            DEFEATED_BOOMER_KWANGER,
            ACQUIRED_HEART_TANK_BOOMER_KWANGER_STAGE
        }},
        {{ // x: 2
            DEFEATED_ARMORED_ARMADILLO,
            ACQUIRED_MEGA_BUSTER
        }},
        {{ // x: 3
            DEFEATED_SPARK_MANDRILL,
            ACQUIRED_HEART_TANK_STING_CHAMELEON_STAGE
        }}
    }},
    {{ // y: 2
        {{ // x: 0
            ACQUIRED_HEART_TANK_ARMORED_ARMADILLO_STAGE,
            ACQUIRED_BOOTS
        }},
        {{ // x: 1
            DEFEATED_STING_CHAMELEON,
            ACQUIRED_SUB_TANK_STORM_EAGLE_STAGE
        }},
        {{ // x: 2
            ACQUIRED_HEART_TANK_LAUNCH_OCTOPUS_STAGE,
            ACQUIRED_SUB_TANK_SPARK_MANDRILL_STAGE
        }},
        {{ // x: 3
            DEFEATED_CHILL_PENGUIN,
            ACQUIRED_HEART_TANK_SPARK_MANDRILL_STAGE
        }}
    }}
}};
*/

#endif