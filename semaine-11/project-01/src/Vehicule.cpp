#include <iostream>
#include "Vehicule.h"

using namespace std;

int Vehicule::nombreInstances = 0;

Vehicule::Vehicule() :
m_prix(0) {
    nombreInstances++;
}

Vehicule::Vehicule(int prix) :
m_prix(prix) {
    nombreInstances++;
}

Vehicule::~Vehicule() {
    nombreInstances--;
}

void Vehicule::affiche() const {
    cout << "Ceci est un véhicule coutant " << m_prix << "$." << endl;
}
