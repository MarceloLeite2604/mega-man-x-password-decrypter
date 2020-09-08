#ifndef PASSWORD_SLOT_CPP
#define PASSWORD_SLOT_CPP

#include <array>
#include <list>

#include "traversions.cpp"
#include "achievements.cpp"
#include "constants.cpp"
#include "pairGroup.cpp"
#include "achievementGroups.cpp"

namespace mmxpd {

    using namespace std;

    class PasswordSlot {

        unsigned short value;
        array<Traversion, PASSWORD_GROUPS_SETS> traversions;
        array<Achievement, 2> achievements;
        array<PairGroup, 2> pairGroups;

        AchievementGroups createAchievementGroups(size_t traversionIndex) const {
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

        public:

        PasswordSlot() {
            this->value = 0;
            this->traversions = {};
            this->achievements = {};
            this->pairGroups = {};
        }

        PasswordSlot(unsigned short value, array<Traversion, PASSWORD_GROUPS_SETS> traversions, array<Achievement, 2> achievements, array<PairGroup, 2> pairGroups) {
            this->value = value;
            this->traversions = traversions;
            this->achievements = achievements;
            this->pairGroups = pairGroups;
        }

        bool isValueInPairGroup(size_t pairGroupIndex) const {
            return pairGroups[pairGroupIndex].contains(value);
        }

        friend ostream& operator<<(ostream& ostream, const PasswordSlot& passwordSlot){
            ostream << passwordSlot.value;
            return ostream;
        }

        list<Achievement> retrieveAchievements(size_t traversionIndex) const {
            AchievementGroups achievementGroups = createAchievementGroups(traversionIndex);
            AchievementGroup achievementGroup = achievementGroups.whichGroupContains(value);
            return createAchievementsList(achievementGroup);
        }

        list<Achievement> createAchievementsList(AchievementGroup achievementGroup) const {
            list<Achievement> achievements;
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
    };
}

#endif