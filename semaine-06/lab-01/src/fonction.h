#ifndef FONCTION_H
#define FONCTION_H

#include <vector>
#include "sousfonction.h"
#include "config.h"

using namespace std;

/*
 * Cette fonction démarre une partie de tic-tac-to.
 *
 * Entrée:
 * Sortie:
 */
void jouerJeu();

/*
 * Cette fonction affiche le jeu dans la console.
 *
 * Entrée: le tableau du jeu
 * Sortie:
 */
void initialiserJeu(char jeu[TAILLE_X][TAILLE_Y]);

/*
 * Cette fonction affiche le jeu dans la console.
 *
 * Entrée: le tableau du jeu
 * Sortie:
 */
void afficherJeu(char jeu[TAILLE_X][TAILLE_Y]);

/*
 * Cette fonction demande une position pour un mouvement.
 * Elle vérifie que la case de soit pas prise pour ensuite
 * l'affecter au jeu.
 *
 * Entrée: le tableau du jeu, le numéro du joueur
 * Sortie:
 */
void demanderPosition(char jeu[TAILLE_X][TAILLE_Y], int joueur);

/*
 * Cette fonction change le numéro du joueur actif.
 *
 * Entrée: le numéro du joueur
 * Sortie:
 */
void prochainJoueur(int &joueur);

/*
 * Cette fonction vérifie s'il y a un gagnant dans la partie.
 * Elle regarde les lignes horizontales, verticales et
 * diagonales dans le jeu.
 *
 * Entrée: le tableau du jeu, le numéro du joueur
 * Sortie: un booléen
 */
bool jeuGagnant(char jeu[TAILLE_X][TAILLE_Y], int joueur);


#endif
