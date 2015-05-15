#ifndef MOTO_H
#define MOTO_H

#include "Vehicule.h"

class Moto : public Vehicule {
    public:
        Moto();
        Moto(int prix);
        virtual ~Moto();
        virtual int nbrRoues() const;
        virtual void affiche() const;
};

#endif
