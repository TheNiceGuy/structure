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
         * Entrée: rien
         * Sortie: rien
         *
         * Constructeur par defaut de illusionniste.
         */
        Illusionniste();

        /*
         * Entrée: le nom du personnage
         * Sortie: rien
         *
         * Constructeur surchargé de illusionniste.
         */
        Illusionniste(std::string nom);

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Destructeur par defaut du illusionniste.
         */
        virtual ~Illusionniste();

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Cette méthode affiche les actions possibles de l'illusionniste.
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
         * Cette méthode aveugle la cible.
         */
        void aveuglement(Paysan* cible);

        /*
         * Entrée: rien
         * Sortie: le nom de la classe
         *
         * Cette méthode retourne le nom de la classe.
         */
        virtual std::string getClasse() const;
};

#endif
