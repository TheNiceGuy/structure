#ifndef MAGICIEN_H
#define MAGICIEN_H

#include <string>
#include "Paysan.h"
#include "../config.h"

/*
 * Constantes pour un magicien
 */
int const M_HP_DE(4);
int const M_HP_DE_NIVEAU(20);
int const M_MP_DE(3);
int const M_MP_DE_NIVEAU(20);

/*
 * Constantes pour l'arme d'un magicien
 */
int         const M_ARME_DE(4);
int         const M_ARME_DE_NIVEAU(4);
int         const M_ARME_DE_REUSSITE(90);
std::string const M_ARME_NOM("épée courte");

/*
 * Constantes pour une boule de feu
 */
int const M_BF_DEGATS_DE(2);
int const M_BF_DEGATS_DE_NIVEAU(20);
int const M_BF_MANA_DE(1);
int const M_BF_MANA_DE_NIVEAU(20);
int const M_BF_REUSSITE(75);

class Magicien : public Paysan {
    public:
        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Constructeur par defaut du magicien.
         */
        Magicien();

        /*
         * Entrée: le nom du personnage
         * Sortie: rien
         *
         * Constructeur surchargé du magicien.
         */
        Magicien(std::string nom);

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Destructeur par defaut du magicien.
         */
        virtual ~Magicien();

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Cette méthode affiche les actions possibles d'un magicien.
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
         * Cette méthode effectue une action.
         */
        void bouleDeFeu(Paysan* cible);

        /*
         * Entrée: rien
         * Sortie: le nom de la classe
         *
         * Cette méthode retourne le nom de la classe.
         */
        virtual std::string getClasse() const;
};

#endif
