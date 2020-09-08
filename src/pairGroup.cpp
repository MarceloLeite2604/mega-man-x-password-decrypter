#ifndef PAIR_GROUP_CPP
#define PAIR_GROUP_CPP

#include <sstream>

#include "achievementGroups.cpp"
#include "traversions.cpp"
#include "pair.cpp"

namespace mmxpd {

    using namespace std;

    class PairGroup {

        array<Pair, 4> values;

        public:

        PairGroup() {
            this->values = {};
        }

        PairGroup(array<Pair, 4> values) {
            this->values = values;
        }

        bool contains(unsigned short value) const {
            for(size_t index = 0; index < values.size(); index++) {
                Pair pair = values[index]; 
                if (pair.contains(value)) {
                    return true;
                }
            }
            return false;
        }

        AchievementGroups createAchievementGroups(Traversion traversion) {

            array<Pair, 4> matchingPairArray = values;

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
    };
}

#endif