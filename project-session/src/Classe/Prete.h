#ifndef PRETE_H
#define PRETE_H

#include <string>
#include "Paysan.h"
#include "../config.h"

/*
 * Constantes pour un prête
 */
int const P_HP_DE(5);
int const P_HP_DE_NIVEAU(20);
int const P_MP_DE(2);
int const P_MP_DE_NIVEAU(20);

/*
 * Constantes pour l'arme d'un prête
 */
int         const P_ARME_DE(2);
int         const P_ARME_DE_NIVEAU(6);
int         const P_ARME_DE_REUSSITE(75);
std::string const P_ARME_NOM("marteau");

/*
 * Constantes pour l'attaque céleste
 */
int const P_AC_DEGATS_DE(2);
int const P_AC_DEGATS_DE_NIVEAU(8);
int const P_AC_MANA_DE(1);
int const P_AC_MANA_DE_NIVEAU(10);
int const P_AC_REUSSITE(80);

/*
 * Constantes pour une guérison
 */
int const P_GU_VIE_DE(1);
int const P_GU_VIE_DE_NIVEAU(10);
int const P_GU_MANA_DE(1);
int const P_GU_MANA_DE_NIVEAU(8);
int const P_GU_REUSSITE(90);

class Prete : public Paysan {
    public:
        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Constructeur par defaut du prête.
         */
        Prete();

        /*
         * Entrée: le nom du personnage
         * Sortie: rien
         *
         * Constructeur surchargé du prête.
         */
        Prete(std::string nom);

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Destructeur par defaut du prête.
         */
        virtual ~Prete();

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Cette méthode affiche les actions possibles d'un prête.
         */
        virtual void afficherAction();

        /*
         * Entrée: un pointeur vers l'ennemi
         * Sortie: rien
         *
         * Cette méthode effectue une action.
         */
        virtual void effectuerAction(Paysan* cible);

        /*
         * Entrée: un pointeur vers la cible
         * Sortie: rien
         *
         * Cette méthode invoque une attaque céleste sur une cible.
         */
        void attaqueCeleste(Paysan* cible);

        /*
         * Entrée: un pointeur vers la cible
         * Sortie: rien
         *
         * Cette méthode invoque une guérison sur une cible. La cible est
         * variable dans le cas où l'on vondrait guérir un autre personne
         * plustard.
         */
        void guerison(Paysan* cible);

        /*
         * Entrée: rien
         * Sortie: le nom de la classe
         *
         * Cette méthode retourne le nom de la classe.
         */
        virtual std::string getClasse() const;
};

#endif
