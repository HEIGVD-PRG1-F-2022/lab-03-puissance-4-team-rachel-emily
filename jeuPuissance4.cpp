//
// Created by rache on 21.10.2022.
//
#include "moteurJeuPuissance4.h"
#include "affichage.h"
#include <vector>
#include <iostream>
#include "util.h"

using namespace std;

vector<vector<Piece>> demandeTailleEtCreeGrille() {
    int ligne, colonne;
    cout << "Entrez les dimensions de la grille de jeu : " << endl;
    while (1) {
        cout << "Nombre de lignes : ";

        askForIntAndCheck(ligne);

        cout << "Nombre de colonnes : ";
        askForIntAndCheck(colonne);
        if (colonne >= 4 or ligne >= 4) {
            break;
        }
        cout << "Aligner 4 pions sur un plateau de moins de 4 lignes ou colonnes va être difficile, réessayez : "
             << endl;
    }
    vector<vector<Piece>> grille(ligne, vector<Piece>(colonne, Piece::empty));
    return grille;
}

void demandeEtJoue(vector<vector<Piece>> &grille, Piece colour) {
    int coup = 0;
    while (1) {
        cout << "Joueur " << ((colour == Piece::red) ? "rouge" : "jaune")
             << ", entrez le numéro de la colonne entre 0 et " << grille[0].size() - 1 << " : " << endl;
        askForIntAndCheck(coup);

        if (isLegalMove(grille, coup)) {
            break;
        }
        cout << "Coup invalide." << endl;
    }
    joue(grille, coup, colour);
}

void ordinateurJoue(vector<vector<Piece>> &grille, Piece colour) {
    joue(grille, computerModeratelyRandomChoice(grille, colour), colour);

}

void joueUnePartie() {
    afficheRegles();
    int response = 0;
    cout << "Voulez vous jouer une partie avec l'ordinateur ? (0 = non, autre chiffre = oui) : ";
    askForIntAndCheck(response);
    bool ia((bool) response);
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
        if (ia and not(joueur1)) {
            ordinateurJoue(grille, currentPiece);
            cout << endl;
        } else {
            demandeEtJoue(grille, currentPiece);
        }

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

