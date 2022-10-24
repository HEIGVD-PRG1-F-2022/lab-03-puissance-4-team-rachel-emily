/**
 * useful functions not specifically related to the game
 *
 * @name Puissance4
 * @date 21.10.2022
 * @authors Emily Baquerizo and Rachel Tranchida
 */

#include <iostream>
#include <limits>

#ifdef _WIN32

#include "windows.h"

#endif
using namespace std;

void askForIntAndCheck(int &numberToFill, string errorMessage) {
    while (not(cin >> numberToFill)) {
        cout << errorMessage;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int randomInt(int maxValue) {
    srand(time(0));
    if (maxValue != 0) {
        return (rand() % maxValue);
    }
    return 0;
}

void setWindowsConsoleToUTF8() {
#ifdef _WIN32

    system(("chcp "s + std::to_string(CP_UTF8)).c_str()); //for colored output in console

#endif
}


/**
 * Clear console with system cmd based on if it's a Windows or a UNIX system
 */




