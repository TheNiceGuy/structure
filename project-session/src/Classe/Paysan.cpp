#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "Prete.h"
#include "Guerrier.h"
#include "Magicien.h"
#include "Illusionniste.h"
#include "../Fonction/faccent.h"
#include "../config.h"

using namespace std;

int Paysan::compteur = 0;

Paysan::Paysan() {
    m_vie        = Paysan::lancerDe(3, 20, m_somme_vie);
    m_vieMax     = m_vie;
    m_mana       = 0;
    m_manaMax    = m_mana;
    m_aveugle    = false;
    m_priorite   = false;
    m_nom        = "SANS NOM";
    m_somme_mana = "aucun";
    m_arme       = NULL;

    compteur++;
}

Paysan::~Paysan() {
    delete m_arme;
    compteur--;
}

void Paysan::afficherAction() {
    /*
     * On affiche le choix de l'attaque avec une arme.
     */
    string degats( "[-"+to_string(m_arme->getDegatsDe())
                 + "d" +to_string(m_arme->getDegatsNbrDe())+"]");
    string reussite("["+to_string(m_arme->getReussite())+"%]");

    /*
     * On affiche les noms des colonnes
     */
    cout << "#   "
         << setw(ESPACEMENT_ACTION)   << left << "actions"
         << setw(ESPACEMENT_VIE)      << left << "vie"
         << setw(ESPACEMENT_MANA)     << left << "mana"
         << setw(ESPACEMENT_REUSSITE) << left << accent("réussite")
         << endl;

    /*
     * On affiche le choix d'une attaque normale.
     */
    cout << "0 - "
         << setw(ESPACEMENT_ACTION)   << left << "attaquer"
         << setw(ESPACEMENT_VIE)      << left << degats
         << setw(ESPACEMENT_MANA)     << left << "[0]"
         << setw(ESPACEMENT_REUSSITE) << left << reussite
         << endl;
}

void Paysan::affiche() const {
    cout << "Mon nom est " << m_nom << " et je suis un " << getClasse() << ". "
         << "J'ai " << m_vie << "HP et " << m_mana << "MP." << endl;
}

void Paysan::statut() const {
    string classe("["+getClasse()+"]");

    cout << setw(15) << right << m_nom
         << setw(20) << right << classe
         << setw(7)  << right << "HP: " << setw(2) << m_vie
         << setw(7)  << right << "MP: " << setw(2) << m_mana << endl;
}

void Paysan::recevoirDegats(int degats) {
    m_vie-=degats;
    if(m_vie < 0)
        m_vie = 0;
}

void Paysan::recevoirVie(int vie) {
    m_vie+=vie;
    if(m_vie > m_vieMax)
        m_vie = m_vieMax;
}

void Paysan::attaque(Paysan *cible) {
    int degats;

    /*
     * Cette vérification peut s'avérer utile si l'on continue le jeu
     * en ajoutant une abilité qui vole l'arme de l'ennemie.
     */
    if(m_arme == NULL) {
        cout << endl << "Vous n'avez pas d'arme en ce moment." << endl;
    } else {
        degats = m_arme->getDegats();

        /*
         * On regarde si l'attaque a été réussie.
         */
        if(degats != RATER) {
            cible->recevoirDegats(degats);
            cout << endl << m_nom << accent(" a infligé ") << degats
                 << accent(" points de dégats à ") << cible->getNom() << " avec un "
                 << m_arme->getNom() << "." << endl;
        } else {
            cout << endl << m_nom << accent(" a manqué ") << cible->getNom()
                 << " avec son " << m_arme->getNom() << "." << endl;
        }
    }
}

void Paysan::etreAveugler() {
    m_aveugle = true;
}

void Paysan::guerirAveugler() {
    m_aveugle = false;
}

bool Paysan::estVivant() const {
    if(m_vie > 0)
        return true;
    else
        return false;
}

bool Paysan::estAveugle() const {
    return m_aveugle;
}

bool Paysan::getPrioriter() const {
    return m_priorite;
}

string Paysan::getNom() const {
    return m_nom;
}

string Paysan::getSommeVie() const {
    return m_somme_vie;
}

string Paysan::getSommeMana() const {
    return m_somme_mana;
}

void Paysan::combat(Paysan* joueur1, Paysan* joueur2) {
    int tour, ronde(1);

    Paysan* joueurActuel;
    Paysan* joueurCible;

    /*
     * On détermine qui va commencer à jouer.
     */
    if(joueur1->getPrioriter() == joueur2->getPrioriter())
        tour = rand()%2+1;
    else if(joueur1->getPrioriter())
        tour = 1;
    else if(joueur2->getPrioriter())
        tour = 2;

    do {
        /*
         * On augmente le nombre de ronde.
         */
        ronde++;

        /*
         * On écrit le statut des deux joueurs.
         */
        system(CLEAR);
        cout << "Ronde #" << (ronde/2) << endl;
        joueur1->statut();
        joueur2->statut();
        cout << endl;

        /*
         * On utilise un pointeur vers les joueur actuel et joueur cible afin
         * de ne pas répéter le code deux fois.
         */
        if(tour == 1) {
            joueurActuel = joueur1;
            joueurCible  = joueur2;
            tour = 2;
        } else {
            joueurActuel = joueur2;
            joueurCible  = joueur1;
            tour = 1;
        }

        /*
         * Si le joueur actuel est aveugler, on passe son tour.
         */
        if(joueurActuel->estAveugle()) {
            cout << "C'est le tour de " << joueurActuel->getNom()
                 << ", mais il est aveugle. Il ne peut pas effectuer d'action "
                 << "en se moment." << endl;
            joueurActuel->guerirAveugler();
            system(PAUSE);
            continue;
        }

        cout << "C'est le tour de " << joueurActuel->getNom() << ". "
             << "Veuillez choisir une action:" << endl << endl;

        /*
         * On affiche les actions possibles et l'on demande au joueur
         * d'effectuer d'une action.
         */
        joueurActuel->afficherAction();
        cout << endl;
        joueurActuel->effectuerAction(joueurCible);

        system(PAUSE);
    } while(joueur1->estVivant() && joueur2->estVivant());

    /*
     * On écrit le statut des deux joueurs.
     */
    system(CLEAR);
    joueur1->statut();
    joueur2->statut();
    cout << endl;

    cout << joueurActuel->getNom() << accent(" a gagné le combat contre ")
         << joueurCible->getNom() << "! "
         << "Il y a eu un total de " << ronde/2 << " rondes dans ce combat."
         << endl;
}

int Paysan::lancerDe(int nbrDe, int niveauDe, string &lancer) {
    int i, de, somme(0);

    lancer = "";
    for(i = 0; i < nbrDe; i++) {
        de     = rand()%niveauDe+1;
        somme += de;

        lancer+=to_string(de);
        if(i < nbrDe-1)
            lancer+=string("+");
    }

    return somme;
}

Paysan* Paysan::choisirPersonnage() {
    int classe;
    string nom;
    Paysan* personnage;

    system(CLEAR);
    cout << "Quel nom voulez vous donner au personnage " << compteur+1 << "? ";
    cin >> nom;
    cout << endl;

    /*
     * TODO: Écrire les carastéristiques des classes (?)
     */
    cout << "Veuillez choisir la classe de " << nom << " parmis les suivantes."
         << endl << accent("[0] Prête | [1] Guerrier | [2] Magicien | ")
         << "[3] Illusionniste | [4] Quitter" << endl;

    do {
        cout << "Choix: ";
        cin >> classe;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            classe = -1;
        }

        if(classe < 0 || classe > 4)
            cout << "Veuillez choisir une classe valide!" << endl;
    } while(classe < 0 || classe > 4);
    cout << endl;

    switch(classe) {
    case 0: personnage = new Prete(nom); break;
    case 1: personnage = new Guerrier(nom); break;
    case 2: personnage = new Magicien(nom); break;
    case 3: personnage = new Illusionniste(nom); break;
    default: return NULL;
    }

    cout << "Vie : " << personnage->getSommeVie()  << endl;
    cout << "Mana: " << personnage->getSommeMana() << endl;

    return personnage;
}
