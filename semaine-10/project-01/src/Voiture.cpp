#include <iostream>
#include "Voiture.h"

using namespace std;

Voiture::Voiture() {
    m_prix  = 0;
    m_porte = 0;
}

Voiture::Voiture(int prix, int nb_porte) {
    m_prix  = prix;
    m_porte = nb_porte;
}

Voiture::~Voiture() {
}

int Voiture::nbrRoues() const {
    return 4;
}

void Voiture::affiche() const {
    cout << "Ceci est une voiture coutant " << m_prix << "$ avec "
         << m_porte << " porte(s)." << endl;
}
