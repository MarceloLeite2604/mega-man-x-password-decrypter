#ifndef ACHIEVEMENT_GROUPS_CPP
#define ACHIEVEMENT_GROUPS_CPP

#include <sstream>
#include "achievementGroups.h"

mmxpd::AchievementGroups::AchievementGroups(std::array<Pair, 4> matchingPairs) {
    this->none = {{matchingPairs[AchievementGroup::NONE]}};
    this->first = {{matchingPairs[AchievementGroup::FIRST]}};
    this->second = {{matchingPairs[AchievementGroup::SECOND]}};
    this->both = {{matchingPairs[AchievementGroup::BOTH]}};
}

mmxpd::AchievementGroup mmxpd::AchievementGroups::whichGroupContains(unsigned short value) {
    if (none.contains(value)) {
        return AchievementGroup::NONE;
    } else  if (first.contains(value)) {
        return AchievementGroup::FIRST;
    } else  if (second.contains(value)) {
        return AchievementGroup::SECOND;
    } else  if (both.contains(value)) {
        return AchievementGroup::BOTH;
    }

    std::ostringstream errorOstream;
    errorOstream << "Value " << value << " was not found in any achievement group.";
    throw errorOstream.str();
}

#endif