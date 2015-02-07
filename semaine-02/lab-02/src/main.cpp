/*
 * Auteur: Gabriel-Andrew Pollo Guilbert
 * Date  : 2 Février 2015
 *
 * Ce programme simule une calculatrice simple d'entiers positifs.
 */

#include <iostream>

#define QUIT -1

using namespace std;

int getNombre(string message) {
    int input;

    do {
        cout << message;
        cin >> input;
        cin.ignore();

        if(input < 0 && input != QUIT) {
            cout << "Ce nombre n'est pas positif!" << endl;
        }
    } while(input < 0 && input != QUIT);

    return input;
}

int main() {
    bool quit(true);
    char operateur;
    int nombre[2];
    int resultat;

    cout << "Ce programme simule une calculatrice simple d'entiers positifs." <<
            "Pour quitter, il suffit d'entrer " << QUIT << " comme nombre." << endl << endl;

    nombre[0] = getNombre("Veuillez entrer le premier nombre:");
    if(nombre[0] == QUIT) return 0;

    nombre[1] = getNombre("Veuillez entrer le deuxième nombre:");
    if(nombre[1] == QUIT) return 0;

    do {
        quit = true;

        cout << "Veuillez entrer l'opérateur à utiliser [+] [-] [*] [/] [%]:";
        cin >> operateur;
        cin.ignore();

        switch(operateur) {
        case '+':
            resultat = nombre[0]+nombre[1];
            break;
        case '-':
            resultat = nombre[0]-nombre[1];
            break;
        case '*':
            resultat = nombre[0]*nombre[1];
            break;
        case '/':
            resultat = nombre[0]/nombre[1];
            break;
        case '%':
            resultat = nombre[0]%nombre[1];
            break;
        default:
            quit = false;
            cout << "L'opérateur entrer n'est pas valide." << endl;
        }
    } while(!quit);

    cout << endl << nombre[0] << operateur << nombre[1] << "=" << resultat << endl;
    cout << endl << "Merci d'avoir utilisé mon programme." << endl;

#ifdef __linux__
    cout << "Veuillez appuyer sur entré pour continuer...";
    cin.get();
#else
    system("pause");
#endif

    return 0;
}
