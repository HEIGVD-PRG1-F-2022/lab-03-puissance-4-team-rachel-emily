#include <iostream>
#include <vector>
#include "affichage.h"
#include "jeu.h"

using namespace std;

//vector<vector<int>> grille(6, vector<int>(7,0));
vector<vector<int>> grille = {
        {2, 1, 2, 1, 2, 1, 1},
        {2, 1, 2, 1, 1, 2, 2},
        {1, 2, 1, 2, 2, 1, 1},
        {1, 1, 2, 1, 2, 1, 2},
        {2, 2, 1, 1, 2, 1, 1},
        {1, 2, 1, 2, 1, 2, 2},
};

int main()  {
    setWindowsConsoleToUTF8();
    afficheRegles();
    afficheGrille(grille);
    //demandePlacement();
    return 0;
}