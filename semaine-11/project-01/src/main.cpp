#include <iostream>
#include <vector>
#include "Voiture.h"
#include "Moto.h"

using namespace std;

int main() {
    int i, j;

    vector<Vehicule*> listeVehicules;

    listeVehicules.push_back(new Voiture(15000, 4));
    listeVehicules.push_back(new Moto(2500));
    listeVehicules.push_back(new Moto(13060));
    listeVehicules.push_back(new Voiture(1000, 2));

    cout << Vehicule::nombreInstances() << endl;

    j = (int)listeVehicules.size();
    for(i = 0; i < j; i++) {
        listeVehicules[i]->affiche();

        delete listeVehicules[i];
        listeVehicules.pop_back();
    }

    return 0;
}
