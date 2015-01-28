#include <iostream>

using namespace std;

int main() {
    int nb1, nb2, somme;

    cout << "Nombre 1:";
    cin >> nb1;
    cin.ignore();

    cout << "Nombre 2:";
    cin >> nb2;
    cin.ignore();

    somme = nb1+nb2;

    cout << nb1 << "+" << nb2 << "=" << somme << endl;

    return 0;
}
