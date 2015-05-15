#include <iostream>
#include <iomanip>
#include <limits>
#include "Guerrier.h"

using namespace std;

Guerrier::Guerrier() {
    m_vie        = Paysan::lancerDe(G_HP_DE, G_HP_DE_NIVEAU, m_somme_vie);
    m_vieMax     = m_vie;
    m_mana       = 0;
    m_manaMax    = m_mana;
    m_aveugle    = false;
    m_priorite   = false;
    m_nom        = "SANS NOM";
    m_somme_mana = "";
    m_arme       = new Arme(G_ARME_DE, G_ARME_DE_NIVEAU, G_ARME_DE_REUSSITE,
                            accent(G_ARME_NOM));
}

Guerrier::Guerrier(std::string nom) {
    m_vie        = Paysan::lancerDe(G_HP_DE, G_HP_DE_NIVEAU, m_somme_vie);
    m_vieMax     = m_vie;
    m_mana       = 0;
    m_manaMax    = m_mana;
    m_aveugle    = false;
    m_priorite   = false;
    m_nom        = nom;
    m_somme_mana = "";
    m_arme       = new Arme(G_ARME_DE, G_ARME_DE_NIVEAU, G_ARME_DE_REUSSITE,
                            accent(G_ARME_NOM));
}

Guerrier::~Guerrier() {

}

void Guerrier::afficherAction() {
    string vie, reussite;

    Paysan::afficherAction();

    vie      = "[-"+to_string(G_CDPR_DE)
              +"d" +to_string(G_CDPR_DE_NIVEAU)+"]";
    reussite = "[" +to_string(G_CDPR_REUSSITE)+"%]";
    cout << "1 - "
         << setw(ESPACEMENT_ACTION)   << left << accent("coup de pied renversé")
         << setw(ESPACEMENT_VIE)      << left << vie
         << setw(ESPACEMENT_MANA)     << left << "[0]"
         << setw(ESPACEMENT_REUSSITE) << left << reussite
         << endl;
}

void Guerrier::coupeDePiedRenverse(Paysan* cible) {
    int reussite, degats;
    string somme;

    /*
     * On s'assure que le joueur a réussie son abilité.
     */
    reussite = Paysan::lancerDe(1, 100, somme);
    if(reussite <= G_CDPR_REUSSITE) {
        /*
         * On génère le dégats et on l'inflige a l'ennemi.
         */
        degats = Paysan::lancerDe(G_CDPR_DE, G_CDPR_DE_NIVEAU, somme);
        cout << endl << accent("Dégats: ") << somme << endl;

        cible->recevoirDegats(degats);
        cout << endl << m_nom << accent(" a infligé ") << degats << accent(" points de dégats à ")
             << cible->getNom() << accent(" avec un coup de pied renversé.") << endl;
    } else {
        cout << endl << m_nom << accent(" n'a pas réussie à donner un coup de pied renversé.") << endl;
    }
}

void Guerrier::effectuerAction(Paysan* cible) {
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
        case 1: coupeDePiedRenverse(cible); break;
        default: cout << "Veuillez choisir une action valide." << endl;
        }
    } while(numero < 0 || numero > 1);
}

string Guerrier::getClasse() const {
    return accent("guerrier");
}
