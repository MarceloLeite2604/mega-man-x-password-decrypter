#ifndef PAIR_GROUP_CPP
#define PAIR_GROUP_CPP

#include <sstream>
#include <algorithm>
#include "headers/pairGroup.h"

mmxpd::PairGroup::PairGroup() {
    this->values = {};
}

mmxpd::PairGroup::PairGroup(std::array<Pair, 4> values) {
    this->values = values;
}

bool mmxpd::PairGroup::contains(unsigned short value) const {
    for(size_t index = 0; index < values.size(); index++) {
        Pair pair = values[index]; 
        if (pair.contains(value)) {
            return true;
        }
    }
    return false;
}

mmxpd::AchievementGroups mmxpd::PairGroup::createAchievementGroups(Traversion traversion) {

    std::array<Pair, 4> matchingPairArray = values;

    switch (traversion) {
        case Traversion::FORWARD:
            break;
        case Traversion::BACKWARD:
            std::reverse(matchingPairArray.begin(), matchingPairArray.end());
            break;
        case Traversion::LEFT_SHIFT_ROTATE_TWICE_FORWARD:
            std::rotate(matchingPairArray.begin(), matchingPairArray.begin()+2, matchingPairArray.end());
            break;
        case Traversion::LEFT_SHIFT_ROTATE_TWICE_BACKWARD:
            std::rotate(matchingPairArray.begin(), matchingPairArray.begin()+2, matchingPairArray.end());
            std::reverse(matchingPairArray.begin(), matchingPairArray.end());
            break;
        default:
            std::ostringstream errorOstream;
            errorOstream << "Traversion value " << traversion << " is not recognized.";
            throw errorOstream.str();
    }

    return {matchingPairArray};
}

#endif