#ifndef GUERRIER_H
#define GUERRIER_H

#include <string>
#include "Paysan.h"
#include "../config.h"

/*
 * Constantes pour un guerrier
 */
int const G_HP_DE(7);
int const G_HP_DE_NIVEAU(20);

/*
 * Constantes pour l'arme d'un guerrier
 */
int         const G_ARME_DE(4);
int         const G_ARME_DE_NIVEAU(4);
int         const G_ARME_DE_REUSSITE(90);
std::string const G_ARME_NOM("hache tranchante");

/*
 * Constantes pour un coup de pied renversé
 */
int const G_CDPR_DE(2);
int const G_CDPR_DE_NIVEAU(6);
int const G_CDPR_REUSSITE(90);

class Guerrier : public Paysan {
    public:
        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Constructeur par defaut du guerrier.
         */
        Guerrier();

        /*
         * Entrée: le nom du personnage
         * Sortie: rien
         *
         * Constructeur surchargé du guerrier.
         */
        Guerrier(std::string nom);

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Destructeur par defaut du guerrier.
         */
        virtual ~Guerrier();

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Cette méthode affiche les actions possibles d'un guerrier.
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
         * Cette méthode donne un coup de pied renversé à la cible.
         */
        void coupeDePiedRenverse(Paysan* cible);

        /*
         * Entrée: rien
         * Sortie: le nom de la classe
         *
         * Cette méthode retourne le nom de la classe.
         */
        virtual std::string getClasse() const;
};

#endif
