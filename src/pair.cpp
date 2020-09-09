#ifndef PAIR_CPP
#define PAIR_CPP

#include "headers/pair.h"
#include <algorithm>

mmxpd::Pair::Pair() {
    this->values = {};
}

mmxpd::Pair::Pair(std::array<unsigned short, 2> values) {
    this->values = values;
}

bool mmxpd::Pair::contains(unsigned short value) {
    return (std::count(values.begin(), values.end(), value) > 0);
}

#endif