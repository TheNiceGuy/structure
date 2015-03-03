#include <iostream>
#include "sousfonction.h"
#include "config.h"

using namespace std;

bool caseVide(char jeu[TAILLE_X][TAILLE_Y], int x, int y) {
    if(jeu[x][y] == VIDE)
        return true;
    else
        return false;
}

bool jeuPlein(char jeu[TAILLE_X][TAILLE_Y]) {
    int x, y;

    /*
     * On regarde chacune des cases pour voir si elle
     * est vide. On quitte dès qu'une case est trouvée.
     */
    for(x = 0; x < TAILLE_X; x++)
        for(y = 0; y < TAILLE_Y; y++)
            if(jeu[x][y] == VIDE)
                return false;

    return true;
}

bool gagnantLigne(char jeu[TAILLE_X][TAILLE_Y], int joueur) {
    int x, y, somme;

    /*
     * Afin de trouver si une ligne qui existe appartient
     * totalement au même joueur, on fait la somme de
     * cette ligne pour ensuite la comparer à la valeur
     * théorique.
     */
    for(x = 0; x < TAILLE_X; x++) {
        somme = 0;
        for(y = 0; y < TAILLE_Y; y++)
            somme = somme+(int)jeu[x][y];

        if(joueur == 0 && somme == (int)JOUEUR0*3)
            return true;
        else if(somme == (int)JOUEUR1*3)
            return true;
    }

    return false;
}

bool gagnantColonne(char jeu[TAILLE_X][TAILLE_Y], int joueur) {
    int x, y, somme;

    /*
     * Afin de trouver si une colonne qui existe appartient
     * totalement au même joueur, on fait la somme de
     * cette colonne pour ensuite la comparer à la valeur
     * théorique.
     */
    for(y = 0; y < TAILLE_Y; y++) {
        somme = 0;
        for(x = 0; x < TAILLE_X; x++)
            somme = somme+(int)jeu[x][y];

        if(joueur == 0 && somme == (int)JOUEUR0*3)
            return true;
        else if(somme == (int)JOUEUR1*3)
            return true;
    }

    return false;
}

bool gagnantDiagonale(char jeu[TAILLE_X][TAILLE_Y], int joueur) {
    int x, y, somme;

    /*
     * Afin de trouver si une diagonale qui existe appartient
     * totalement au même joueur, on fait la somme de
     * cette diagonale pour ensuite la comparer à la valeur
     * théorique.
     *
     * Trouver la diagonale où les coordonnées respectent
     * l'équation suivante:
     *
     *          x-y=0 <=> x=y
     */
    somme = 0;
    for(x = 0; x < TAILLE_X; x++) {
        for(y = 0; y < TAILLE_Y; y++)
            if(x == y)
                somme = somme+(int)jeu[x][y];

        if(joueur == 0 && somme == (int)JOUEUR0*3)
            return true;
        else if(somme == (int)JOUEUR1*3)
            return true;
    }

    /*
     * Trouver la diagonale où les coordonnées respectent
     * l'équation suivante:
     *
     *          x+y-MAX+1=0
     *
     * Si MAX est la taille du tableau dans les deux dimensions.
     */
    somme = 0;
    for(x = 0; x < TAILLE_X; x++) {
        for(y = 0; y < TAILLE_Y; y++)
            if(x+y-TAILLE_X+1 == 0)
                somme = somme+(int)jeu[x][y];

        if(joueur == 0 && somme == (int)JOUEUR0*3)
            return true;
        else if(somme == (int)JOUEUR1*3)
            return true;
    }

    return false;
}
