#ifndef PAIR_GROUP_H
#define PAIR_GROUP_H

#include "achievementGroups.h"
#include "traversion.h"
#include "pair.h"

namespace mmxpd {

    class PairGroup {
        
        private:

        std::array<Pair, 4> values;

        public:

        PairGroup();
        PairGroup(std::array<Pair, 4>);
        bool contains(unsigned short) const;
        AchievementGroups createAchievementGroups(Traversion);
    };
}

#endif