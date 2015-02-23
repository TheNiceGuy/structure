#ifndef FONCTION_H
#define FONCTION_H

#define QUIT -1

/*
 * Entrée: un vector d'entier vide
 * Sortie: aucune
 *
 * Cette fonction remplis le tableau avec des notes entrées
 * par l'utilisateur.
 */
void getNote(std::vector<int> &note);

/*
 * Entrée: un vector d'entier contenant des notes
 * Sortie: un double
 *
 * Cette fonction retourne la moyenne des valeurs dans le
 * vector.
 */
double moyenneNote(std::vector<int> const &note);

#endif
