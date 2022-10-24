/**
 * useful functions not specifically related to the game
 *
 * @name Puissance4
 * @date 21.10.2022
 * @authors Emily Baquerizo and Rachel Tranchida
 */
#ifndef PUISSANCE4_UTIL_H
#define PUISSANCE4_UTIL_H


#include <string>

/**
 * Fonction utilitaire, permet de demander un int à l'utilisateur jusqu'à ce qu'il entre bien un int
 * @param numberToFill la variable qui doit contenir la réponse de l'utilisateur
 * @param errorMessage le message d'erreur à donner à l'utilisateur (avec valeur par défaut)
 */
void askForIntAndCheck(int &numberToFill, std::string errorMessage = "Entrée invalide, réessayez : ");

/**
 * trouve un int aléatoire entre 0 et maxValue
 * @param maxValue valeur max de l'entier aléatoire désiré
 * @return un entier aléatoire entre 0 et maxValue
 */
int randomInt(int maxValue);

/**
* Set Windows console format to UTF-8 to support display of colors
*/
void setWindowsConsoleToUTF8();


#endif //PUISSANCE4_UTIL_H
