#include <iostream>
#include <cstdlib>
#include "jeuDevine.h"

#define LIMITE 1000

using namespace std;

/*
 * Cette fonction retourne un nombre entre 1 et la borne LIMITE.
 */
int getNumber() {
    return rand()%LIMITE+1;
}

/*
 * Cette fonction démarre le jeu de devinette à l'utilisateur.
 * Elle retourne soit -1 pour quitter ou le nombre de tentative.
 */
int playGame() {
    bool fin(false);
    int nombre(getNumber());
    int tentative(0);
    int reponse;
    int ret;

    cout << "Je vous cache un nombre compris entre 1 et " << LIMITE << "." << endl;
    cout << "Pouvez-vous le deviner ? (" << QUIT << " pour quitter)" << endl << endl;
    cout << "S’il-vous-plait entrez votre premier essai: ";
    do {
        tentative++;
        cin >> reponse;
        cin.ignore();
        if(reponse == QUIT) {
            ret = QUIT;
            fin = true;
        } else if(reponse < 1 || reponse > LIMITE) {
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
