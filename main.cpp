#include <iostream>
#include <vector>
#include "affichage.h"
using namespace std;

vector<vector<int>> grille(6, vector<int>(7,0));
int main()  {
    afficheGrille(grille);
    return 0;
}