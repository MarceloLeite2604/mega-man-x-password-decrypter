#ifndef PASSWORD_SLOT_H
#define PASSWORD_SLOT_H

#include <list>

#include "traversion.h"
#include "achievement.h"
#include "constants.h"
#include "pairGroup.h"
#include "achievementGroups.h"

namespace mmxpd {

    class PasswordSlot {
        
        private:

        unsigned short value;
        std::array<Traversion, TRAVERSION_SETS> traversions;
        std::array<Achievement, 2> achievements;
        std::array<PairGroup, 2> pairGroups;

        AchievementGroups createAchievementGroups(size_t) const;

        public:

        PasswordSlot();
        PasswordSlot(unsigned short, std::array<Traversion, TRAVERSION_SETS>, std::array<Achievement, 2>, std::array<PairGroup, 2>);
        bool isValueInPairGroup(size_t) const;
        friend std::ostream& operator<<(std::ostream&, const PasswordSlot&);
        std::list<Achievement> retrieveAchievements(size_t) const;
        std::list<Achievement> createAchievementsList(AchievementGroup) const;
    };

    std::ostream& operator<<(std::ostream&, const PasswordSlot&);
}

#endif