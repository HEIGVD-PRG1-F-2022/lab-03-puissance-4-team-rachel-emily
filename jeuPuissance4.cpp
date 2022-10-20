//
// Created by rache on 21.10.2022.
//
#include "moteurJeuPuissance4.h"
#include "affichage.h"
#include <vector>
#include <iostream>

using namespace std;

vector<vector<Piece>> demandeTailleEtCreeGrille() {
    int ligne, colonne;
    cout << "Entrez les dimensions de la grille de jeu : " << endl;
    while (1) {
        cout << "Nombre de lignes : ";

        askUserAndCheck(ligne);

        cout << "Nombre de colonnes : ";
        askUserAndCheck(colonne);
        if (colonne >= 4 or ligne >= 4) {
            break;
        }
        cout << "Aligner 4 pions sur un plateau de moins de 4 lignes ou colonnes va être difficile, réessayez : "
             << endl;
    }
    vector<vector<Piece>> grille(ligne, vector<Piece>(colonne, Piece::empty));
    return grille;
}

void joueUnePartie() {
    vector<vector<Piece>> grille = demandeTailleEtCreeGrille();
    bool joueur1 = true;
    Piece currentPiece;
    while (1) {
        afficheGrille(grille);
        if (joueur1) {
            currentPiece = Piece::yellow;

        } else {
            currentPiece = Piece::red;
        }
        demandeEtJoue(grille, currentPiece);

        if (hasWon(grille, currentPiece)) {
            afficheGrille(grille);
            cout << "Joueur " << (joueur1 ? "jaune" : "rouge") << " a gagné. " << endl;
            return;
        }
        if (isBoardFull(grille)) {
            afficheGrille(grille);
            cout << "Egalité" << endl;
            return;
        }
        joueur1 = !joueur1;
    }
}

