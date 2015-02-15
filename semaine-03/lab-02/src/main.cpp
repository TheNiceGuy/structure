/*
 * Auteur: Gabriel-Andrew Pollo Guilbert
 * Date  : 15 Février 2015
 *
 * Ce jeu demande un nombre entre des bornes à l'utilisateur en
 * lui donnant des indices.
 */

#include <iostream>
#include <stdlib.h>
#ifndef __linux__
    #include <time.h>
#endif
#include "jeuDevine.h"

using namespace std;

int main() {
    char choix;
    int ret;
    int min, max;

    srand(time(NULL));
    setLimit(min, max);

    do {
        cout << endl;
        ret = playGame(min, max);
        if(ret != QUIT) {
            cout << endl << "Vous avez eu besoin de " << ret;
            cout << (ret>1?" tentatives.":" tentative.") << endl;
            cout << "Desirez-vous jouer encore? (y ou n)? ";
            cin >> choix;
            cin.ignore();

            // regarde le choix (y ou n)
            switch(choix) {
            case 'y':
            case 'Y':
                cout << endl;
                break;
            case 'n':
            case 'N':
                ret = QUIT;
            default:
                break;
            }
        }
    } while(ret != QUIT);
    cout << endl << "Merci d'avoir utilisé mon programme." << endl;

#ifdef __linux__
    cout << "Veuillez appuyer sur entré pour continuer...";
    cin.get();
#else
    system("pause");
#endif

    return 0;
}
