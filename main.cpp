#include <iostream>
#include <vector>
#include "affichage.h"
#include "moteurJeuPuissance4.h"
#include "jeuPuissance4.h"

using namespace std;

//vector<vector<int>> grille(6, vector<int>(7,0));
vector<vector<Piece>> grille(6, vector<Piece>(7, Piece::empty));

int main() {
    setWindowsConsoleToUTF8();
    afficheRegles();
    joueUnePartie();
    return 0;
}