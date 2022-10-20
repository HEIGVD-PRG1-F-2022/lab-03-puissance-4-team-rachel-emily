#include <iostream>
#include <vector>
#include "affichage.h"
#include "jeu.h"

using namespace std;

//vector<vector<int>> grille(6, vector<int>(7,0));
vector<vector<Piece>> grille(6, vector<Piece>(7, Piece::empty));

int main()  {
    setWindowsConsoleToUTF8();
    afficheRegles();
    afficheGrille(grille);
    demandeEtJoue(grille, Piece::red);
    afficheGrille(grille);

    return 0;
}