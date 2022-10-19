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
#ifdef _WIN32

    /**
 * Set Windows console format to UTF-8 to support display of colors
 */

    system(("chcp "s + std::to_string(CP_UTF8)).c_str()); //for colored output in console


#endif
    afficheRegles();
    afficheGrille(grille);
    //demandePlacement();
    return 0;
}