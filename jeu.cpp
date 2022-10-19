//
// Created by emily on 18.10.2022.
//
#include "jeu.h"
#include <iostream>

using namespace std;



void demandePlacement()  {
    int colonne;
    cout << "Entrez le numéro de la colonne entre 0 et 6 : " << endl;
    cin >> colonne;
}

bool isLegalMove(vector<vector<int>>& grille, int coup){
    if ((coup >= 0 && coup <= grille.size()) && (grille[0][coup] == 0)){
        return true;
    }
    return false;
}

void demandeEtJoue(){

}