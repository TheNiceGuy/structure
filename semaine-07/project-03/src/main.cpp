#include <iostream>

using namespace std;

int main() {
    int* pointeur(0);
    pointeur = new int;

    cout << "Quel est votre age? ";
    cin >> *pointeur;
    cin.ignore();

    cout << "Vous avez " << *pointeur << " ans." << endl;

    delete pointeur;
    pointeur = 0;

    return 0;
}
