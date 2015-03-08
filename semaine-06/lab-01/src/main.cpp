/*
 * Auteur: Gabriel-Andrew Pollo Guilbert
 *         Samuel Piché
 * Date  : 2 Mars 2015
 */

#include <iostream>
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

    cout << "Bienvenue à ce fantastique jeu de tic-tac-to. " << endl <<
            "Vous aurez à rentrer des positions. L'origine est en haut à gauche." << endl << endl;

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

    cout << "Merci d'avoir jouer à mon jeu." << endl;

    return 0;
}
