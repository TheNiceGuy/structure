/*
 * Auteur: Gabriel-Andrew Pollo Guilbert
 *         Samuel Piché
 * Date  : 2 Mars 2015
 */

#include <iostream>
#include <stdlib.h>
#include <limits>
#include "fonction.h"
#include "config.h"

using namespace std;

int main() {
    bool quit, valide;
    char choix;

    system(CLEAR);
    cout << "Bienvenue à ce fantastique jeu de tic-tac-to. " << endl
         << "Vous aurez à rentrer des positions (x,y)." << endl << endl
         << "L'origine est en haut à gauche:" << endl
         << "(0,0) (...) (0," << TAILLE_Y-1 << ")" << endl
         << "(...) (...) (...)" << endl
         << "(" << TAILLE_X-1 << ",0) (...) (" << TAILLE_Y-1 << "," << TAILLE_X-1 << ")"
         << endl << endl;

    do {
        jouerJeu();

        /*
         * On demande à l'utilisateur s'il veut jouer une autre partie.
         * On boucle pour être sur qu'il entre un choix valide.
         */
        do {
            cout << "Voulez-vous jouer une autre partie? (O/N) ";
            cin >> choix;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            switch(choix) {
            case 'n':
            case 'N':
                quit   = true;
                valide = true;
                system(CLEAR);
                break;
            case 'o':
            case 'O':
                quit   = false;
                valide = true;
                system(CLEAR);
                break;
            default:
                valide = false;
                break;
            }
        } while(!valide);
    } while(!quit);

    cout << "Merci d'avoir joué à notre jeu." << endl;

#ifdef __linux__
    cout << "Veuillez appuyer sur entré pour continuer...";
    cin.get();
#else
    system("pause");
#endif

    return 0;
}
