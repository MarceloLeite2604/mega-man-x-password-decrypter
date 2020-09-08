#ifndef PASSWORD_VALUES_CPP
#define PASSWORD_VALUES_CPP

#include <ostream>
#include "newConstants.cpp"

namespace mmxpd {

    using namespace std;

    class PasswordValues {

        array<array<unsigned short, PASSWORD_GRID_Y_SIZE>, PASSWORD_GRID_X_SIZE> values;

        public:
            PasswordValues(array<array<unsigned short, PASSWORD_GRID_Y_SIZE>, PASSWORD_GRID_X_SIZE> values) {
                this->values = values;
            }

            friend ostream& operator<<(ostream& ostream, const PasswordValues& passwordValues){
                ostream
                    << "[ " << passwordValues.values[0][0] << " ]" 
                    << "[ " << passwordValues.values[1][0] << " ]" 
                    << "[ " << passwordValues.values[2][0] << " ]" 
                    << "[ " << passwordValues.values[3][0] << " ]" 
                    << endl
                    << "[ " << passwordValues.values[0][1] << " ]" 
                    << "[ " << passwordValues.values[1][1] << " ]" 
                    << "[ " << passwordValues.values[2][1] << " ]" 
                    << "[ " << passwordValues.values[3][1] << " ]"
                    << endl
                    << "[ " << passwordValues.values[0][2] << " ]" 
                    << "[ " << passwordValues.values[1][2] << " ]" 
                    << "[ " << passwordValues.values[2][2] << " ]" 
                    << "[ " << passwordValues.values[3][2] << " ]"
                    << endl;
                return ostream;
            }
    };
}

#endif