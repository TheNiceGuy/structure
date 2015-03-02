#ifndef SOUSFONCTION_H
#define SOUSFONCTION_H

#include <vector>
#include "config.h"

using namespace std;

/*
 * Cette fonction vérifie si une case est vide.
 *
 * Entrée: le tableau du jeu, une coordonnée en x,
           un coordonnées en y
 * Sortie: un booléen
 */
bool caseVide(char jeu[TAILLE_X][TAILLE_X], int x, int y);

/*
 * Cette fonction vérifie si le jeu est plein.
 *
 * Entrée: le tableau du jeu
 * Sortie: un booléen
 */
bool jeuPlein(char jeu[TAILLE_X][TAILLE_X]);

/*
 * Cette fonction vérifie si un joueur a une ligne
 * gagnante dans le jeu.
 *
 * Entrée: le tableau du jeu, le numéro du joueur
 * Sortie: un booléen
 */
bool gagnantLigne(char jeu[TAILLE_X][TAILLE_X], int joueur);

/*
 * Cette fonction vérifie si un joueur a une colonne
 * gagnante dans le jeu.
 *
 * Entrée: le tableau du jeu, le numéro du joueur
 * Sortie: un booléen
 */
bool gagnantColonne(char jeu[TAILLE_X][TAILLE_X], int joueur);

/*
 * Cette fonction vérifie si un joueur a une diagonale
 * gagnante dans le jeu.
 *
 * Entrée: le tableau du jeu, le numéro du joueur
 * Sortie: un booléen
 */
bool gagnantDiagonale(char jeu[TAILLE_X][TAILLE_X], int joueur);

#endif
