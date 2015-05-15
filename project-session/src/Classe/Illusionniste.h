#ifndef ILLUSIONNISTE_H
#define ILLUSIONNISTE_H

#include <string>
#include "Prete.h"
#include "../config.h"

/*
 * Constantes pour un illusionniste
 */
int const I_HP_DE(3);
int const I_HP_DE_NIVEAU(20);
int const I_MP_DE(1);
int const I_MP_DE_NIVEAU(20);

/*
 * Constantes pour l'arme d'un illusionniste
 */
int         const I_ARME_DE(3);
int         const I_ARME_DE_NIVEAU(4);
int         const I_ARME_DE_REUSSITE(90);
std::string const I_ARME_NOM("dague");

/*
 * Constantes pour l'aveuglement
 */
int const I_AV_DEGATS_DE(2);
int const I_AV_DEGATS_DE_NIVEAU(6);
int const I_AV_REUSSITE(50);

class Illusionniste : public Prete {
    public:
        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Constructeur par defaut de illusionniste.
         */
        Illusionniste();

        /*
         * Entr�e: le nom du personnage
         * Sortie: rien
         *
         * Constructeur surcharg� de illusionniste.
         */
        Illusionniste(std::string nom);

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Destructeur par defaut du illusionniste.
         */
        virtual ~Illusionniste();

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Cette m�thode affiche les actions possibles de l'illusionniste.
         */
        virtual void afficherAction();

        /*
         * Entr�e: un pointeur vers l'ennemi
         * Sortie: rien
         *
         * Cette m�thode effectue une action.
         */
        virtual void effectuerAction(Paysan* cible);

        /*
         * Entr�e: un pointeur vers la cible
         * Sortie: rien
         *
         * Cette m�thode aveugle la cible.
         */
        void aveuglement(Paysan* cible);

        /*
         * Entr�e: rien
         * Sortie: le nom de la classe
         *
         * Cette m�thode retourne le nom de la classe.
         */
        virtual std::string getClasse() const;
};

#endif
