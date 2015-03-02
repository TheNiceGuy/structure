/*
 * Auteur: Gabriel-Andrew Pollo Guilbert
 *         Samuel Piché
 * Date  : 23 Février 2015
 *
 * Ce programme demande des notes et fait la moyenne de celles-ci;
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include "fonction.h"

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
    int counter;
    double moyenne;
    vector<int> note;

    cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(1);

    getNote(note);

    // quitter si le nombre de valeur entré est nul
    if((int)note.size() == 0) {
        quit();
        return 0;
    }
    moyenne = moyenneNote(note);

    // afficher les notes ramassées
    cout << endl;
    cout << "Resultats pour ce groupe :" << endl;
    cout << "__________________________" << endl;
    for(counter = 0; counter < (int)note.size(); counter++) {
        cout << "Étudiant #" << counter+1 << ":" << setw(5) << note[counter] << "%" << endl;
    }
    // afficher la moyenne des notes
    cout << "__________________________" << endl;
    cout << "Moyenne:" << setw(9) << moyenne << "%" << endl;

    quit();
    return 0;
}
