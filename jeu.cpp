//
// Created by emily on 18.10.2022.
//
#include "jeu.h"
#include <iostream>
#include <limits>

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

bool isLegalMove(vector<vector<Piece>>& grille, int coup){
    if ((coup >= 0 && coup <= grille.size()) && (grille[0][coup] == Piece::empty)){
        return true;
    }
    return false;
}

void demandeEtJoue(vector<vector<Piece>>& grille, Piece colour){
    int coup = 0;
    do {
        coup = demandePlacement();
    } while(!isLegalMove(grille, coup));
   joue(grille, coup, colour);
}

void joue(vector<vector<Piece>>& grille, int coup, Piece colour) {

    for(int i = grille.size()-1; i >= 0; i--) {
        if(grille[i][coup] == Piece::empty) {
          grille[i][coup] = colour;
          break;
        }
    }
}

bool hasWon(const vector<vector<Piece>> &grille, Piece colour) {
    for(int x = 0; x < grille.size(); x++){
        for(int y = 0; y < grille[x].size(); y++){
            bool  isInYRange = y + 4 <= grille[x].size();
            bool isInXRange = x + 4 <= grille.size();
            if(isInYRange && count(grille, x, y, 0, 1)
            || isInYRange && isInXRange && count(grille, x, y, 1, 1)
            || isInXRange && count(grille, x, y, 1, 0)){
                return true;
            }

        }
    }
}

bool count(const vector<vector<Piece>> &grille, int ligneDepart, int colonneDepart, bool dirX, bool dirY) {
    int result = 0;
    int ligne(ligneDepart);
    int colonne(colonneDepart);

    while(grille[ligne][colonne] == grille[ligneDepart][colonneDepart]) {
        ++result;
        ligne += dirX;
        colonne += dirY;
        if (result >= 4) {
            return true;
        }
    }
    return false;
}