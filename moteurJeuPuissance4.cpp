//
// Created by emily on 18.10.2022.
//
#include "moteurJeuPuissance4.h"
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;


bool isLegalMove(vector<vector<Piece>> &grille, int coup) {
    if ((coup >= 0 && coup <= grille.size()) && (grille[0][coup] == Piece::empty)) {
        return true;
    }
    return false;
}


void demandeEtJoue(vector<vector<Piece>> &grille, Piece colour) {
    int coup = 0;
    while (1) {
        cout << "Entrez le numéro de la colonne entre 0 et " << grille[0].size() - 1 << " : " << endl;
        askForIntAndCheck(coup);

        if (isLegalMove(grille, coup)) {
            break;
        }
        cout << "Coup invalide." << endl;
    }
    joue(grille, coup, colour);
}


void joue(vector<vector<Piece>> &grille, int coup, Piece colour) {

    for (int i = grille.size() - 1; i >= 0; i--) {
        if (grille[i][coup] == Piece::empty) {
            grille[i][coup] = colour;
            break;
        }
    }
}


bool hasWon(const vector<vector<Piece>> &grille, Piece colour) {
    for (int x = 0; x < grille.size(); x++) {
        for (int y = 0; y < grille[x].size(); y++) {
            if (grille[x][y] == colour) { //on vérifie seulement si c'est la couleur que l'on veut vérifier
                //pour s'assurer qu'il reste au moins 4 colonnes dans une direction
                bool isInPosYRange = (y + 4 <= grille[x].size());
                bool isInPosXRange = (x + 4 <= grille.size());
                bool isInNegYRange = (y - 3 >= 0);

                if (isInPosYRange && countedFour(grille, x, y, 0, 1) //dans la ligne
                    || isInPosYRange && isInPosXRange && countedFour(grille, x, y, 1, 1) //diagonale de gauche à droite
                    || isInPosXRange && countedFour(grille, x, y, 1, 0) //colonne de haut en bas
                    || isInNegYRange && countedFour(grille, x, y, -1, 1)) { //diagonale de droite à gauche
                    return true;
                }
            }
        }
    }
    return false;
}


bool countedFour(const vector<vector<Piece>> &grille, int ligneDepart, int colonneDepart, int dirX, int dirY) {
    int result = 0;
    int ligne(ligneDepart);
    int colonne(colonneDepart);

    while (grille[ligne][colonne] == grille[ligneDepart][colonneDepart]) {
        ++result;
        ligne += dirX;
        colonne += dirY;
        if (result >= 4) {
            return true;
        }
    }
    return false;
}


bool isBoardFull(const vector<vector<Piece>> &grille) {
    for (int y = 0; y < grille[0].size(); y++) {
        if (grille[0][y] == Piece::empty) {
            return false;
        }
    }
    return true;
}


void askForIntAndCheck(int &numberToFill, string errorMessage) {
    while (not(cin >> numberToFill)) {
        cout << errorMessage;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int computerRandomChoice(const vector<vector<Piece>> &grille) {
    vector<int> notFullColumns;
    for (int y = 0; y < grille[0].size(); y++) {
        if (grille[0][y] == Piece::empty) {
            notFullColumns.push_back(y);
        }
    }
    srand(time(0));
    return notFullColumns[(rand() % (notFullColumns.size() - 1))];
}

void ordinateurJoue(vector<vector<Piece>> &grille, Piece colour) {
    joue(grille, computerRandomChoice(grille), colour);

}