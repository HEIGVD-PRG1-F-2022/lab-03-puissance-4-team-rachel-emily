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
 * demande le coup à l'utilisateur puis le joue
 * @param Grille Grille de jeu
 * @param colour Couleur du pion à jouer
 */
void demandeEtJoue(std::vector<std::vector<Piece>> &grille, Piece colour);

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
 * @return retourne true, s'il y a 4 pion aligné dans la direction donnée, false sinon
 */

bool countedFour(const std::vector<std::vector<Piece>> &grille, int ligneDepart, int colonneDepart, int dirX, int dirY);

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

/**
 * Fonction utilitaire, permet de demander un int à l'utilisateur jusqu'à ce qu'il entre bien un int
 * @param numberToFill la variable qui doit contenir la réponse de l'utilisateur
 * @param errorMessage le message d'erreur à donner à l'utilisateur (avec valeur par défaut)
 */
void askForIntAndCheck(int &numberToFill, std::string errorMessage = "Entrée invalide, réessayez : ");

/**
 * Calcule un coup aléatoire pour l'ordinateur
 * @param grille La grille de jeu
 * @return Retourne le coup de l'ordinateur
 */
int computerRandomChoice(const std::vector<std::vector<Piece>> &grille);

/**
 *
 * @param grille
 * @param colour
 */
void ordinateurJoue(std::vector<std::vector<Piece>> &grille, Piece colour);

#endif //PUISSANCE4_MOTEURJEUPUISSANCE4_H