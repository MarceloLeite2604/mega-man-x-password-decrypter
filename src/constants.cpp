#ifndef CONSTANTS_CPP
#define CONSTANTS_CPP

#include <array>

using namespace std;

const unsigned short PASSWORD_GRID_X_SIZE = 4;
const unsigned short PASSWORD_GRID_Y_SIZE = 3;

const unsigned short PASSWORD_GROUPS_SETS = 8;

typedef array<array<unsigned short, PASSWORD_GRID_X_SIZE>, PASSWORD_GRID_Y_SIZE> passwordGrid;

#endif