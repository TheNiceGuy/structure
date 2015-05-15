#ifndef PAYSAN_H
#define PAYSAN_H

#include "Arme.h"
#include "../Fonction/faccent.h"
#include "../config.h"

/*
 * Constantes pour l'espacement dans l'affichage de certaines fonctions
 */
int const ESPACEMENT_ACTION(30);
int const ESPACEMENT_CLASSE(15);
int const ESPACEMENT_VIE(10);
int const ESPACEMENT_MANA(10);
int const ESPACEMENT_REUSSITE(10);

class Paysan {
    public:
        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Constructeur par defaut du paysan.
         */
        Paysan();

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Destructeur par defaut du paysan.
         */
        virtual ~Paysan();

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Cette m�thode affiche les actions possibles d'un paysan.
         */
        virtual void afficherAction();

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Cette m�thode effectue une action.
         */
        virtual void effectuerAction(Paysan* cible) = 0;

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Cette m�thode affiche les carast�ristiques du paysan.
         */
        void affiche() const;

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Cette m�thode affiche les carast�ristiques du paysan d'une
         * mani�re abr�g�e.
         */
        void statut() const;

        /*
         * Entr�e: le d�gats re�u
         * Sortie: rien
         *
         * Cette m�thode r�duit la vie du paysan.
         */
        void recevoirDegats(int degats);

        /*
         * Entr�e: la vie re�u
         * Sortie: rien
         *
         * Cette m�thode augmente la vie du paysan.
         */
        void recevoirVie(int vie);

        /*
         * Entr�e: un pointeur vers la cible
         * Sortie: rien
         *
         * Cette m�thode attaque une cible avec l'arme.
         */
        void attaque(Paysan *cible);

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Cette m�thode aveugle le paysan.
         */
        void etreAveugler();

        /*
         * Entr�e: rien
         * Sortie: rien
         *
         * Cette m�thode gu�rie le paysan de l'aveuglement.
         */
        void guerirAveugler();

        /*
         * Entr�e: rien
         * Sortie: true,  si le paysan est en vie
         *         false, si le paysan est mort
         *
         * Cette m�thode regarde si le paysan est en vie.
         */
        bool estVivant() const;

        /*
         * Entr�e: rien
         * Sortie: true,  si le paysan est aveugle
         *         false, si le paysan n'est pas aveugle
         *
         * Cette m�thode regarde si le paysan est aveugle.
         */
        bool estAveugle() const;

        /*
         * Entr�e: rien
         * Sortie: true,  si le paysan a priorit� dans le combat
         *         false, si le paysan n'a pas priorit� dans le combat
         *
         * Cette m�thode regarde si le paysan a priorit� dans le combat.
         */
        bool getPrioriter() const;

        /*
         * Entr�e: rien
         * Sortie: le nom du paysan
         *
         * Cette m�thode retourne le nom du paysan.
         */
        std::string getNom() const;

        /*
         * Entr�e: rien
         * Sortie: l'�quation qui d�termine la vie maximale
         *
         * Cette m�thode retourne l'�quation qui d�termine la vie maximale.
         */
        std::string getSommeVie() const;

        /*
         * Entr�e: rien
         * Sortie: l'�quation qui d�termine la mana maximale
         *
         * Cette m�thode retourne l'�quation qui d�termine la mana maximale.
         */
        std::string getSommeMana() const;

        /*
         * Entr�e: rien
         * Sortie: le nom de la classe
         *
         * Cette m�thode retourne le nom de la classe.
         */
        virtual std::string getClasse() const = 0;

        /*
         * Entr�e: un pointeur vers le paysan du joueur 1
         *         un pointeur vers le paysan du joueur 2
         * Sortie: rien
         *
         * Cette m�thode initie un combat jusqu'� la mort entre deux joueurs.
         */
        static void combat(Paysan* joueur1, Paysan* joueur2);

        /*
         * Entr�e: le nombre de d� � lancer
         *         le niveau des d�s � lancer
         *         une r�f�rence � un string qui va contenir l'addition des d�s
         * Sortie: la somme des d�s lanc�s
         *
         * Cette m�thode simule un lancer de plusieurs d�s de m�me niveau.
         */
        static int lancerDe(int nbrDe, int niveauDe, std::string &lancer);

        /*
         * Entr�e: rien
         * Sortie: un pointeur vers un nouveau paysan
         *
         * Cette m�thode cr�e un paysan. Il demande � l'utilisateur le nom ainsi
         * que la sp�cialisation du paysan.
         */
        static Paysan* choisirPersonnage();

    protected:
        /*
         * Cet attribut contient la vie du paysan.
         */
        int m_vie;

        /*
         * Cet attribut contient la vie maximale du paysan.
         */
        int m_vieMax;

        /*
         * Cet attribut contient la mana du paysan.
         */
        int m_mana;

        /*
         * Cet attribut contient la mana maximale du paysan.
         */
        int m_manaMax;

        /*
         * Cet attribut contient un bool qui d�termine si le paysan est aveugle
         * ou non.
         */
        bool m_aveugle;

        /*
         * Cet attribut contient un bool qui d�termine si le paysan a priorit�
         * ou non.
         */
        bool m_priorite;

        /*
         * Cet attribut contient le nom du paysan.
         */
        std::string m_nom;

        /*
         * Cet attribut contient l'�quation de la vie maximale.
         */
        std::string m_somme_vie;

        /*
         * Cet attribut contient l'�quation de la mana maximale.
         */
        std::string m_somme_mana;

        /*
         * Cet attribut contient pointeur vers l'arme du paysan.
         */
        Arme *m_arme;

        /*
         * Cet attribut static contient le nombre de paysan cr�er.
         */
        static int compteur;
};

#endif
