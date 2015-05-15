#include <iostream>
#include <iomanip>
#include <limits>
#include "Magicien.h"

using namespace std;

Magicien::Magicien() {
    m_vie      = Paysan::lancerDe(M_HP_DE, M_HP_DE_NIVEAU, m_somme_vie);
    m_vieMax   = m_vie;
    m_mana     = Paysan::lancerDe(M_MP_DE, M_MP_DE_NIVEAU, m_somme_mana);
    m_manaMax  = m_mana;
    m_aveugle  = false;
    m_priorite = false;
    m_nom      = "SANS NOM";
    m_arme     = new Arme(M_ARME_DE, M_ARME_DE_NIVEAU, M_ARME_DE_REUSSITE,
                          accent(M_ARME_NOM));
}

Magicien::Magicien(string nom) {
    m_vie      = Paysan::lancerDe(M_HP_DE, M_HP_DE_NIVEAU, m_somme_vie);
    m_vieMax   = m_vie;
    m_mana     = Paysan::lancerDe(M_MP_DE, M_MP_DE_NIVEAU, m_somme_mana);
    m_manaMax  = m_mana;
    m_aveugle  = false;
    m_priorite = false;
    m_nom      = nom;
    m_arme     = new Arme(M_ARME_DE, M_ARME_DE_NIVEAU, M_ARME_DE_REUSSITE,
                          accent(M_ARME_NOM));
}

Magicien::~Magicien() {

}

void Magicien::afficherAction() {
    string vie, mana, reussite;

    Paysan::afficherAction();

    vie      = "[-"+to_string(M_BF_DEGATS_DE)
              +"d" +to_string(M_BF_DEGATS_DE_NIVEAU)+"]";
    mana     = "[" +to_string(M_BF_MANA_DE)
              +"d" +to_string(M_BF_MANA_DE_NIVEAU)+"]";
    reussite = "[" +to_string(M_BF_REUSSITE)+"%]";
    cout << "1 - "
         << setw(ESPACEMENT_ACTION)   << left << accent("boule de feu")
         << setw(ESPACEMENT_VIE)      << left << vie
         << setw(ESPACEMENT_MANA)     << left << mana
         << setw(ESPACEMENT_REUSSITE) << left << reussite
         << endl;
}

void Magicien::effectuerAction(Paysan* cible) {
    int numero;

    /*
     * On boucle afin de s'assurer que l'utilisateur a saisie un choix valide.
     */
    do {
        cout << "Choix: ";
        cin >> numero;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            numero = -1;
        }

        /*
         * On effectue l'action demandée.
         */
        switch(numero) {
        case 0: attaque(cible); break;
        case 1: bouleDeFeu(cible); break;
        default: cout << "Veuillez choisir une action valide." << endl;
        }
    } while(numero < 0 || numero > 1);
}

void Magicien::bouleDeFeu(Paysan* cible) {
    int reussite, mana, degats;
    string somme;

    /*
     * On regarde si le joueur a assez de mana.
     */
    mana = Paysan::lancerDe(M_BF_MANA_DE, M_BF_MANA_DE_NIVEAU, somme);
    cout << endl << "Mana  : " << somme << endl;
    if(m_mana < mana) {
        cout << endl << m_nom << " n'a pas assez de mana." << endl;
        return;
    } else
        m_mana -= mana;

    /*
     * On s'assure que le joueur a réussie son abilité.
     */
    reussite = Paysan::lancerDe(1, 100, somme);
    if(reussite <= M_BF_REUSSITE) {
        /*
         * On génère le dégats et on l'inflige a l'ennemi.
         */
        degats = Paysan::lancerDe(M_BF_DEGATS_DE, M_BF_DEGATS_DE_NIVEAU, somme);
        cout << accent("Dégats: ") << somme << endl;

        cible->recevoirDegats(degats);
        cout << endl << m_nom << accent(" a infligé ") << degats
             << accent(" points de dégats") << accent(" à ")
             << cible->getNom() << " avec une boule de feu." << endl;
    } else {
        cout << endl << m_nom << accent(" n'a pas réussie à invoquer une boule de feu.")
             << endl;
    }
}

string Magicien::getClasse() const {
    return accent("magicien");
}
