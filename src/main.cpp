#include <algorithm>
#include <iostream>
#include "constants.cpp"
#include "factorGroups.cpp"
#include "traversions.cpp"
#include "achievements.cpp"

using namespace std;

int main(int, char**);
unsigned short retrieveFactorGroupIndex(unsigned short, unsigned short, unsigned short);
passwordGrid retrievePasswordGrid();
unsigned short retrieveTraverseSetIndex(passwordGrid);
bool factorSetContains(factorSet, unsigned short);
bool checkPositionValueIsInFactorSet(passwordGrid, unsigned short, unsigned short, unsigned short);
factorSet traverseFactorSet(factorSet, unsigned short);
bool valueIsIn(values, unsigned short);
void printMatchingGroups(factorSet);
void checkAchievementsDone(bool[Achievements::_SIZE]);

int main(int argc, char** argv) {

    bool achievementsDone[Achievements::_SIZE];

    const passwordGrid passwordGrid = retrievePasswordGrid();
    const unsigned short traverseSetIndex = retrieveTraverseSetIndex(passwordGrid);
    const traversionPositions traversionPositions = TRAVERSIONS_SET[traverseSetIndex];

    for(size_t yPosition = 0; yPosition < PASSWORD_GRID_Y_SIZE; yPosition++) {
        for(size_t xPosition = 0; xPosition < PASSWORD_GRID_X_SIZE; xPosition++) {
            const unsigned short value = passwordGrid[yPosition][xPosition];
            
            const unsigned short factorGroupIndex = retrieveFactorGroupIndex(traverseSetIndex, xPosition, yPosition);
            const factorSet selectedFactorSet = POSITIONS_FACTORS_GROUPS[yPosition][xPosition][factorGroupIndex];
            const unsigned short traversion = traversionPositions[yPosition][xPosition];
            const factorSet matchingGroups = traverseFactorSet(selectedFactorSet, traversion);

            printMatchingGroups(matchingGroups);

            if (valueIsIn(matchingGroups[AchievementsRealized::NONE], value)) {
                achievementsDone[ACHIEVEMENTS_POSITIONS[yPosition][xPosition][0]] = false;
                achievementsDone[ACHIEVEMENTS_POSITIONS[yPosition][xPosition][1]] = false;
            } else if (valueIsIn(matchingGroups[AchievementsRealized::FIRST], value)) {
                achievementsDone[ACHIEVEMENTS_POSITIONS[yPosition][xPosition][0]] = true;
                achievementsDone[ACHIEVEMENTS_POSITIONS[yPosition][xPosition][1]] = false;
            } else if (valueIsIn(matchingGroups[AchievementsRealized::SECOND], value)) {
                achievementsDone[ACHIEVEMENTS_POSITIONS[yPosition][xPosition][0]] = false;
                achievementsDone[ACHIEVEMENTS_POSITIONS[yPosition][xPosition][1]] = true;
            } else if (valueIsIn(matchingGroups[AchievementsRealized::BOTH], value)) {
                achievementsDone[ACHIEVEMENTS_POSITIONS[yPosition][xPosition][0]] = true;
                achievementsDone[ACHIEVEMENTS_POSITIONS[yPosition][xPosition][1]] = true;
            } else {
                cerr << "Something wrong happened while checking position ("<< xPosition <<", " << yPosition << ")." << endl;
                return 1;
            }
        }
    }
    checkAchievementsDone(achievementsDone);
    return 0;
}

unsigned short retrieveFactorGroupIndex(unsigned short traverseSetIndex, unsigned short xPosition, unsigned short yPosition) {
    unsigned short factorGroupIndex = 0;
    if ( xPosition == 2 && yPosition == 0 ) {
        factorGroupIndex = ((traverseSetIndex & 0x02) >>1);
    } else if ( xPosition == 3 && yPosition == 0 ) {
        factorGroupIndex = (traverseSetIndex & 0x01); 
    } else if ( xPosition == 1 && yPosition == 2 ) {
        factorGroupIndex = ((traverseSetIndex & 0x04) >>2);
    }
    return factorGroupIndex;
}

passwordGrid retrievePasswordGrid() {

    return (passwordGrid)
    {{
        {2, 6, 5, 6},
        {6, 4, 8, 8},
        {3, 2, 4, 8}
    }};
}

unsigned short retrieveTraverseSetIndex(passwordGrid passwordGrid) {

    unsigned short b0 = 0, b1 = 0, b2 = 0;

    if (checkPositionValueIsInFactorSet(passwordGrid, 3,0,1)) {
        b0 = 1;
    }

    if (checkPositionValueIsInFactorSet(passwordGrid, 2,0,1)) {
        b1 = 2;
    }

    if (checkPositionValueIsInFactorSet(passwordGrid, 1,2,1)) {
        b2 = 4;
    }

    return b0 + b1 + b2;
}

bool checkPositionValueIsInFactorSet(passwordGrid passwordGrid, unsigned short xPosition, unsigned short yPosition, unsigned short factorGroup) {
    
    const unsigned short positionValue = passwordGrid[yPosition][xPosition];
    const factorSet factorSet = POSITIONS_FACTORS_GROUPS[yPosition][xPosition][factorGroup];
    return factorSetContains(factorSet, positionValue);
}

bool factorSetContains(factorSet factorSet, unsigned short checkedValue) {
    for(unsigned short factorSetIndex = 0; factorSetIndex < factorSet.size(); factorSetIndex++) {
        values values = factorSet[factorSetIndex];
        for (unsigned short valuesIndex = 0; valuesIndex < values.size(); valuesIndex++) {
            if (values[valuesIndex] != 0 && values[valuesIndex] == checkedValue) {
                return true;
            }
        }
    }
    
    return false;
}

factorSet traverseFactorSet(factorSet factorSetToTraverse, unsigned short traversion) {

    factorSet resultFactorSet = factorSetToTraverse;
    
    switch (traversion) {
        case Traversion::FORWARD:
            break;
        case Traversion::BACKWARD:
            std::reverse(resultFactorSet.begin(), resultFactorSet.end());
            break;
        case Traversion::LEFT_SHIFT_ROTATE_TWICE_FORWARD:
            std::rotate(resultFactorSet.begin(), resultFactorSet.begin()+2, resultFactorSet.end());
            break;
        case Traversion::LEFT_SHIFT_ROTATE_TWICE_BACKWARD:
            std::rotate(resultFactorSet.begin(), resultFactorSet.begin()+2, resultFactorSet.end());
            std::reverse(resultFactorSet.begin(), resultFactorSet.end());
            break;
    }

    return resultFactorSet;
}

bool valueIsIn(values values, unsigned short value) {
    return (std::count(values.begin(), values.end(), value) > 0);
}


void printMatchingGroups(factorSet factorSet) {
    cout << "Matching groups are : ";
    for(size_t factorSetIndex = 0; factorSetIndex < factorSet.size(); factorSetIndex++) {
        values values = factorSet[factorSetIndex];
        cout << "[" << values[0] << ", " << values[1] << "] ";
    }   
    cout << endl;
}

/*
void checkAchievementsDone(bool achievementsDone[Achievements::_SIZE] ) {
    if (achievementsDone[DEFEATED_ARMORED_ARMADILLO]) {
        cout << "Player has defeated Armored Armadillo." << endl;        
    }
    if (achievementsDone[DEFEATED_BOOMER_KWANGER]) {
        cout << "Player has defeated Boomer Kwanger." << endl;        
    }
    if (achievementsDone[DEFEATED_CHILL_PENGUIN]) {
        cout << "Player has defeated Chill Penguin." << endl;        
    }
    if (achievementsDone[DEFEATED_LAUNCH_OCTOPUS]) {
        cout << "Player has defeated Launch Octopus." << endl;        
    }
    if (achievementsDone[DEFEATED_SPARK_MANDRILL]) {
        cout << "Player has defeated Spark Mandrill." << endl;        
    }
    if (achievementsDone[DEFEATED_STING_CHAMELEON]) {
        cout << "Player has defeated Sting Chameleon." << endl;        
    }
    if (achievementsDone[DEFEATED_STORM_EAGLE]) {
        cout << "Player has defeated Storm Eagle." << endl;        
    }
    if (achievementsDone[DEFEATED_FLAME_MAMMOTH]) {
        cout << "Player has defeated Flame Mammoth." << endl;        
    }

    if (achievementsDone[ACQUIRED_HEART_TANK_ARMORED_ARMADILLO_STAGE]) {
        cout << "Player has acquired heart tank on Armored Armadillo stage." << endl;
    }
    if (achievementsDone[ACQUIRED_HEART_TANK_BOOMER_KWANGER_STAGE]) {
        cout << "Player has acquired heart tank on Boomer Kwanger stage." << endl;
    }
    if (achievementsDone[ACQUIRED_HEART_TANK_CHILL_PENGUIN_STAGE]) {
        cout << "Player has acquired heart tank on Chill Penguin stage." << endl;
    }
    if (achievementsDone[ACQUIRED_HEART_TANK_LAUNCH_OCTOPUS_STAGE]) {
        cout << "Player has acquired heart tank on Launch Octopus stage." << endl;
    }
    if (achievementsDone[ACQUIRED_HEART_TANK_SPARK_MANDRILL_STAGE]) {
        cout << "Player has acquired heart tank on Spark Mandrill stage." << endl;
    }
    if (achievementsDone[ACQUIRED_HEART_TANK_STING_CHAMELEON_STAGE]) {
        cout << "Player has acquired heart tank on Sting Chameleon stage." << endl;
    }
    if (achievementsDone[ACQUIRED_HEART_TANK_STORM_EAGLE_STAGE]) {
        cout << "Player has acquired heart tank on Storm Eagle stage." << endl;
    }
    if (achievementsDone[ACQUIRED_HEART_TANK_FLAME_MAMMOTH_STAGE]) {
        cout << "Player has acquired heart tank on Flame Mammoth stage." << endl;
    }
    if (achievementsDone[ACQUIRED_SUB_TANK_ARMORED_ARMADILLO_STAGE]) {
        cout << "Player has acquired sub tank on Armored Armadillo stage." << endl;
    }

    if (achievementsDone[ACQUIRED_SUB_TANK_SPARK_MANDRILL_STAGE]) {
        cout << "Player has acquired sub tank on Spark Mandrill stage." << endl;
    }
    if (achievementsDone[ACQUIRED_SUB_TANK_STORM_EAGLE_STAGE]) {
        cout << "Player has acquired sub tank on Storm Eagle stage." << endl;
    }
    if (achievementsDone[ACQUIRED_SUB_TANK_FLAME_MAMMOTH_STAGE]) {
        cout << "Player has acquired sub tank on Flame Mammoth stage." << endl;
    }

    if (achievementsDone[ACQUIRED_BOOTS]) {
        cout << "Player has acquired boots." << endl;
    }
    if (achievementsDone[ACQUIRED_ARMOR]) {
        cout << "Player has acquired armor." << endl;
    }
    if (achievementsDone[ACQUIRED_MEGA_BUSTER]) {
        cout << "Player has acquired mega buster." << endl;
    }
    if (achievementsDone[ACQUIRED_HELMET]) {
        cout << "Player has acquired helmet." << endl;
    }
}
*/