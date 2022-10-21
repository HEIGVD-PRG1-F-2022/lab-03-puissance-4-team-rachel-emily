//
// Created by rache on 21.10.2022.
//

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

/**
 * efface la console, s'adapte en fonction que l'on utilise windows ou linux
 */
void clearConsole();

#endif //PUISSANCE4_UTIL_H
