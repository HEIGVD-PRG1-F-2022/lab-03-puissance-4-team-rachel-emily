//
// Created by rache on 18.10.2022.
//
#include <iostream>

#ifdef _WIN32
#include "windows.h"
#endif
#include "affichage.h"
using namespace std;
void afficheRegles() {
    cout << "Pour commencer une partie de puissance 4, on désigne le premier joueur. Celui-ci met un de ses jetons de couleur dans l’une des colonnes de son choix. Le jeton tombe alors en bas de la colonne.\n"
            "\n"
            "Le deuxième joueur insère à son tour son jeton, de l’autre couleur dans la colonne de son choix. Et ainsi de suite jusqu'à obtenir une rangée de 4 jetons de même couleur."
            "\n" << endl;
}

void afficheGrille(const vector<vector<int>> &grille) {
    for(int i = 0; i < grille.size(); i++) {
        for(int j= 0; j < grille[i].size(); j++) {
            cout << setw(2) <<"\x1b[38;2;85;85;255m |\x1b[0m" << setw(2) << ((grille[i][j] == 1) ? "\x1b[38;2;255;255;0m o\x1b[0m" : (grille[i][j] == 2) ? "\x1b[38;2;255;0;0m o\x1b[0m" : " ");

        }
        cout << setw(2) << "\x1b[38;2;85;85;255m |\x1b[0m" << endl;
    }
}

/**
* Set Windows console format to UTF-8 to support display of colors
*/
void setWindowsConsoleToUTF8(){
#ifdef _WIN32

    system(("chcp "s + std::to_string(CP_UTF8)).c_str()); //for colored output in console

#endif
}
