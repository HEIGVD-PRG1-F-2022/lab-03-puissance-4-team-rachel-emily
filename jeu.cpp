//
// Created by emily on 18.10.2022.
//
#include "jeu.h"
#include <iostream>

using namespace std;



int demandePlacement()  {
    int colonne;
    cout << "Entrez le numéro de la colonne entre 0 et 6 : " << endl;
    while (not(cin >> colonne)) {
        cout << "Vous n'avez pas entré un entier, recommencez : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return colonne;
}

bool isLegalMove(vector<vector<int>>& grille, int coup){
    if ((coup >= 0 && coup <= grille.size()) && (grille[0][coup] == 0)){
        return true;
    }
    return false;
}

void demandeEtJoue(vector<vector<int>>& grille, bool joueur){
    int coup = 0;
    do {
        coup = demandePlacement();
    } while(!isLegalMove(grille, coup));
   joue(grille, coup, joueur);
}

void joue(vector<vector<int>>& grille, int coup, bool joueur) {

    for(int i = grille.size()-1; i >= 0; i--) {
        if(grille[i][coup] == 0) {
          grille[i][coup] = (int)joueur + 1;
          break;
        }
    }
}

