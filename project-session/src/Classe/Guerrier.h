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
 * Constantes pour un coup de pied renvers�
 */
int const G_CDPR_DE(2);
int const G_CDPR_DE_NIVEAU(6);
int const G_CDPR_REUSSITE(90);

class Guerrier : public Paysan {
    public:
        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Constructeur par defaut du guerrier.
         */
        Guerrier();

        /*
         * Entr�e: le nom du personnage
         * Sortie: rien
         *
         * Constructeur surcharg� du guerrier.
         */
        Guerrier(std::string nom);

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Destructeur par defaut du guerrier.
         */
        virtual ~Guerrier();

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Cette m�thode affiche les actions possibles d'un guerrier.
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
         * Cette m�thode donne un coup de pied renvers� � la cible.
         */
        void coupeDePiedRenverse(Paysan* cible);

        /*
         * Entr�e: rien
         * Sortie: le nom de la classe
         *
         * Cette m�thode retourne le nom de la classe.
         */
        virtual std::string getClasse() const;
};

#endif
