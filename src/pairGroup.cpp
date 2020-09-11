#ifndef PAIR_GROUP_CPP
#define PAIR_GROUP_CPP

#include <sstream>
#include <algorithm>
#include "pairGroup.h"

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
        case Traversion::FORWARDS:
            break;
        case Traversion::BACKWARDS:
            std::reverse(matchingPairArray.begin(), matchingPairArray.end());
            break;
        case Traversion::FORWARDS_LEFT_ROTATE_TWICE:
            std::rotate(matchingPairArray.begin(), matchingPairArray.begin()+2, matchingPairArray.end());
            break;
        case Traversion::BACKWARDS_LEFT_ROTATE_TWICE:
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