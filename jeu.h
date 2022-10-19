//
// Created by emily on 18.10.2022.
//

#ifndef PUISSANCE4_JEU_H
#define PUISSANCE4_JEU_H
#include <vector>
enum Pion {Vide, Rouge, Jaune};
int demandePlacement();
bool isColumnFull();
void demandeEtJoue(std::vector<std::vector<int>>& grille, bool joueur);
bool isLegalMove(std::vector<std::vector<int>>& grille, int coup);
void demandeJouer(std::vector<std::vector<int>>& grille);
void joue(std::vector<std::vector<int>>& grille, int coup, bool joueur);
#endif //PUISSANCE4_JEU_H
