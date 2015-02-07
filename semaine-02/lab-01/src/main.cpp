/*
 * Auteur: Gabriel-Andrew Pollo Guilbert
 * Date  : 2 Février 2015
 *
 * Ce programme demande une note à l'utilisateur et lui renvoit
 * un message de réussite ou d'échec.
 */

#include <iostream>

#define MIN   0
#define MAX 100
#define NOTE_A 90
#define NOTE_B 80
#define NOTE_C 70
#define NOTE_D 60
#define EXCELLENT 75
#define BRAVO 60

using namespace std;

int main() {
    int chiffre;

    cout << "Ce programme demande une note à l'utilisateur et lui donne son résultat." << endl << endl;

    do {
        cout << "Veuillez entrer une note entre " << MIN << " et " << MAX << ":";
        cin >> chiffre;
        cin.ignore();
    } while(chiffre < MIN || chiffre > MAX);

    if(chiffre >= NOTE_A) {
        cout << "Vous avez eu un A votre examen.";
    } else if(chiffre >= NOTE_B) {
        cout << "Vous avez eu un B votre examen.";
    } else if(chiffre >= NOTE_C) {
        cout << "Vous avez eu un C votre examen.";
    } else if(chiffre >= NOTE_D) {
        cout << "Vous avez eu un D votre examen.";
    } else {
        cout << "Désolé, cette note est un échec.";
    }

    if(chiffre > EXCELLENT) {
        cout << " Excellent! Vous avez obtenu une excellent note." << endl;
    } else if(chiffre >= BRAVO) {
        cout << " Bravo! Vous avez réussi l'examen." << endl;
    } else {
        cout << endl;
    }

    cout << endl << "Merci d'avoir utilisé mon programme." << endl;

#ifdef __linux__
    cout << "Veuillez appuyer sur une touche pour continuer...";
    cin.get();
#else
    system("pause");
#endif

    return 0;
}
