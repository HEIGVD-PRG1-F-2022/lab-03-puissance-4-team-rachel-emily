/**
 * main game functions
 *
 * @name Puissance4
 * @date 23.10.2022
 * @authors Emily Baquerizo and Rachel Tranchida
 */

#include <vector>
#include <iostream>
#include "util.h"
#include "moteurJeuPuissance4.h"
#include "affichage.h"

using namespace std;

vector<vector<Piece>> askSizeAndCreateBoard() {
    int line, column;
    cout << "Entrez les dimensions de la grille de jeu : " << endl;
    while (1) {
        cout << "Nombre de lignes : ";

        askForIntAndCheck(line);

        cout << "Nombre de colonnes : ";
        askForIntAndCheck(column);
        if (column >= 4 && line >= 2 or line >= 4 && column >= 2) {
            break;
        }
        cout << "Aligner 4 pions de même couleur sur un plateau de moins de 2x4 ou 4x2 va être difficile, réessayez : "
             << endl;
    }
    vector<vector<Piece>> gameBoard(line, vector<Piece>(column, Piece::empty));
    return gameBoard;
}

void askAndPlay(vector<vector<Piece>> &gameBoard, Piece colour) {
    int move = 0;
    while (1) {
        cout << "Joueur " << ((colour == Piece::red) ? "rouge" : "jaune")
             << ", entrez le numéro de la colonne entre 0 et " << gameBoard[0].size() - 1 << " : " << endl;
        askForIntAndCheck(move);

        if (isLegalMove(gameBoard, move)) {
            break;
        }
        cout << "Coup invalide." << endl;
    }
    playMove(gameBoard, move, colour);
}

void computerPlay(vector<vector<Piece>> &gameBoard, Piece colour) {
    playMove(gameBoard, computerModeratelyRandomChoice(gameBoard, colour), colour);

}

void playGame() {
    showRules();
    int response = 0;
    cout << "Voulez vous jouer une partie avec l'ordinateur ? (0 = non, autre chiffre = oui) : ";
    askForIntAndCheck(response);
    bool ai((bool) response);
    vector<vector<Piece>> gameBoard = askSizeAndCreateBoard();
    bool firstPlayer = true;
    Piece currentPiece;
    while (1) {
        showGameBoard(gameBoard);
        if (firstPlayer) {
            currentPiece = Piece::yellow;

        } else {
            currentPiece = Piece::red;
        }
        if (ai and not(firstPlayer)) {
            computerPlay(gameBoard, currentPiece);
            cout << endl;
        } else {
            askAndPlay(gameBoard, currentPiece);
        }

        if (hasWon(gameBoard, currentPiece)) {
            showGameBoard(gameBoard);
            cout << "Joueur " << (firstPlayer ? "jaune" : "rouge") << " a gagné. " << endl;
            return;
        }
        if (isBoardFull(gameBoard)) {
            showGameBoard(gameBoard);
            cout << "Egalité" << endl;
            return;
        }
        firstPlayer = !firstPlayer;
    }
}

