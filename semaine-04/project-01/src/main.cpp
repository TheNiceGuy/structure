#include <iostream>
#include <vector>

#define QUIT -1
#define MIN 0
#define MAX 100

using namespace std;

/*
 * Entrée: un tableau dynamique de double
 * Sortie: un double
 * Rôle  : calcule la moyenne d'un tableau
 */
double average(vector<double> const& tab) {
    int i, sum(0);

    for(i = 0; i < (int)tab.size(); i++) {
        sum += tab[i];
    }

    return sum/tab.size();
}

int main() {
    int input, counter(1);
    double moyenne;

    vector<double> note;

    cout << "Veuillez entrer les notes de vos élèves (" << QUIT << " pour quitter):" << endl;

    do {
        cout << "Note #" << counter << ":";
        cin >> input;
        cin.ignore();

        if(input > MIN && input < MAX && input != QUIT) {
            counter++;
            note.push_back(input);
        } else {

        }
    } while(input != QUIT);

    moyenne = average(note);

    cout << "La moyenne de la classe est de " << moyenne << "." << endl;

    return 0;
}
