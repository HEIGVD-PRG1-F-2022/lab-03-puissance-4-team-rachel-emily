//
// Created by rache on 18.10.2022.
//

#ifndef PUISSANCE4_AFFICHAGE_H
#define PUISSANCE4_AFFICHAGE_H

#include <vector>
#include <iomanip>
#include "moteurJeuPuissance4.h"

void afficheRegles();

void afficheGrille(const std::vector<std::vector<Piece>> &grille);

void setWindowsConsoleToUTF8();

void clearConsole();

#endif //PUISSANCE4_AFFICHAGE_H
