#include <iostream>
#include <iomanip>
#include <limits>
#include "Illusionniste.h"

using namespace std;

Illusionniste::Illusionniste() {
    m_vie      = Paysan::lancerDe(I_HP_DE, I_HP_DE_NIVEAU, m_somme_vie);
    m_vieMax   = m_vie;
    m_mana     = Paysan::lancerDe(I_MP_DE, I_MP_DE_NIVEAU, m_somme_mana);
    m_manaMax  = m_mana;
    m_aveugle  = false;
    m_priorite = true;
    m_nom      = "SANS NOM";

    delete m_arme;
    m_arme     = new Arme(I_ARME_DE, I_ARME_DE_NIVEAU, I_ARME_DE_REUSSITE,
                          accent(I_ARME_NOM));
}

Illusionniste::Illusionniste(string nom) {
    m_vie      = Paysan::lancerDe(I_HP_DE, I_HP_DE_NIVEAU, m_somme_vie);
    m_vieMax   = m_vie;
    m_mana     = Paysan::lancerDe(I_MP_DE, I_MP_DE_NIVEAU, m_somme_mana);
    m_manaMax  = m_mana;
    m_aveugle  = false;
    m_priorite = true;
    m_nom      = nom;

    delete m_arme;
    m_arme     = new Arme(I_ARME_DE, I_ARME_DE_NIVEAU, I_ARME_DE_REUSSITE,
                          accent(I_ARME_NOM));
}

Illusionniste::~Illusionniste() {

}

void Illusionniste::afficherAction() {
    string vie, mana, reussite;

    Prete::afficherAction();

    vie      = "[-"+to_string(I_AV_DEGATS_DE)
              +"d" +to_string(I_AV_DEGATS_DE_NIVEAU)+"]";
    reussite = "[" +to_string(I_AV_REUSSITE)+"%]";
    cout << "3 - "
         << setw(ESPACEMENT_ACTION)   << left << accent("aveuglement")
         << setw(ESPACEMENT_VIE)      << left << vie
         << setw(ESPACEMENT_MANA)     << left << "[0]"
         << setw(ESPACEMENT_REUSSITE) << left << reussite
         << endl;
}

void Illusionniste::effectuerAction(Paysan* cible) {
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
        case 1: attaqueCeleste(cible); break;
        case 2: guerison(this); break;
        case 3: aveuglement(cible); break;
        default: cout << "Veuillez choisir une action valide." << endl;
        }
    } while(numero < 0 || numero > 3);
}

void Illusionniste::aveuglement(Paysan* cible) {
    int reussite, degats;
    string somme;

    /*
     * On s'assure que le joueur a réussie son abilité.
     */
    reussite = Paysan::lancerDe(1, 100, somme);
    if(reussite <= I_AV_REUSSITE) {
        /*
         * On génère le dégats et on l'inflige a l'ennemi.
         */
        degats = Paysan::lancerDe(I_AV_DEGATS_DE, I_AV_DEGATS_DE_NIVEAU, somme);
        cout << endl << accent("Dégats: ") << somme << endl;

        cible->etreAveugler();
        cible->recevoirDegats(degats);
        cout << endl << m_nom << accent(" a infligé ") << degats << accent(" points de dégats")
             << accent(" à ") << cible->getNom() << " en l'aveuglant." << endl;
    } else {
        cout << endl << m_nom << accent(" n'a pas réussie à aveugler ")
             << cible->getNom() << "." << endl;
    }
}

string Illusionniste::getClasse() const {
    return accent("illusionniste");
}
