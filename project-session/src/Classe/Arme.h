#ifndef ARME_H
#define ARME_H

#include <string>
#include "../config.h"

/*
 * Valeur retournée lorsque l'attaque est manqué
 */
int const RATER(-1);

class Arme {
    public:
        /*
         * Entrée: le nombre de dés du dégats
                   le niveau de dé du dégats
                   le pourcentage de réussite d'une attaque
                   le nom de l'arme
         * Sortie: rien
         *
         * Constructeur surchargé d'une arme.
         */
        Arme(int degatsDe, int degatsNbrDe, int reussite, std::string nom);

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Destructeur par defaut d'une arme.
         */
        ~Arme();

        /*
         * Entrée: rien
         * Sortie: une dégats positif si l'attaque est réussie
         *         la constante RATER si l'attaque est manqué
         *
         * Cette méthode retourne un dégats généré au hasard par l'arme.
         * Elle s'assure aussi que l'attaque est réussite.
         */
        int getDegats();

        /*
         * Entrée: rien
         * Sortie: le nombre de dés d'attaques
         *
         * Cette méthode retourne le nombre de dés d'attaques.
         */
        int getDegatsDe();

        /*
         * Entrée: rien
         * Sortie: le nombre de dés d'attaques
         *
         * Cette méthode retourne le niveau des dés d'attaques.
         */
        int getDegatsNbrDe();

        /*
         * Entrée: rien
         * Sortie: le pourcentage de réussite
         *
         * Cette méthode retourne le pourcentage de réussite.
         */
        int getReussite();

        /*
         * Entrée: rien
         * Sortie: le nom de l'arme
         *
         * Cette méthode retourne le nom de l'arme.
         */
        std::string getNom();

    private:
        /*
         * Cet attribut contient le nombre de dés d'attaques
         */
        int m_degatsDe;

        /*
         * Cet attribut contient le niveau des dés d'attaques
         */
        int m_degatsNbrDe;

        /*
         * Cet attribut contient le pourcentage de réussite
         */
        int m_reussite;

        /*
         * Cet attribut contient le nom de l'arme
         */
        std::string m_nom;
};

#endif
