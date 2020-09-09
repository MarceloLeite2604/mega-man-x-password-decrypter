#ifndef PAIR_H
#define PAIR_H

#include <array>

namespace mmxpd {

    class Pair {

        private:
        std::array<unsigned short, 2> values;

        public:
        Pair();
        Pair(std::array<unsigned short, 2>);
        bool contains(unsigned short);
    };
}

#endif