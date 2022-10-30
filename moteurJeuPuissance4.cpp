/**
 * functions used to compute the game Puissance4
 *
 * @name Puissance4
 * @date 23.10.2022
 * @authors Emily Baquerizo and Rachel Tranchida
 */

#include "moteurJeuPuissance4.h"
#include "util.h"

using namespace std;

bool isLegalMove(vector<vector<Piece>> &gameBoard, int move) {
    if ((move >= 0 && move < gameBoard[0].size()) && (gameBoard[0][move] == Piece::empty)) {
        return true;
    }
    return false;
}


void playMove(vector<vector<Piece>> &gameBoard, int move, Piece colour) {

    for (int i = gameBoard.size() - 1; i >= 0; i--) {
        if (gameBoard[i][move] == Piece::empty) {
            gameBoard[i][move] = colour;
            break;
        }
    }
}


bool hasWon(const vector<vector<Piece>> &gameBoard, Piece colour) {
    for (int x = 0; x < gameBoard.size(); x++) {
        for (int y = 0; y < gameBoard[x].size(); y++) {
            if (gameBoard[x][y] == colour) { //on vérifie seulement si c'est la couleur que l'on veut vérifier
                //pour s'assurer qu'il reste au moins 4 colonnes dans une direction
                bool isInPosYRange = (y + 4 <= gameBoard[x].size());
                bool isInPosXRange = (x + 4 <= gameBoard.size());
                bool isInNegYRange = (y - 3 >= 0);

                if (isInPosYRange && countedFour(gameBoard, x, y, 0, 1) //dans la ligne
                    ||
                    isInPosYRange && isInPosXRange && countedFour(gameBoard, x, y, 1, 1) //diagonale de gauche à droite
                    || isInPosXRange && countedFour(gameBoard, x, y, 1, 0) //colonne de haut en bas
                    ||
                    isInNegYRange && isInPosXRange &&
                    countedFour(gameBoard, x, y, 1, -1)) { //diagonale de droite à gauche
                    return true;
                }
            }
        }
    }
    return false;
}


bool countedFour(const vector<vector<Piece>> &gameBoard, int startX, int startY, int dirX, int dirY) {
    int result = 0;
    int line(startX);
    int column(startY);

    while (gameBoard[line][column] == gameBoard[startX][startY]) {
        ++result;
        line += dirX;
        column += dirY;
        if (result >= 4) {
            return true;
        }
    }
    return false;
}


bool isBoardFull(const vector<vector<Piece>> &gameBoard) {
    for (int y = 0; y < gameBoard[0].size(); y++) {
        if (gameBoard[0][y] == Piece::empty) {
            return false;
        }
    }
    return true;
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

int computerModeratelyRandomChoice(const vector<vector<Piece>> &gameBoard, Piece colour) {

    vector<int> possibleMoves = getPossibleMoves(gameBoard);
    for (auto i: possibleMoves) {
        vector<vector<Piece>> gameBoardCopy(gameBoard); //copie la grille de base
        playMove(gameBoardCopy, i, colour); // joue le coup sur la copie
        if (hasWon(gameBoardCopy, colour)) { // si le coup joué résulte en une victoire, retourne ce coup
            return i;
        }
    }
    //si l'ordinateur ne peut pas jouer au prochain coup, regarde si l'adversaire peut gagner en un coup
    for (auto j: possibleMoves) {
        vector<vector<Piece>> gameBoardCopy(gameBoard); //copie la grille de base
        Piece newColour = ((colour == Piece::red) ? Piece::yellow : Piece::red); //on trouve la couleur de l'adversaire
        playMove(gameBoardCopy, j, newColour); // joue le coup sur la copie
        if (hasWon(gameBoardCopy, newColour)) { // si le coup joué résulte en une victoire
            //retourne le coup, l'ordinateur joue ici pour empêcher à l'adversaire de jouer là après
            return j;
        }
    }
    //si on ne peut pas gagner tout de suite ou l'adversaire le coup d'après
    //on calcule un coup aléatoire
    return possibleMoves[randomInt(possibleMoves.size() - 1)];

}