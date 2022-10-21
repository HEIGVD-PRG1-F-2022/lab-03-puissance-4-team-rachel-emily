//
// Created by rache on 18.10.2022.
//
#include <iostream>


#include "affichage.h"
#include "util.h"

using namespace std;

void afficheRegles() {
    cout
            << "Pour commencer une partie de puissance 4, on désigne le premier joueur. Celui-ci met un de ses jetons de couleur dans l’une des colonnes de son choix. Le jeton tombe alors en bas de la colonne."
            << endl <<
            "Le deuxième joueur insère à son tour son jeton, de l’autre couleur dans la colonne de son choix. Et ainsi de suite jusqu'à obtenir une ligne, colonne, ou diagonale de 4 jetons de même couleur."
            << endl <<
            "Pour cette version, chaque joueur, choisit la colonne dans laquelle il veut jouer en donnant le numéro de colonne (débute en colonne 0),"
            << endl << endl;

}

void afficheGrille(const vector<vector<Piece>> &grille) {
    clearConsole();
    for (int i = 0; i < grille.size(); i++) {
        for (int j = 0; j < grille[i].size(); j++) {
            cout << setw(2) << "\x1b[38;2;85;85;255m |\x1b[0m" << setw(2)
                 << ((grille[i][j] == Piece::red) ? "\x1b[38;2;255;0;0m o\x1b[0m" : (grille[i][j] == Piece::yellow)
                                                                                    ? "\x1b[38;2;255;255;0m o\x1b[0m"
                                                                                    : " ");

        }
        cout << setw(2) << "\x1b[38;2;85;85;255m |\x1b[0m" << endl;
    }
}


