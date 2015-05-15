#include <stdlib.h>
#include "Arme.h"
#include "Paysan.h"

using namespace std;

Arme::Arme(int degatsDe, int degatsNbrDe, int reussite, std::string nom) :
m_degatsDe(degatsDe),
m_degatsNbrDe(degatsNbrDe),
m_reussite(reussite),
m_nom(nom) {

}

Arme::~Arme() {

}

int Arme::getDegats() {
    int reussite, degats;
    string somme;

    /*
     * On s'assure qu'il n'a pas manqué son attaque.
     */
    reussite = Paysan::lancerDe(1, 100, somme);
    if(reussite <= m_reussite) {
        degats = Paysan::lancerDe(m_degatsDe, m_degatsNbrDe, somme);

        cout << endl << accent("Dégats: ") << somme << endl;
        return degats;
    } else
        return RATER;
}

int Arme::getDegatsDe() {
    return m_degatsDe;
}

int Arme::getDegatsNbrDe() {
    return m_degatsNbrDe;
}

int Arme::getReussite() {
    return m_reussite;
}

string Arme::getNom() {
    return m_nom;
}
