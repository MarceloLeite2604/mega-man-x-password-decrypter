#ifndef ACHIEVEMENT_GROUPS_H
#define ACHIEVEMENT_GROUPS_H

#include "achievementGroup.h"
#include "pair.h"

namespace mmxpd {

    class AchievementGroups {
        private:

        Pair none;
        Pair first;
        Pair second;
        Pair both;

        public:

        AchievementGroups(std::array<Pair, 4>);
        AchievementGroup whichGroupContains(unsigned short);

    };
}
#endif