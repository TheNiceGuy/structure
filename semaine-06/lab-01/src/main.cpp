/*
 * Auteur: Gabriel-Andrew Pollo Guilbert
 *         Samuel Piché
 * Date  : 2 Mars 20159
 */

#include <iostream>
#include <vector>
#include "fonction.h"
#include "config.h"

using namespace std;

void quit() {
    #ifdef __linux__
        cout << "Veuillez appuyer sur entré pour continuer...";
        cin.get();
    #else
        system("pause");
    #endif
}

int main() {
    bool quit;
    char choix;

    do {
        jouerJeu();

        cout << "Voulez-vous jouer une autre partie? (O/N) ";
        cin >> choix;
        cin.ignore();

        switch(choix) {
        case 'n':
        case 'N':
            quit = true;
            break;
        case 'o':
        case 'O':
            quit = false;
            break;
        default:
            break;
        }
    } while(!quit);

    return 0;
}
