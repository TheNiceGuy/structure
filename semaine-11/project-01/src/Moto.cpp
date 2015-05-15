#include <iostream>
#include "Moto.h"

using namespace std;

Moto::Moto() {
    m_prix = 0;
}

Moto::Moto(int prix) {
    m_prix = prix;
}

Moto::~Moto() {
}

void Moto::affiche() const {
    cout << "Ceci est une moto coutant " << m_prix << "$." << endl;
}
