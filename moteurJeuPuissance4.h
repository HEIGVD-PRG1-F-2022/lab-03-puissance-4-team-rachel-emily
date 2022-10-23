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
 * @param grille La grille de jeu
 * @param coup le coup demandé par l'utilisateur à vérifier (numéro de la colonne)
 * @return true si le coup est autorisé, false sinon
 */
bool isLegalMove(std::vector<std::vector<Piece>> &grille, int coup);

/**
 * Vérifie s'il y a une victoire pour un pion donné (4 pions alignés)
 * @param grille La grille d jeu
 * @param colour La couleur à vérifier
 * @return true s'il y a une victoire, false sinon
 */
bool hasWon(const std::vector<std::vector<Piece>> &grille, Piece colour);

/**
 * compte le nombre de pion aligné pour une direction donnée à partir d'un pion de départ
 * @param grille La grille de jeu
 * @param ligneDepart numéro de ligne du pion de départ
 * @param colonneDepart numéro de colonne du pion de départ
 * @param dirX la direction dans laquelle vérifier selon x
 * @param dirY la direction dans laquelle vérifier selon y
 * @return retourne true, s'il y a plus dde 4 pions alignés dans la direction donnée, false sinon
 */

bool countedFour(const std::vector<std::vector<Piece>> &grille, int ligneDepart, int colonneDepart, int dirX, int dirY);


std::vector<int> getPossibleMoves(const std::vector<std::vector<Piece>> &grille);

/**
 * Calcule le coup de l'ordinateur, si un coup lui permet de gagner directement le joue
 * sinon si l'adversaire peut gagner au prochain coup, l'en empêche,
 * sinon joue un coup aléatoire
 * @param grille La grille de jeu
 * @param colour la couleur du pion
 * @return le coup de l'ordinateur (numéro de colonne)
 */
int computerModeratelyRandomChoice(const std::vector<std::vector<Piece>> &grille, Piece colour);

/**
 * Place la pièce dans la colonne donnée sur la bonne ligne
 * @param grille La grille de jeu
 * @param coup La colonne dans laquelle on joue (de 0 à taille de la grille-1)
 * @param colour La couleur de la pièce à placer
 */
void joue(std::vector<std::vector<Piece>> &grille, int coup, Piece colour);

/**
 * Vérifie si la grille est pleine
 * @param grille La grille de jeu
 * @return true si la grille est pleine, false sinon
 */
bool isBoardFull(const std::vector<std::vector<Piece>> &grille);


#endif //PUISSANCE4_MOTEURJEUPUISSANCE4_H
