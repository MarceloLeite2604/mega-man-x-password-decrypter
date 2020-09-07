#ifndef FACTOR_GROUPS_CPP
#define FACTOR_GROUPS_CPP

#include <array>
#include "constants.cpp"

using namespace std;

typedef array<unsigned short, 2> values;

typedef array<values, 4> factorSet;

typedef array<factorSet, 4> factorsGroup;

typedef array<array<factorsGroup, PASSWORD_GRID_X_SIZE>, PASSWORD_GRID_Y_SIZE> positionsFactorsGroups;

const positionsFactorsGroups POSITIONS_FACTORS_GROUPS =
{{
    {{  // y: 0
        {{ // x: 0
            {{ // factor group: 0
                {1,4}, {2,7}, {5,6}, {3,8}
            }},
            {{}}
        }},
        {{ // x: 1
            {{ // factor group: 0
                {2,3}, {7,8}, {1,4}, {5,6}
            }},
            {{}}
        }},
        {{ // x: 2
            {{ // factor group: 0
                {2}, {4}, {6}, {7}
            }},
            {{ // factor group: 1
                {1}, {5}, {8}, {3}
            }}
        }},
        {{ // x: 3
            {{ // factor group: 0
                {5}, {3}, {2}, {6}
            }},
            {{ // factor group: 1
                {4}, {7}, {8}, {1}
            }}
        }}
    }},
    {{ // y: 1
        {{ // x: 0
            {{ // factor group: 0
                {5,7}, {2,3}, {1,8}, {4,6}
            }},
            {{}}
        }},
        {{ // x: 1
            {{ // factor group: 0
                {2,8}, {4,7}, {1,3}, {5,6}
            }},
            {{}}
        }},
        {{ // x: 2
            {{ // factor group: 0
                {4,5}, {1,8}, {3,7}, {2,6}
            }},
            {{}}
        }},
        {{ // x: 3
            {{ // factor group: 0
                {2}, {6}, {8}, {7}
            }},
            {{}}
        }}
    }},
    {{ // y: 2
        {{ // x: 0
            {{ // factor group: 0
                {1,8}, {4,6}, {3,7}, {2,5}
            }},
            {{}}
        }},
        {{ // x: 1
            {{ // factor group: 0
                {8}, {3}, {2}, {1}
            }},
            {{ // factor group: 1
                {6}, {7}, {4}, {5}
            }}
        }},
        {{ // x: 2
            {{ // factor group: 0
                {2,6}, {7,8}, {3,5}, {1,4}
            }},
            {{}}
        }},
        {{ // x: 3
            {{ // factor group: 0
                {1}, {4}, {6}, {8}
            }},
            {{}}
        }}
    }}
}};

#endif