#include <iostream>
#include "Vehicule.h"

using namespace std;

int Vehicule::compteur = 0;

Vehicule::Vehicule() :
m_prix(0) {
    compteur++;
}

Vehicule::Vehicule(int prix) :
m_prix(prix) {
}

Vehicule::~Vehicule() {
    compteur--;
}

void Vehicule::affiche() const {
    cout << "Ceci est un véhicule coutant " << m_prix << "$." << endl;
}

int Vehicule::nombreInstances() {
    return compteur;
}
