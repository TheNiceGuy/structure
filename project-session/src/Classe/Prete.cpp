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
     * On affiche le choix de l'attaque c�leste.
     */
    vie      = "[-"+to_string(P_AC_DEGATS_DE)
              +"d" +to_string(P_AC_DEGATS_DE_NIVEAU)+"]";
    mana     = "[" +to_string(P_AC_MANA_DE)
              +"d" +to_string(P_AC_MANA_DE_NIVEAU)+"]";
    reussite = "[" +to_string(P_AC_REUSSITE)+"%]";
    cout << "1 - "
         << setw(ESPACEMENT_ACTION)   << left << accent("attaque c�leste")
         << setw(ESPACEMENT_VIE)      << left << vie
         << setw(ESPACEMENT_MANA)     << left << mana
         << setw(ESPACEMENT_REUSSITE) << left << reussite
         << endl;

    /*
     * On affiche le choix de la gu�rison.
     */
    vie      = "[+"+to_string(P_GU_VIE_DE)
              +"d" +to_string(P_GU_VIE_DE_NIVEAU)+"]";
    mana     = "[" +to_string(P_GU_MANA_DE)
              +"d" +to_string(P_GU_MANA_DE_NIVEAU)+"]";
    reussite = "[" +to_string(P_GU_REUSSITE)+"%]";
    cout << "2 - "
         << setw(ESPACEMENT_ACTION)   << left << accent("gu�rison")
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
         * On effectue l'action demand�e.
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
     * On s'assure que le joueur a r�ussie son abilit�.
     */
    reussite = Paysan::lancerDe(1, 100, somme);
    if(reussite <= P_AC_REUSSITE) {
        /*
         * On g�n�re le d�gats et on l'inflige a l'ennemi.
         */
        degats = Paysan::lancerDe(P_AC_DEGATS_DE, P_AC_DEGATS_DE_NIVEAU, somme);
        cout << accent("D�gats: ") << somme << endl;

        cible->recevoirDegats(degats);
        cout << endl << m_nom << accent(" a inflig� ") << degats
             << accent(" points de d�gats � ") << cible->getNom()
             << accent(" avec une attaque c�leste.") << endl;
    } else {
        cout << endl << m_nom << accent(" n'a pas r�ussie � invoquer une attaque ")
             << accent(" c�leste.") << endl;
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
     * On s'assure que le joueur a r�ussie son abilit�.
     */
    reussite = Paysan::lancerDe(1, 100, somme);
    if(reussite <= P_GU_REUSSITE) {
        /*
         * On g�n�re la vie et on l'affecte a la cible.
         */
        vie = Paysan::lancerDe(P_GU_VIE_DE, P_GU_VIE_DE_NIVEAU, somme);
        cout << "Vie : " << somme << endl;

        cible->recevoirVie(vie);
        if(m_nom == cible->getNom())
            cout << endl << m_nom << accent(" s'est gu�rie de ") << vie
                 << " points de vie." << endl;
        else
            cout << endl << m_nom << accent(" a redonn� ") << vie << " points de vie � "
                 << cible->getNom() << "." << endl;
    } else {
        cout << endl << m_nom << accent(" n'a pas r�ussie � invoquer une gu�rison.")
             << endl;
    }
}

string Prete::getClasse() const {
    return accent("pr�te");
}
