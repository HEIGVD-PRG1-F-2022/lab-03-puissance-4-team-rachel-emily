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
std::vector<std::vector<Piece>> demandeTailleEtCreeGrille();

/**
 * demande le coup à l'utilisateur puis le joue
 * @param Grille Grille de jeu
 * @param colour Couleur du pion à jouer
 */
void demandeEtJoue(std::vector<std::vector<Piece>> &grille, Piece colour);

/**
 *calcule un coup aléatoire de l'ordinateur et le joue sur la grille
 * @param grille La grille de jeu
 * @param colour La couleur du pion à placer
 */
void ordinateurJoue(std::vector<std::vector<Piece>> &grille, Piece colour);

/**
 * joue une partie entière de Puissance4 jusqu'à ce qu'il y ait une victoire ou un nul
 */
void joueUnePartie();

#endif //PUISSANCE4_JEUPUISSANCE4_H
