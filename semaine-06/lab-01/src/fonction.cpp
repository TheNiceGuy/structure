#include <iostream>
#include <stdlib.h>
#include "fonction.h"
#include "config.h"

using namespace std;

void jouerJeu() {
    char jeu[TAILLE_X][TAILLE_Y];
    int joueur(1);

    initialiserJeu(jeu);

    /*
     * Ceci est la boucle principale du jeu. La demande
     * et l'affichage du jeu sont appelées ici.
     */
    do {
        prochainJoueur(joueur);
        afficherJeu(jeu);
        demanderPosition(jeu, joueur);
    } while(!jeuGagnant(jeu, joueur) && !jeuPlein(jeu));

    /*
     * On affiche le jeu après la partie et on affiche
     * le status de la partie: le gagnant ou une partie
     * nulle.
     */
    afficherJeu(jeu);
    if(jeuPlein(jeu))
        cout << "La partie est nulle!" << endl;
}

void initialiserJeu(char jeu[TAILLE_X][TAILLE_X]) {
    int x, y;

    /*
     * Toute les valeurs sont mises à la valeur VIDE
     * définit dans le fichier config.h.
     */
    for(x = 0; x < TAILLE_X; x++)
        for(y = 0; y < TAILLE_X; y++)
            jeu[x][y] = VIDE;
}

void afficherJeu(char jeu[TAILLE_X][TAILLE_X]) {
    int x, y;

    /*
     * Le séparateur entre les colonnes peut-être
     * changer avec la valeur SEPARATION dans le fichier
     * config.h.
     */
    for(x = 0; x < TAILLE_X; x++) {
        for(y = 0; y < TAILLE_X; y++)
            cout << SEPARATION << jeu[x][y];
        cout << SEPARATION << endl;
    }
}

void demanderPosition(char jeu[TAILLE_X][TAILLE_X], int joueur) {
    int x, y;

    /*
     * Il faut s'assurer que la case reliée aux coordonnées
     * entrées est libre avant de continuer.
     */
    do {
        /*
         * Demandons la coordonnée en x. Il faut s'assurer
         * que la coordonnée en x respecte bien les bornes
         * du jeu.
         */
        do {
            cout << "Position x: ";
            cin >> x;
            cin.ignore();
            if(x < 0 || x >= TAILLE_X)
                cout << "Veuillez entrer une valeur entre 0 et " << TAILLE_X-1 << "." << endl;
        } while(x < 0 || x >= TAILLE_X);

        /*
         * Demandons la coordonnée en y. Il faut s'assurer
         * que la coordonnée en y respecte bien les bornes
         * du jeu.
         */
        do {
            cout << "Position y: ";
            cin >> y;
            cin.ignore();
            if(y < 0 || y >= TAILLE_Y)
                cout << "Veuillez entrer une valeur entre 0 et " << TAILLE_Y-1 << "." << endl;
        } while(y < 0 || y >= TAILLE_Y);

        /*
         * Écrire un message d'erreur si la case n'est pas vide.
         */
        if(!caseVide(jeu, x, y))
            cout << "Veuillez choisir une autre case." << endl;
    } while(!caseVide(jeu, x, y));

    /*
     * Affecter la case au symbole du joueur qui jouait.
     */
    if(joueur == 0)
        jeu[x][y] = JOUEUR0;
    else
        jeu[x][y] = JOUEUR1;
}

void prochainJoueur(int &joueur) {
    if(joueur == 0)
        joueur = 1;
    else
        joueur = 0;
}

bool jeuGagnant(char jeu[TAILLE_X][TAILLE_X], int joueur) {
    /*
     * Vérifier chacun leur tour les trois types de lignes.
     * On quitte la fonction dès qu'une ligne est trouvée.
     */
    if(gagnantLigne(jeu, joueur))
        return true;
    else if(gagnantColonne(jeu, joueur))
        return true;
    else if(gagnantDiagonale(jeu, joueur))
        return true;

    return false;
}
