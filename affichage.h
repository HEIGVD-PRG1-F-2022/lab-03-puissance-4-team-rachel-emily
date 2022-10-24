/**
 * Display related functions
 *
 * @name Puissance4
 * @date 23.10.2022
 * @authors Emily Baquerizo and Rachel Tranchida
 */


#ifndef PUISSANCE4_AFFICHAGE_H
#define PUISSANCE4_AFFICHAGE_H

#include <vector>
#include "moteurJeuPuissance4.h"

/**
 * affiche les règles du jeu et comment jouer avec ce programme
 */
void showRules();

/**
 * affiche la grille de jeu
 * @param gameBoard grille à afficher
 */
void showGameBoard(const std::vector<std::vector<Piece>> &gameBoard);


#endif //PUISSANCE4_AFFICHAGE_H
