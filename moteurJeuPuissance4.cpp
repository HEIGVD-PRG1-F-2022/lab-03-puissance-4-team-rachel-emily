//
// Created by emily on 18.10.2022.
//
#include "moteurJeuPuissance4.h"
#include "util.h"

using namespace std;
const int MAX_SCORE = 1000;
const int LOWEST_SCORE = -1000;
const int MAX_DEEP = 3;

bool isLegalMove(vector<vector<Piece>> &grille, int coup) {
    if ((coup >= 0 && coup <= grille.size()) && (grille[0][coup] == Piece::empty)) {
        return true;
    }
    return false;
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
                    ||
                    isInNegYRange && isInPosXRange && countedFour(grille, x, y, 1, -1)) { //diagonale de droite à gauche
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

bool countedFour2(const vector<vector<Piece>> &grille, int ligneDepart, int colonneDepart, int dirX, int dirY) {
    int result = 0;
    int ligne(ligneDepart);
    int colonne(colonneDepart);

    while (grille[ligne][colonne] == grille[ligneDepart][colonneDepart]) {
        ++result;
        ligne += dirX;
        colonne += dirY;

    }
    return result;
}


bool isBoardFull(const vector<vector<Piece>> &grille) {
    for (int y = 0; y < grille[0].size(); y++) {
        if (grille[0][y] == Piece::empty) {
            return false;
        }
    }
    return true;
}

int minmax(vector<vector<Piece>> grille, Piece colour) {
    static int deepness = 1;
    vector<int> possibleMoves = getPossibleMoves(grille);
    for (auto i: possibleMoves) {
        joue(grille, i, colour);
        bool somebodyWon = hasWon(grille, colour);
        if (somebodyWon and deepness % 2 == 0) {
            deepness = 1;
            return MAX_SCORE;
        } else if (somebodyWon and deepness % 2 == 1) {
            deepness = 1;
            return LOWEST_SCORE;
        }
    }
    if (MAX_DEEP > deepness) {
        ++deepness;
        return minmax(grille, ((colour == Piece::red) ? Piece::yellow : Piece::red));
    } else {
        deepness = 1;
    }
    return 0;
}

vector<int> getPossibleMoves(const vector<vector<Piece>> &grille) {
    vector<int> notFullColumns;
    for (int y = 0; y < grille[0].size(); y++) {
        if (grille[0][y] == Piece::empty) {
            notFullColumns.push_back(y);
        }
    }
    return notFullColumns;
}

int computerModeratelyRandomChoice(const vector<vector<Piece>> &grille, Piece colour) {

    vector<int> possibleMoves = getPossibleMoves(grille);
    for (auto i: possibleMoves) {
        vector<vector<Piece>> grilleEval(grille); //copie la grille de base
        joue(grilleEval, i, colour); // joue le coup sur la copie
        if (hasWon(grilleEval, colour)) { // si le coup joué résulte en une victoire, retourne ce coup
            return i;
        }
    }
    //si l'ordinateur ne peut pas jouer au prochain coup, regarde si l'adversaire peut gagner en un coup
    for (auto j: possibleMoves) {
        vector<vector<Piece>> grilleEval2(grille); //copie la grille de base
        Piece newColour = ((colour == Piece::red) ? Piece::yellow : Piece::red); //on trouve la couleur de l'adversaire
        joue(grilleEval2, j, newColour); // joue le coup sur la copie
        if (hasWon(grilleEval2, newColour)) { // si le coup joué résulte en une victoire
            //retourne le coup, l'ordinateur joue ici pour empêcher à l'adversaire de jouer là après
            return j;
        }
    }
    //si on ne peut pas gagner tout de suite ou l'adversaire le coup d'après
    //on calcule un coup aléatoire
    return possibleMoves[randomInt(possibleMoves.size() - 1)];

}