#ifndef TRAVERSIONS_CPP
#define TRAVERSIONS_CPP

#include <array>
#include "constants.cpp"

namespace mmxpd {

    using namespace std;

    enum Traversion {
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD
    };
}
/*
typedef array<array<unsigned short, PASSWORD_GRID_X_SIZE>, PASSWORD_GRID_Y_SIZE> traversionPositions;

const traversionPositions TRAVERSION_POSITIONS_SET_0 =
{{
    {{ // y: 0
        FORWARD,
        FORWARD,
        FORWARD,
        FORWARD
    }},
    {{ // y: 1
        FORWARD,
        FORWARD,
        FORWARD,
        FORWARD
    }},
    {{ // y: 2
        FORWARD,
        FORWARD,
        FORWARD,
        FORWARD
    }}
}};

const traversionPositions TRAVERSION_POSITIONS_SET_1 =
{{
    {{ // y: 0
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD
    }},
    {{ // y: 1
        FORWARD,
        FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD
    }},
    {{ // y: 2
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD
    }}
}};

const traversionPositions TRAVERSION_POSITIONS_SET_2 =
{{
    {{ // y: 0
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        FORWARD
    }},
    {{ // y: 1
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        BACKWARD
    }},
    {{ // y: 2
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        FORWARD,
        FORWARD
    }}
}};

const traversionPositions TRAVERSION_POSITIONS_SET_3 =
{{
    {{ // y: 0
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
    }},
    {{ // y: 1
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        BACKWARD,
    }},
    {{ // y: 2
        BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD
    }}
}};

const traversionPositions TRAVERSION_POSITIONS_SET_4 =
{{
    {{ // y: 0
        FORWARD,
        FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD
    }},
    {{ // y: 1
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        FORWARD
    }},
    {{ // y: 2
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD
    }}
}};

const traversionPositions TRAVERSION_POSITIONS_SET_5 =
{{
    {{ // y: 0
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        FORWARD
    }},
    {{ // y: 1
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD
    }},
    {{ // y: 2
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        BACKWARD,
        BACKWARD
    }}
}};

const traversionPositions TRAVERSION_POSITIONS_SET_6 =
{{
    {{ // y: 0
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD
    }},
    {{ // y: 1
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        BACKWARD,
        BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD
    }},
    {{ // y: 2
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD
    }}
}};

const traversionPositions TRAVERSION_POSITIONS_SET_7 =
{{
    {{ // y: 0
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        FORWARD,
        FORWARD
    }},
    {{ // y: 1
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        BACKWARD,
        BACKWARD,
        BACKWARD
    }},
    {{ // y: 2
        BACKWARD,
        FORWARD,
        BACKWARD,
        BACKWARD
    }}
}};

typedef array<traversionPositions, PASSWORD_GROUPS_SETS> traversionsSet;

const traversionsSet TRAVERSIONS_SET =
{{
    TRAVERSION_POSITIONS_SET_0,
    TRAVERSION_POSITIONS_SET_1,
    TRAVERSION_POSITIONS_SET_2,
    TRAVERSION_POSITIONS_SET_3,
    TRAVERSION_POSITIONS_SET_4,
    TRAVERSION_POSITIONS_SET_5,
    TRAVERSION_POSITIONS_SET_6,
    TRAVERSION_POSITIONS_SET_7
}};
*/

#endif