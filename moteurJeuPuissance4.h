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


void demandeEtJoue(std::vector<std::vector<Piece>> &grille, Piece colour);

bool isLegalMove(std::vector<std::vector<Piece>> &grille, int coup);

bool hasWon(const std::vector<std::vector<Piece>> &grille, Piece colour);

bool count(const std::vector<std::vector<Piece>> &grille, int ligneDepart, int colonneDepart, int dirX, int dirY);

void joue(std::vector<std::vector<Piece>> &grille, int coup, Piece colour);

bool isBoardFull(const std::vector<std::vector<Piece>> &grille);

void askUserAndCheck(int &numberToFill, std::string errorMessage = "Entrée invalide, réessayez : ");

#endif //PUISSANCE4_MOTEURJEUPUISSANCE4_H
