/*
 * Auteur: Gabriel-Andrew Pollo Guilbert
 * Date  : 9 Février 2015
 *
 * Ce jeu demande un nombre entre des bornes à l'utilisateur en
 * lui donnant des indices.
 */

#include <iostream>
#ifdef __linux__
    #include <cstdlib>
#else
    #include <ctime>
#endif
#include "jeuDevine.h"

using namespace std;

int main() {
    char choix;
    int ret;

    srand(time(NULL));

    do {
        ret = playGame();
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
