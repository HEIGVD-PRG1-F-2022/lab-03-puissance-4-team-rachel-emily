//
// Created by rache on 18.10.2022.
//
#include <iostream>

#include "affichage.h"
using namespace std;
void afficheRegles() {
    cout << "Pour commencer une partie de puissance 4, on désigne le premier joueur. Celui-ci met un de ses jetons de couleur dans l’une des colonnes de son choix. Le jeton tombe alors en bas de la colonne.\n"
            "\n"
            "Le deuxième joueur insère à son tour son jeton, de l’autre couleur dans la colonne de son choix. Et ainsi de suite jusqu’à obtenir une rangée de 4 jetons de même couleur."
            "\n" << endl;
}

void afficheGrille(const vector<vector<int>>& grille) {
    for(int i = 0; i < grille.size(); i++) {
        for(int j= 0; j < grille[i].size(); j++) {
            cout << setw(4) << grille[i][j];
        }
        cout << endl;
    }
}