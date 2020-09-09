#ifndef PASSWORD_SLOT_CPP
#define PASSWORD_SLOT_CPP

#include <sstream>

#include "passwordSlot.h"

mmxpd::AchievementGroups mmxpd::PasswordSlot::createAchievementGroups(size_t traversionIndex) const {
    Traversion traversion = traversions[traversionIndex];

    PairGroup selectedPairGroup;
    if (pairGroups[0].contains(value)) {
        selectedPairGroup = pairGroups[0];
    } else if (pairGroups[1].contains(value)) {
        selectedPairGroup = pairGroups[1];
    } else {
        std::ostringstream errorOstream;
        errorOstream << "Value " << value << " was not found on any pair group.";
        throw errorOstream.str();
    }

    return selectedPairGroup.createAchievementGroups(traversion);
}

mmxpd::PasswordSlot::PasswordSlot() {
    this->value = 0;
    this->traversions = {};
    this->achievements = {};
    this->pairGroups = {};
}

mmxpd::PasswordSlot::PasswordSlot(unsigned short value, std::array<Traversion, TRAVERSION_SETS> traversions, std::array<Achievement, 2> achievements, std::array<PairGroup, 2> pairGroups) {
    this->value = value;
    this->traversions = traversions;
    this->achievements = achievements;
    this->pairGroups = pairGroups;
}

bool mmxpd::PasswordSlot::isValueInPairGroup(size_t pairGroupIndex) const {
    return pairGroups[pairGroupIndex].contains(value);
}

std::ostream& mmxpd::operator<<(std::ostream& ostream, const mmxpd::PasswordSlot& passwordSlot){
    ostream << passwordSlot.value;
    return ostream;
}

std::list<mmxpd::Achievement> mmxpd::PasswordSlot::retrieveAchievements(size_t traversionIndex) const {
    AchievementGroups achievementGroups = createAchievementGroups(traversionIndex);
    AchievementGroup achievementGroup = achievementGroups.whichGroupContains(value);
    return createAchievementsList(achievementGroup);
}

std::list<mmxpd::Achievement> mmxpd::PasswordSlot::createAchievementsList(AchievementGroup achievementGroup) const {
    std::list<mmxpd::Achievement> achievements;
    switch(achievementGroup) {
        case AchievementGroup::NONE:
            break;
        case AchievementGroup::FIRST:
            achievements.insert(achievements.end(), this->achievements[0]);
            break;
        case AchievementGroup::SECOND:
            achievements.insert(achievements.end(), this->achievements[1]);
            break;
        case AchievementGroup::BOTH:
            achievements.insert(achievements.end(), this->achievements[0]);
            achievements.insert(achievements.end(), this->achievements[1]);
            break; 
    }

    return achievements;
}

#endif