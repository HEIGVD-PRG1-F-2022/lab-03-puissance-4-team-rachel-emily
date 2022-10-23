//
// Created by emily on 18.10.2022.
//

#ifndef PUISSANCE4_MOTEURJEUPUISSANCE4_H
#define PUISSANCE4_MOTEURJEUPUISSANCE4_H

#include <vector>
#include <string>

enum Piece {
    empty, red, yellow
};


/**
 * Vérifie si le coup est autorisé (numéro de colonne existe dans la grille ET la colonne n'est pas pleine)
 * @param gameBoard La grille de jeu
 * @param move le coup demandé par l'utilisateur à vérifier (numéro de la colonne)
 * @return true si le coup est autorisé, false sinon
 */
bool isLegalMove(std::vector<std::vector<Piece>> &gameBoard, int move);

/**
 * Vérifie s'il y a une victoire pour un pion donné (4 pions alignés)
 * @param gameBoard La grille d jeu
 * @param colour La couleur à vérifier
 * @return true s'il y a une victoire, false sinon
 */
bool hasWon(const std::vector<std::vector<Piece>> &gameBoard, Piece colour);

/**
 * compte le nombre de pion aligné pour une direction donnée à partir d'un pion de départ
 * @param gameBoard La grille de jeu
 * @param startX numéro de ligne du pion de départ
 * @param startY numéro de colonne du pion de départ
 * @param dirX la direction dans laquelle vérifier selon x
 * @param dirY la direction dans laquelle vérifier selon y
 * @return retourne true, s'il y a plus dde 4 pions alignés dans la direction donnée, false sinon
 */

bool countedFour(const std::vector<std::vector<Piece>> &gameBoard, int startX, int startY, int dirX, int dirY);


std::vector<int> getPossibleMoves(const std::vector<std::vector<Piece>> &grille);

/**
 * Calcule le coup de l'ordinateur, si un coup lui permet de gagner directement le playMove
 * sinon si l'adversaire peut gagner au prochain coup, l'en empêche,
 * sinon playMove un coup aléatoire
 * @param gameBoard La grille de jeu
 * @param colour la couleur du pion
 * @return le coup de l'ordinateur (numéro de colonne)
 */
int computerModeratelyRandomChoice(const std::vector<std::vector<Piece>> &gameBoard, Piece colour);

/**
 * Place la pièce dans la colonne donnée sur la bonne ligne
 * @param gameBoard La grille de jeu
 * @param move La colonne dans laquelle on playMove (de 0 à taille de la grille-1)
 * @param colour La couleur de la pièce à placer
 */
void playMove(std::vector<std::vector<Piece>> &gameBoard, int move, Piece colour);

/**
 * Vérifie si la grille est pleine
 * @param gameBoard La grille de jeu
 * @return true si la grille est pleine, false sinon
 */
bool isBoardFull(const std::vector<std::vector<Piece>> &gameBoard);


#endif //PUISSANCE4_MOTEURJEUPUISSANCE4_H
