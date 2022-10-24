/**
 * Display related functions
 *
 * @name Puissance4
 * @date 23.10.2022
 * @authors Emily Baquerizo and Rachel Tranchida
 */

#include <iostream>
#include <iomanip>
#include "affichage.h"

using namespace std;

void showRules() {
    cout
            << "Pour commencer une partie de puissance 4, on désigne le premier joueur. Celui-ci met un de ses jetons de couleur dans l’une des colonnes de son choix. Le jeton tombe alors en bas de la colonne."
            << endl <<
            "Le deuxième joueur insère à son tour son jeton, de l’autre couleur dans la colonne de son choix. Et ainsi de suite jusqu'à obtenir une ligne, colonne, ou diagonale de 4 jetons de même couleur."
            << endl <<
            "Pour cette version, chaque joueur, choisit la colonne dans laquelle il veut jouer en donnant le numéro de colonne (débute en colonne 0),"
            << endl << endl;

}

void showGameBoard(const vector<vector<Piece>> &gameBoard) {
    for (const auto &i: gameBoard) {
        for (auto j: i) {
            cout << setw(2) << "\x1b[38;2;85;85;255m |\x1b[0m" << setw(2)
                 << ((j == Piece::red) ? "\x1b[38;2;255;0;0m o\x1b[0m" : (j == Piece::yellow)
                                                                         ? "\x1b[38;2;255;255;0m o\x1b[0m"
                                                                         : " ");

        }
        cout << setw(2) << "\x1b[38;2;85;85;255m |\x1b[0m" << endl;
    }
}


