#ifndef ARME_H
#define ARME_H

#include <string>
#include "../config.h"

/*
 * Valeur retourn�e lorsque l'attaque est manqu�
 */
int const RATER(-1);

class Arme {
    public:
        /*
         * Entr�e: le nombre de d�s du d�gats
                   le niveau de d� du d�gats
                   le pourcentage de r�ussite d'une attaque
                   le nom de l'arme
         * Sortie: rien
         *
         * Constructeur surcharg� d'une arme.
         */
        Arme(int degatsDe, int degatsNbrDe, int reussite, std::string nom);

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Destructeur par defaut d'une arme.
         */
        ~Arme();

        /*
         * Entr�e: rien
         * Sortie: une d�gats positif si l'attaque est r�ussie
         *         la constante RATER si l'attaque est manqu�
         *
         * Cette m�thode retourne un d�gats g�n�r� au hasard par l'arme.
         * Elle s'assure aussi que l'attaque est r�ussite.
         */
        int getDegats();

        /*
         * Entr�e: rien
         * Sortie: le nombre de d�s d'attaques
         *
         * Cette m�thode retourne le nombre de d�s d'attaques.
         */
        int getDegatsDe();

        /*
         * Entr�e: rien
         * Sortie: le nombre de d�s d'attaques
         *
         * Cette m�thode retourne le niveau des d�s d'attaques.
         */
        int getDegatsNbrDe();

        /*
         * Entr�e: rien
         * Sortie: le pourcentage de r�ussite
         *
         * Cette m�thode retourne le pourcentage de r�ussite.
         */
        int getReussite();

        /*
         * Entr�e: rien
         * Sortie: le nom de l'arme
         *
         * Cette m�thode retourne le nom de l'arme.
         */
        std::string getNom();

    private:
        /*
         * Cet attribut contient le nombre de d�s d'attaques
         */
        int m_degatsDe;

        /*
         * Cet attribut contient le niveau des d�s d'attaques
         */
        int m_degatsNbrDe;

        /*
         * Cet attribut contient le pourcentage de r�ussite
         */
        int m_reussite;

        /*
         * Cet attribut contient le nom de l'arme
         */
        std::string m_nom;
};

#endif
