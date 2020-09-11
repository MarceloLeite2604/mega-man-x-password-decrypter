#ifndef TRAVERSION_H
#define TRAVERSION_H

namespace mmxpd {

    enum Traversion : unsigned short {
        FORWARDS,
        FORWARDS_LEFT_ROTATE_TWICE,
        BACKWARDS,
        BACKWARDS_LEFT_ROTATE_TWICE
    };
}

#endif