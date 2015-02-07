/*
 * Auteur: Gabriel-Andrew Pollo Guilbert
 * Date  : 2 Février 2015
 *
 * Ce programme demande 10 valeurs et détermine la plus grande.
 */

#include <iostream>

#define NOMBRE_DE_VALEUR 10

using namespace std;

int main() {
    // i est initialisé à 2 pour faciliter la sortie des demandes.
    int a, b, i(2);

    cout << "Ce programme demande 10 valeurs et détermine la plus grande." << endl << endl;

    cout << "Veuillez entrer la valeur #1: ";
    cin >> a;
    cin.ignore();

    do {
        cout << "Veuillez entrer la valeur #" << i << ": ";
        cin >> b;
        cin.ignore();

        if(b > a) {
            a = b;
        }

        i++;
    } while(i <= NOMBRE_DE_VALEUR);

    cout << "La valeur la plus grande  est " << a << "." << endl;
    cout << endl << "Merci d'avoir utilisé mon programme." << endl;

#ifdef __linux__
    cout << "Veuillez appuyer sur entré pour continuer...";
    cin.get();
#else
    system("pause");
#endif

    return 0;
}
