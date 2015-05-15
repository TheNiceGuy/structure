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
         * Entrée: rien
         * Sortie: rien
         *
         * Constructeur par defaut du paysan.
         */
        Paysan();

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Destructeur par defaut du paysan.
         */
        virtual ~Paysan();

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Cette méthode affiche les actions possibles d'un paysan.
         */
        virtual void afficherAction();

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Cette méthode effectue une action.
         */
        virtual void effectuerAction(Paysan* cible) = 0;

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Cette méthode affiche les carastéristiques du paysan.
         */
        void affiche() const;

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Cette méthode affiche les carastéristiques du paysan d'une
         * manière abrégée.
         */
        void statut() const;

        /*
         * Entrée: le dégats reçu
         * Sortie: rien
         *
         * Cette méthode réduit la vie du paysan.
         */
        void recevoirDegats(int degats);

        /*
         * Entrée: la vie reçu
         * Sortie: rien
         *
         * Cette méthode augmente la vie du paysan.
         */
        void recevoirVie(int vie);

        /*
         * Entrée: un pointeur vers la cible
         * Sortie: rien
         *
         * Cette méthode attaque une cible avec l'arme.
         */
        void attaque(Paysan *cible);

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Cette méthode aveugle le paysan.
         */
        void etreAveugler();

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Cette méthode guérie le paysan de l'aveuglement.
         */
        void guerirAveugler();

        /*
         * Entrée: rien
         * Sortie: true,  si le paysan est en vie
         *         false, si le paysan est mort
         *
         * Cette méthode regarde si le paysan est en vie.
         */
        bool estVivant() const;

        /*
         * Entrée: rien
         * Sortie: true,  si le paysan est aveugle
         *         false, si le paysan n'est pas aveugle
         *
         * Cette méthode regarde si le paysan est aveugle.
         */
        bool estAveugle() const;

        /*
         * Entrée: rien
         * Sortie: true,  si le paysan a priorité dans le combat
         *         false, si le paysan n'a pas priorité dans le combat
         *
         * Cette méthode regarde si le paysan a priorité dans le combat.
         */
        bool getPrioriter() const;

        /*
         * Entrée: rien
         * Sortie: le nom du paysan
         *
         * Cette méthode retourne le nom du paysan.
         */
        std::string getNom() const;

        /*
         * Entrée: rien
         * Sortie: l'équation qui détermine la vie maximale
         *
         * Cette méthode retourne l'équation qui détermine la vie maximale.
         */
        std::string getSommeVie() const;

        /*
         * Entrée: rien
         * Sortie: l'équation qui détermine la mana maximale
         *
         * Cette méthode retourne l'équation qui détermine la mana maximale.
         */
        std::string getSommeMana() const;

        /*
         * Entrée: rien
         * Sortie: le nom de la classe
         *
         * Cette méthode retourne le nom de la classe.
         */
        virtual std::string getClasse() const = 0;

        /*
         * Entrée: un pointeur vers le paysan du joueur 1
         *         un pointeur vers le paysan du joueur 2
         * Sortie: rien
         *
         * Cette méthode initie un combat jusqu'à la mort entre deux joueurs.
         */
        static void combat(Paysan* joueur1, Paysan* joueur2);

        /*
         * Entrée: le nombre de dé à lancer
         *         le niveau des dés à lancer
         *         une référence à un string qui va contenir l'addition des dés
         * Sortie: la somme des dés lancés
         *
         * Cette méthode simule un lancer de plusieurs dés de même niveau.
         */
        static int lancerDe(int nbrDe, int niveauDe, std::string &lancer);

        /*
         * Entrée: rien
         * Sortie: un pointeur vers un nouveau paysan
         *
         * Cette méthode crée un paysan. Il demande à l'utilisateur le nom ainsi
         * que la spécialisation du paysan.
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
         * Cet attribut contient un bool qui détermine si le paysan est aveugle
         * ou non.
         */
        bool m_aveugle;

        /*
         * Cet attribut contient un bool qui détermine si le paysan a priorité
         * ou non.
         */
        bool m_priorite;

        /*
         * Cet attribut contient le nom du paysan.
         */
        std::string m_nom;

        /*
         * Cet attribut contient l'équation de la vie maximale.
         */
        std::string m_somme_vie;

        /*
         * Cet attribut contient l'équation de la mana maximale.
         */
        std::string m_somme_mana;

        /*
         * Cet attribut contient pointeur vers l'arme du paysan.
         */
        Arme *m_arme;

        /*
         * Cet attribut static contient le nombre de paysan créer.
         */
        static int compteur;
};

#endif
