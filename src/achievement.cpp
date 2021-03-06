#ifndef ACHIEVEMENT_CPP
#define ACHIEVEMENT_CPP

#include <ostream>
#include "achievement.h"

std::ostream& mmxpd::operator<<(std::ostream& ostream, Achievement achievement) {
    switch(achievement)
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

#endif