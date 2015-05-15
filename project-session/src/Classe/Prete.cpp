#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "Prete.h"

using namespace std;

Prete::Prete() {
    m_vie      = Paysan::lancerDe(P_HP_DE, P_HP_DE_NIVEAU, m_somme_vie);
    m_vieMax   = m_vie;
    m_mana     = Paysan::lancerDe(P_MP_DE, P_MP_DE_NIVEAU, m_somme_mana);
    m_manaMax  = m_mana;
    m_aveugle  = false;
    m_priorite = false;
    m_nom      = "SANS NOM";
    m_arme     = new Arme(P_ARME_DE, P_ARME_DE_NIVEAU, P_ARME_DE_REUSSITE,
                          accent(P_ARME_NOM));
}

Prete::Prete(string nom) {
    m_vie      = Paysan::lancerDe(P_HP_DE, P_HP_DE_NIVEAU, m_somme_vie);
    m_vieMax   = m_vie;
    m_mana     = Paysan::lancerDe(P_MP_DE, P_MP_DE_NIVEAU, m_somme_mana);
    m_manaMax  = m_mana;
    m_aveugle  = false;
    m_priorite = false;
    m_nom      = nom;
    m_arme     = new Arme(P_ARME_DE, P_ARME_DE_NIVEAU, P_ARME_DE_REUSSITE,
                          accent(P_ARME_NOM));
}

Prete::~Prete() {

}

void Prete::afficherAction() {
    string vie, mana, reussite;

    Paysan::afficherAction();

    /*
     * On affiche le choix de l'attaque céleste.
     */
    vie      = "[-"+to_string(P_AC_DEGATS_DE)
              +"d" +to_string(P_AC_DEGATS_DE_NIVEAU)+"]";
    mana     = "[" +to_string(P_AC_MANA_DE)
              +"d" +to_string(P_AC_MANA_DE_NIVEAU)+"]";
    reussite = "[" +to_string(P_AC_REUSSITE)+"%]";
    cout << "1 - "
         << setw(ESPACEMENT_ACTION)   << left << accent("attaque céleste")
         << setw(ESPACEMENT_VIE)      << left << vie
         << setw(ESPACEMENT_MANA)     << left << mana
         << setw(ESPACEMENT_REUSSITE) << left << reussite
         << endl;

    /*
     * On affiche le choix de la guérison.
     */
    vie      = "[+"+to_string(P_GU_VIE_DE)
              +"d" +to_string(P_GU_VIE_DE_NIVEAU)+"]";
    mana     = "[" +to_string(P_GU_MANA_DE)
              +"d" +to_string(P_GU_MANA_DE_NIVEAU)+"]";
    reussite = "[" +to_string(P_GU_REUSSITE)+"%]";
    cout << "2 - "
         << setw(ESPACEMENT_ACTION)   << left << accent("guérison")
         << setw(ESPACEMENT_VIE)      << left << vie
         << setw(ESPACEMENT_MANA)     << left << mana
         << setw(ESPACEMENT_REUSSITE) << left << reussite
         << endl;
}

void Prete::effectuerAction(Paysan* cible) {
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
        default: cout << "Veuillez choisir une action valide." << endl;
        }
    } while(numero < 0 || numero > 2);
}

void Prete::attaqueCeleste(Paysan* cible) {
    int reussite, mana, degats;
    string somme;

    /*
     * On regarde si le joueur a assez de mana.
     */
    mana = Paysan::lancerDe(P_AC_MANA_DE, P_AC_MANA_DE_NIVEAU, somme);
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
    if(reussite <= P_AC_REUSSITE) {
        /*
         * On génère le dégats et on l'inflige a l'ennemi.
         */
        degats = Paysan::lancerDe(P_AC_DEGATS_DE, P_AC_DEGATS_DE_NIVEAU, somme);
        cout << accent("Dégats: ") << somme << endl;

        cible->recevoirDegats(degats);
        cout << endl << m_nom << accent(" a infligé ") << degats
             << accent(" points de dégats à ") << cible->getNom()
             << accent(" avec une attaque céleste.") << endl;
    } else {
        cout << endl << m_nom << accent(" n'a pas réussie à invoquer une attaque ")
             << accent(" céleste.") << endl;
    }
}

void Prete::guerison(Paysan* cible) {
    int reussite, mana, vie;
    string somme;

    /*
     * On regarde si le joueur a assez de mana.
     */
    mana = Paysan::lancerDe(P_GU_MANA_DE, P_GU_MANA_DE_NIVEAU, somme);
    cout << endl << "Mana: " << somme << endl;
    if(m_mana < mana) {
        cout << endl << m_nom << " n'a pas assez de mana." << endl;
        return;
    } else
        m_mana -= mana;

    /*
     * On s'assure que le joueur a réussie son abilité.
     */
    reussite = Paysan::lancerDe(1, 100, somme);
    if(reussite <= P_GU_REUSSITE) {
        /*
         * On génère la vie et on l'affecte a la cible.
         */
        vie = Paysan::lancerDe(P_GU_VIE_DE, P_GU_VIE_DE_NIVEAU, somme);
        cout << "Vie : " << somme << endl;

        cible->recevoirVie(vie);
        if(m_nom == cible->getNom())
            cout << endl << m_nom << accent(" s'est guérie de ") << vie
                 << " points de vie." << endl;
        else
            cout << endl << m_nom << accent(" a redonné ") << vie << " points de vie à "
                 << cible->getNom() << "." << endl;
    } else {
        cout << endl << m_nom << accent(" n'a pas réussie à invoquer une guérison.")
             << endl;
    }
}

string Prete::getClasse() const {
    return accent("prête");
}
