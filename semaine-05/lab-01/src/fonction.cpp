#include <iostream>
#include <vector>
#include "fonction.h"

using namespace std;

void getNote(vector<int> &note) {
    int counter(1), input;

    cout << "Veuillez entrer les notes de vos élèves. (-1 pour quitter)" << endl;

    // demander les notes à l'utilisateur
    do {
        cout << "Étudiant #" << counter << ":";
        cin >> input;
        cin.ignore();

        // regarder si la note est entre 0 et 100 inclusivement
        if(input >= 0 && input <= 100) {
            note.push_back(input);
            counter++;
        // regarder si l'utilisateur veut quitter
        // sinon, la valeur entrée est mauvaise
        } else if(input != QUIT){
            cout << "Veuillez entrer une valeur entre 0 et 100:" << endl;
        }
    } while(input != QUIT);
}

double moyenneNote(vector<int> const &note) {
    int counter;
    double sum;

    // effectuer la somme des entiers
    for(counter = 0; counter < (int)note.size(); counter++) {
        sum = sum + note[counter];
    }

    // retourner la division de la somme qui est la moyenne
    return sum/(int)note.size();
}
