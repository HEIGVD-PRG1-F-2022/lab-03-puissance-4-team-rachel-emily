//
// Created by rache on 18.10.2022.
//

#ifndef PUISSANCE4_AFFICHAGE_H
#define PUISSANCE4_AFFICHAGE_H
#include <vector>
#include <iomanip>
#ifdef _WIN32
#include "windows.h"
#endif
void afficheRegles();
void afficheGrille(const std::vector<std::vector<int>>& grille);
#endif //PUISSANCE4_AFFICHAGE_H
