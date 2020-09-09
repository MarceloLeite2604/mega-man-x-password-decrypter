#ifndef PASSWORD_GRID_H
#define PASSWORD_GRID_H

#include <list>

#include "constants.h"
#include "passwordSlot.h"

namespace mmxpd {
    
    class PasswordGrid {
        private:

        std::array<std::array<PasswordSlot, PASSWORD_GRID_Y_SIZE>, PASSWORD_GRID_X_SIZE> passwordSlots;
        size_t retrieveTraversionIndex() const;

        public:

        PasswordGrid(std::array<std::array<unsigned short, PASSWORD_GRID_Y_SIZE>, PASSWORD_GRID_X_SIZE>);
        friend std::ostream& operator<<(std::ostream&, const PasswordGrid&);
        std::list<Achievement> retrieveAchievements() const;
    };
}
#endif