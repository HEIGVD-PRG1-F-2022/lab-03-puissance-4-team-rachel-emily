//
// Created by rache on 18.10.2022.
//

#ifndef PUISSANCE4_AFFICHAGE_H
#define PUISSANCE4_AFFICHAGE_H

#include <vector>
#include <iomanip>
#include "moteurJeuPuissance4.h"

/**
 * affiche les règles du jeu et comment jouer avec ce programme
 */
void afficheRegles();

/**
 * affiche la grille de jeu
 * @param grille grille à afficher
 */
void afficheGrille(const std::vector<std::vector<Piece>> &grille);


#endif //PUISSANCE4_AFFICHAGE_H
