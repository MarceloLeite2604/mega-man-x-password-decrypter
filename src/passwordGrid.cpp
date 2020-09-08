#ifndef PASSWORD_GRID_CPP
#define PASSWORD_GRID_CPP

#include <iostream>
#include <list>
#include "newConstants.cpp"
#include "passwordSlot.cpp"

namespace mmxpd {
    using namespace std;

    class PasswordGrid {
        array<array<PasswordSlot, PASSWORD_GRID_Y_SIZE>, PASSWORD_GRID_X_SIZE> passwordSlots;


        size_t retrieveTraversionIndex() const {

            size_t traversionIndex = 0;

            if (passwordSlots[3][0].isValueInPairGroup(1)) {
                traversionIndex += 1;
            }

            if (passwordSlots[2][0].isValueInPairGroup(1)) {
                traversionIndex += 2;
            }

            if (passwordSlots[1][2].isValueInPairGroup(1)) {
                traversionIndex += 4;
            }

            return traversionIndex;
        }

        public:
            PasswordGrid(array<array<unsigned short, PASSWORD_GRID_Y_SIZE>, PASSWORD_GRID_X_SIZE> values) {
                const PasswordSlot passwordSlot00(values[0][0], TRAVERSIONS_00, ACHIEVEMENTS_00, PAIR_GROUPS_00);
                const PasswordSlot passwordSlot10(values[1][0], TRAVERSIONS_10, ACHIEVEMENTS_10, PAIR_GROUPS_10);
                const PasswordSlot passwordSlot20(values[2][0], TRAVERSIONS_20, ACHIEVEMENTS_20, PAIR_GROUPS_20);
                const PasswordSlot passwordSlot30(values[3][0], TRAVERSIONS_30, ACHIEVEMENTS_30, PAIR_GROUPS_30);

                const PasswordSlot passwordSlot01(values[0][1], TRAVERSIONS_01, ACHIEVEMENTS_01, PAIR_GROUPS_01);
                const PasswordSlot passwordSlot11(values[1][1], TRAVERSIONS_11, ACHIEVEMENTS_11, PAIR_GROUPS_11);
                const PasswordSlot passwordSlot21(values[2][1], TRAVERSIONS_21, ACHIEVEMENTS_21, PAIR_GROUPS_21);
                const PasswordSlot passwordSlot31(values[3][1], TRAVERSIONS_31, ACHIEVEMENTS_31, PAIR_GROUPS_31);

                const PasswordSlot passwordSlot02(values[0][2], TRAVERSIONS_02, ACHIEVEMENTS_02, PAIR_GROUPS_02);
                const PasswordSlot passwordSlot12(values[1][2], TRAVERSIONS_12, ACHIEVEMENTS_12, PAIR_GROUPS_12);
                const PasswordSlot passwordSlot22(values[2][2], TRAVERSIONS_22, ACHIEVEMENTS_22, PAIR_GROUPS_22);
                const PasswordSlot passwordSlot32(values[3][2], TRAVERSIONS_32, ACHIEVEMENTS_32, PAIR_GROUPS_32);

                passwordSlots = {{
                    {{ // x: 0
                        passwordSlot00,
                        passwordSlot01,
                        passwordSlot02,
                    }},
                    {{ // x: 1
                        passwordSlot10,
                        passwordSlot11,
                        passwordSlot12,
                    }},
                    {{ // x: 2
                        passwordSlot20,
                        passwordSlot21,
                        passwordSlot22,
                    }},
                    {{ // x: 3
                        passwordSlot30,
                        passwordSlot31,
                        passwordSlot32,
                    }}
                }};
            };

            friend ostream& operator<<(ostream& ostream, const PasswordGrid& passwordGrid){
                ostream
                    << "[ " << passwordGrid.passwordSlots[0][0] << " ]" 
                    << "[ " << passwordGrid.passwordSlots[1][0] << " ]" 
                    << "[ " << passwordGrid.passwordSlots[2][0] << " ]" 
                    << "[ " << passwordGrid.passwordSlots[3][0] << " ]" 
                    << endl
                    << "[ " << passwordGrid.passwordSlots[0][1] << " ]" 
                    << "[ " << passwordGrid.passwordSlots[1][1] << " ]" 
                    << "[ " << passwordGrid.passwordSlots[2][1] << " ]" 
                    << "[ " << passwordGrid.passwordSlots[3][1] << " ]"
                    << endl
                    << "[ " << passwordGrid.passwordSlots[0][2] << " ]" 
                    << "[ " << passwordGrid.passwordSlots[1][2] << " ]" 
                    << "[ " << passwordGrid.passwordSlots[2][2] << " ]" 
                    << "[ " << passwordGrid.passwordSlots[3][2] << " ]"
                    << endl;

                return ostream;
            }

            list<Achievement> retrieveAchievements() const {

                list<Achievement> achievements;
                size_t traversionIndex = retrieveTraversionIndex();

                for(size_t yPosition = 0; yPosition < PASSWORD_GRID_Y_SIZE; yPosition++) {
                    for(size_t xPosition = 0; xPosition < PASSWORD_GRID_X_SIZE; xPosition++) {
                        list<Achievement> slotAchievements = passwordSlots[xPosition][yPosition].retrieveAchievements(traversionIndex);
                        achievements.splice(achievements.end(), slotAchievements);
                    }
                }

                return achievements;
            }
    };
}
#endif