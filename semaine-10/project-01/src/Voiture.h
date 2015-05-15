#ifndef VOITURE_H
#define VOITURE_H

#include "Vehicule.h"

class Voiture : public Vehicule {
    public:
        Voiture();
        Voiture(int prix, int nb_porte);
        virtual ~Voiture();
        virtual int nbrRoues() const;
        virtual void affiche() const;

    private:
        int m_porte;
};

#endif
