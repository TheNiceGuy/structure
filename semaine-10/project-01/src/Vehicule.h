#ifndef VEHICULE_H
#define VEHICULE_H

class Vehicule {
    public:
        Vehicule();
        Vehicule(int prix);
        virtual ~Vehicule();
        virtual int nbrRoues() const = 0;
        virtual void affiche() const;
        
        static int nombreInstances();

    protected:
        int m_prix;

        static int compteur;
};

#endif
