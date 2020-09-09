#include <algorithm>
#include <iostream>
#include <regex>

#include "passwordGrid.h"

using namespace std;
using namespace mmxpd;

int main(int, char**);
array<array<unsigned short, PASSWORD_GRID_Y_SIZE>, PASSWORD_GRID_X_SIZE> retrieveExamplePasswordValues();
array<array<unsigned short, PASSWORD_GRID_Y_SIZE>, PASSWORD_GRID_X_SIZE> readPasswordValuesFromArgument(char*);
smatch retrievePasswordRegexMatches(string);
PasswordGrid createPasswordGrid(int, char**);
void print(list<Achievement>);

int main(int argc, char** argv) {

    try {
        const PasswordGrid passwordGrid = createPasswordGrid(argc, argv);
        cout << passwordGrid;

        list<Achievement> achievements = passwordGrid.retrieveAchievements();

        achievements.sort();
        print(achievements);

    } catch (const std::string error) {
        cerr << error << endl;
        return 1;
    }
    
    return 0;
}

void print(list<Achievement> achievements) {
    for (Achievement achievement : achievements) {
        cout << achievement << endl;
    }
}

PasswordGrid createPasswordGrid(int argc, char** argv) {
    if (argc == 2) {
        return {readPasswordValuesFromArgument(argv[1])};
    }
    return {retrieveExamplePasswordValues()};
}

array<array<unsigned short, PASSWORD_GRID_Y_SIZE>, PASSWORD_GRID_X_SIZE> readPasswordValuesFromArgument(char* argument) {
    
    string stringArgument(argument);
    smatch regexMatches = retrievePasswordRegexMatches(stringArgument);

    array<array<unsigned short, PASSWORD_GRID_Y_SIZE>, PASSWORD_GRID_X_SIZE> values;

    size_t yPosition = 0;
    for (size_t regexMatchesIndex = 1; regexMatchesIndex < regexMatches.size(); regexMatchesIndex++) {
        unsigned long lineValues = strtoul(regexMatches[regexMatchesIndex].str().c_str(), NULL, 10);
        
        size_t xPosition = 3;
        while(lineValues > 0) {
            values[xPosition][yPosition] = lineValues % 10;
            lineValues /= 10;
            xPosition--;
        }
        yPosition++;
    }

    return values;
}

smatch retrievePasswordRegexMatches(string argument) {
    regex passwordArgumentRegex("(\\d{4})-(\\d{4})-(\\d{4})");
    
    smatch regexMatches;

    if(!regex_search(argument, regexMatches, passwordArgumentRegex) || regexMatches.size() != 4) {
        std::ostringstream errorOstream;
        errorOstream << "Invalid password \"" << argument << "\". Please inform a valid password using \"DDDD-DDDD-DDDD\" pattern.";
        throw errorOstream.str();
    }

    return regexMatches;
}

array<array<unsigned short, PASSWORD_GRID_Y_SIZE>, PASSWORD_GRID_X_SIZE> retrieveExamplePasswordValues() {
    return {{ 
        {{4, 8, 8}}, 
        {{7, 7, 7}}, 
        {{6, 8, 1}}, 
        {{4, 8, 6}} 
    }};
}