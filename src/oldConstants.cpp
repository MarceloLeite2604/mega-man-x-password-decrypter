#ifndef CONSTANTS_CPP
#define CONSTANTS_CPP

#include "achievement.cpp"
#include "pairGroup.cpp"

namespace mmxpd {

    const size_t PASSWORD_GRID_Y_SIZE = 3;
    const size_t PASSWORD_GRID_X_SIZE = 4;
    const size_t TRAVERSION_SETS = 8;

    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_00 = {{
        FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_00 = {{
        ACQUIRED_HEART_TANK_CHILL_PENGUIN_STAGE,
        ACQUIRED_SUB_TANK_ARMORED_ARMADILLO_STAGE
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_00 = {{
        (PairGroup){{
            (Pair){{1,4}}, 
            (Pair){{2,7}}, 
            (Pair){{5,6}}, 
            (Pair){{3,8}}, 
        }}, 
        (PairGroup){}
    }};


    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_10 = {{
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_10 = {{
        DEFEATED_FLAME_MAMMOTH,
        ACQUIRED_HELMET
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_10 = {{
        (PairGroup){{
            (Pair){{2,3}}, 
            (Pair){{7,8}}, 
            (Pair){{1,4}}, 
            (Pair){{5,6}}, 
        }}, 
        (PairGroup){}
    }};

    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_20 = {{
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        FORWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_20 = {{
        ACQUIRED_HEART_TANK_FLAME_MAMMOTH_STAGE,
        ACQUIRED_SUB_TANK_FLAME_MAMMOTH_STAGE
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_20 = {{
        (PairGroup){{
            (Pair){{2}}, 
            (Pair){{4}}, 
            (Pair){{6}}, 
            (Pair){{7}}, 
        }}, 
        (PairGroup){{
            (Pair){{1}}, 
            (Pair){{5}}, 
            (Pair){{8}}, 
            (Pair){{3}}, 
        }}
    }};

    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_30 = {{
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        FORWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_30 = {{
        DEFEATED_STORM_EAGLE,
        ACQUIRED_HEART_TANK_STORM_EAGLE_STAGE
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_30 = {{
        (PairGroup){{
            (Pair){{5}}, 
            (Pair){{3}}, 
            (Pair){{2}}, 
            (Pair){{6}}, 
        }}, 
        (PairGroup){{
            (Pair){{4}}, 
            (Pair){{7}}, 
            (Pair){{8}}, 
            (Pair){{1}}, 
        }}
    }};

    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_01 = {{
        FORWARD,
        FORWARD,
        FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_01 = {{
        DEFEATED_LAUNCH_OCTOPUS,
        ACQUIRED_ARMOR
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_01 = {{
        (PairGroup){{
            (Pair){{5,7}}, 
            (Pair){{2,3}}, 
            (Pair){{1,8}}, 
            (Pair){{4,6}}, 
        }}, 
        (PairGroup){}
    }};

    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_11 = {{
        FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        BACKWARD,
        BACKWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_11 = {{
        DEFEATED_BOOMER_KWANGER,
        ACQUIRED_HEART_TANK_BOOMER_KWANGER_STAGE
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_11 = {{
        (PairGroup){{
            (Pair){{2,8}}, 
            (Pair){{4,7}}, 
            (Pair){{1,3}}, 
            (Pair){{5,6}}, 
        }}, 
        (PairGroup){}
    }};

    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_21 = {{
        FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        BACKWARD,
        BACKWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_21 = {{
        DEFEATED_ARMORED_ARMADILLO,
        ACQUIRED_MEGA_BUSTER
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_21 = {{
        (PairGroup){{
            (Pair){{4,5}}, 
            (Pair){{1,8}}, 
            (Pair){{3,7}}, 
            (Pair){{2,6}}, 
        }}, 
        (PairGroup){}
    }};

    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_31 = {{
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        BACKWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        BACKWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_31 = {{
        DEFEATED_SPARK_MANDRILL,
        ACQUIRED_HEART_TANK_STING_CHAMELEON_STAGE
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_31 = {{
        (PairGroup){{
            (Pair){{2}}, 
            (Pair){{6}}, 
            (Pair){{8}}, 
            (Pair){{7}}, 
        }}, 
        (PairGroup){}
    }};

    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_02 = {{
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        BACKWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        BACKWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_02 = {{
        ACQUIRED_HEART_TANK_ARMORED_ARMADILLO_STAGE,
        ACQUIRED_BOOTS
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_02 = {{
        (PairGroup){{
            (Pair){{1,8}}, 
            (Pair){{4,6}}, 
            (Pair){{3,7}}, 
            (Pair){{2,5}}, 
        }}, 
        (PairGroup){}
    }};

    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_12 = {{
        FORWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        FORWARD,
        FORWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_12 = {{
        DEFEATED_STING_CHAMELEON,
        ACQUIRED_SUB_TANK_STORM_EAGLE_STAGE
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_12 = {{
        (PairGroup){{
            (Pair){{8}}, 
            (Pair){{3}}, 
            (Pair){{2}}, 
            (Pair){{1}}, 
        }}, 
        (PairGroup){{
            (Pair){{6}}, 
            (Pair){{7}}, 
            (Pair){{4}}, 
            (Pair){{5}}, 
        }}
    }};

    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_22 = {{
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        BACKWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_22 = {{
        ACQUIRED_HEART_TANK_LAUNCH_OCTOPUS_STAGE,
        ACQUIRED_SUB_TANK_SPARK_MANDRILL_STAGE
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_22 = {{
        (PairGroup){{
            (Pair){{2,6}}, 
            (Pair){{7,8}}, 
            (Pair){{3,5}}, 
            (Pair){{1,4}}, 
        }}, 
        (PairGroup){}
    }};

    const std::array<Traversion, TRAVERSION_SETS> TRAVERSIONS_32 = {{
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        FORWARD,
        LEFT_SHIFT_ROTATE_TWICE_BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        BACKWARD,
        LEFT_SHIFT_ROTATE_TWICE_FORWARD,
        BACKWARD
    }};

    const std::array<Achievement, 2> ACHIEVEMENTS_32 = {{
        DEFEATED_CHILL_PENGUIN,
        ACQUIRED_HEART_TANK_SPARK_MANDRILL_STAGE
    }};

    const std::array<PairGroup, 2> PAIR_GROUPS_32 = {{
        (PairGroup){{
            (Pair){{1}}, 
            (Pair){{4}}, 
            (Pair){{6}}, 
            (Pair){{8}}, 
        }}, 
        (PairGroup){}
    }};
}

#endif