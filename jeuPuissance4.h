//
// Created by rache on 21.10.2022.
//

#ifndef PUISSANCE4_JEUPUISSANCE4_H
#define PUISSANCE4_JEUPUISSANCE4_H

#include "moteurJeuPuissance4.h"
#include <vector>

/**
 * demande à l'utilisateur la taille de la grille de jeu
 * @return retourne une grille de jeu de la taille demandée
 */
std::vector<std::vector<Piece>> askSizeAndCreateBoard();

/**
 * demande le coup à l'utilisateur puis le joue
 * @param Grille Grille de jeu
 * @param colour Couleur du pion à jouer
 */
void askAndPlay(std::vector<std::vector<Piece>> &gameBoard, Piece colour);

/**
 *calcule un coup aléatoire de l'ordinateur et le playMove sur la grille
 * @param gameBoard La grille de jeu
 * @param colour La couleur du pion à placer
 */
void computerPlay(std::vector<std::vector<Piece>> &gameBoard, Piece colour);

/**
 * joue une partie entière de Puissance4 jusqu'à ce qu'il y ait une victoire ou un nul
 */
void playGame();

#endif //PUISSANCE4_JEUPUISSANCE4_H
