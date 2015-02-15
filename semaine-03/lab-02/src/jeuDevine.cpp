/*
 * Auteur: Gabriel-Andrew Pollo Guilbert
 * Date  : 15 Février 2015
 */

#include <iostream>
#include <stdlib.h>
#include "jeuDevine.h"

#define LIMITE 1000

using namespace std;

/*
 * Cette fonction change les bornes minimale et maximale
 */
void setLimit(int& min, int& max) {
    cout << "Veuillez entrer la borne minimale: ";
    do {
        cin >> min;
        cin.ignore();
        if(min < 0)
            cout << "Veuillez enter un nombre plus grand que " << 0 << ": ";
    } while(min < 0);

    cout << "Veuillez entrer la borne maximale: ";
    do {
        cin >> max;
        cin.ignore();
        if(max <= min)
            cout << "Veuillez enter un nombre plus grand que " << min << ": ";
    } while(max <= min);
}

/*
 * Cette fonction retourne un nombre entre min et max inclusivement.
 */
int getNumber(int min, int max) {
    return rand()%(max+1-min)+min;
}

/*
 * Cette fonction démarre le jeu de devinette à l'utilisateur.
 * Elle retourne soit -1 pour quitter ou le nombre de tentative.
 */
int playGame(int min, int max) {
    bool fin(false);
    int nombre(getNumber(min, max));
    int tentative(0);
    int reponse;
    int ret;

    cout << "Je vous cache un nombre compris entre " << min << " et " << max << "." << endl;
    cout << "Pouvez-vous le deviner ? (" << QUIT << " pour quitter)" << endl << endl;
    cout << "S’il-vous-plait entrez votre premier essai: ";
    do {
        tentative++;
        cin >> reponse;
        cin.ignore();
        if(reponse == QUIT) {
            ret = QUIT;
            fin = true;
        } else if(reponse < 0 || reponse > LIMITE) {
            cout << "Le nombre est hors borne. Essayez encore: ";
        } else if(reponse < nombre) {
            cout << "Nombre pas assez élevé. Essayez encore: ";
        } else if(reponse > nombre) {
            cout << "Nombre trop élevé. Essayez encore: ";
        } else {
            ret = tentative;
            fin = true;
            cout << "Excellent! Vous avez deviné le nombre!" << endl;
        }
    } while(!fin);

    return ret;
}
