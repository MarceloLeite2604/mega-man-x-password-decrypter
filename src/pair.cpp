#ifndef PAIR_CPP
#define PAIR_CPP

#include <array>
#include <algorithm>

namespace mmxpd {

    using namespace std;

    class Pair {

        array<unsigned short, 2> values;

        public:
            Pair() {
                this->values = {};
            }

            Pair(array<unsigned short, 2> values) {
                this->values = values;
            }

            bool contains(unsigned short value) {
                return (std::count(values.begin(), values.end(), value) > 0);
            }
    };
}

#endif