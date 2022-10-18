#include <iostream>
#include <vector>
#include "affichage.h"
#include "affichage.h"
#include "jeu.h"

using namespace std;

vector<vector<int>> grille(6, vector<int>(7,0));
int main()  {
    afficheRegles();
    afficheGrille(grille);
    demandePlacement();
    return 0;
}