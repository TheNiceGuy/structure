#ifndef PRETE_H
#define PRETE_H

#include <string>
#include "Paysan.h"
#include "../config.h"

/*
 * Constantes pour un pr�te
 */
int const P_HP_DE(5);
int const P_HP_DE_NIVEAU(20);
int const P_MP_DE(2);
int const P_MP_DE_NIVEAU(20);

/*
 * Constantes pour l'arme d'un pr�te
 */
int         const P_ARME_DE(2);
int         const P_ARME_DE_NIVEAU(6);
int         const P_ARME_DE_REUSSITE(75);
std::string const P_ARME_NOM("marteau");

/*
 * Constantes pour l'attaque c�leste
 */
int const P_AC_DEGATS_DE(2);
int const P_AC_DEGATS_DE_NIVEAU(8);
int const P_AC_MANA_DE(1);
int const P_AC_MANA_DE_NIVEAU(10);
int const P_AC_REUSSITE(80);

/*
 * Constantes pour une gu�rison
 */
int const P_GU_VIE_DE(1);
int const P_GU_VIE_DE_NIVEAU(10);
int const P_GU_MANA_DE(1);
int const P_GU_MANA_DE_NIVEAU(8);
int const P_GU_REUSSITE(90);

class Prete : public Paysan {
    public:
        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Constructeur par defaut du pr�te.
         */
        Prete();

        /*
         * Entr�e: le nom du personnage
         * Sortie: rien
         *
         * Constructeur surcharg� du pr�te.
         */
        Prete(std::string nom);

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Destructeur par defaut du pr�te.
         */
        virtual ~Prete();

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Cette m�thode affiche les actions possibles d'un pr�te.
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
         * Cette m�thode invoque une attaque c�leste sur une cible.
         */
        void attaqueCeleste(Paysan* cible);

        /*
         * Entr�e: un pointeur vers la cible
         * Sortie: rien
         *
         * Cette m�thode invoque une gu�rison sur une cible. La cible est
         * variable dans le cas o� l'on vondrait gu�rir un autre personne
         * plustard.
         */
        void guerison(Paysan* cible);

        /*
         * Entr�e: rien
         * Sortie: le nom de la classe
         *
         * Cette m�thode retourne le nom de la classe.
         */
        virtual std::string getClasse() const;
};

#endif
