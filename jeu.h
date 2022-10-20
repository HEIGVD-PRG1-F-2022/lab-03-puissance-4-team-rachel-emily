//
// Created by emily on 18.10.2022.
//

#ifndef PUISSANCE4_JEU_H
#define PUISSANCE4_JEU_H

#include <vector>

enum Piece {
    empty, red, yellow
};

int demandePlacement();

void demandeEtJoue(std::vector<std::vector<Piece>> &grille, Piece colour);

bool isLegalMove(std::vector<std::vector<Piece>> &grille, int coup);

bool hasWon(const std::vector<std::vector<Piece>> &grille, Piece colour);

bool count(const std::vector<std::vector<Piece>> &grille, int ligneDepart, int colonneDepart, bool dirX, bool dirY);

void joue(std::vector<std::vector<Piece>> &grille, int coup, Piece colour);

bool isBoardFull(const std::vector<std::vector<Piece>> &grille);

void joueUnePartie();

#endif //PUISSANCE4_JEU_H
