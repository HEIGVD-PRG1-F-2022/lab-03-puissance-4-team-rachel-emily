//
// Created by rache on 21.10.2022.
//
#include <iostream>

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
    return (rand() % maxValue);
}

void setWindowsConsoleToUTF8() {
#ifdef _WIN32

    system(("chcp "s + std::to_string(CP_UTF8)).c_str()); //for colored output in console

#endif
}


/**
 * Clear console with system cmd based on if it's a Windows or a UNIX system
 */
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}



