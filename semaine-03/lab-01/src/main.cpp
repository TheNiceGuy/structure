/*
 * Auteur: Gabriel-Andrew Pollo Guilbert
 * Date  : 15 Février 2015
 *
 * Ce programme demande des multiplications l'utilisateur.
 */

#include <iostream>
#include <stdlib.h>
#ifndef __linux__
    #include <time.h>
#endif

#define QUIT -1
#define LIMITE 12

using namespace std;

/*
 * Cette fonction retourne un nombre entre 1 et la borne LIMITE.
 */
int getNumber() {
    return rand()%LIMITE+1;
}

/*
 * Cette fonction simule un jeu d'essaie pour une multiplication.
 */
int jeu() {
    bool fin;
    int nombre[2];
    int resultat;
    int reponse;
    int ret;

    nombre[0] = getNumber();
    nombre[1] = getNumber();
    resultat = nombre[0]*nombre[1];

    cout << "Combien font " << nombre[0] << " fois " << nombre[1] << " ?" << endl;
    cout << "Réponse: ";

    do {
        cin >> reponse;
        cin.ignore();

        if(reponse == resultat) {
            ret = 0;
            fin = true;
            cout << "Très bien!" << endl << endl;
        } else if(reponse == QUIT) {
            ret = QUIT;
            fin = true;
        } else
            cout << "Non. Essaie de nouveau s’il-te-plait: ";
    } while(!fin);

    return ret;
}

int main() {
    cout << "Ce programme demande des multiplications à l'utilisateur. " <<
            "Pour quitter, il suffit d'entrer " << QUIT << " comme nombre." << endl << endl;

    srand(time(NULL));

    while(jeu() != QUIT) {}
    cout << endl << "Merci d'avoir utilisé mon programme." << endl;

#ifdef __linux__
    cout << "Veuillez appuyer sur entré pour continuer...";
    cin.get();
#else
    system("pause");
#endif

    return 0;
}
