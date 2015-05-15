#include <iostream>
#include "Vehicule.h"

using namespace std;

Vehicule::Vehicule() :
m_prix(0) {
}

Vehicule::Vehicule(int prix) :
m_prix(prix) {
}

Vehicule::~Vehicule() {
}

void Vehicule::affiche() const {
    cout << "Ceci est un véhicule coutant " << m_prix << "$." << endl;
}
