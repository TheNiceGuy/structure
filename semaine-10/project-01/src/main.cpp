#include <iostream>
#include "Voiture.h"
#include "Moto.h"

using namespace std;

int main() {
    Vehicule* v1 = NULL;
    Vehicule* v2 = NULL;
    Vehicule* v3 = NULL;

    v1 = new Moto(45640);
    v2 = new Voiture(28500, 4);
    v3 = new Moto(1540);

    v1->affiche();
    v2->affiche();
    v3->affiche();

    delete v1;
    delete v2;
    delete v3;

    return 0;
}
