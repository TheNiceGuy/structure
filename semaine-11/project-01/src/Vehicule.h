#ifndef VEHICULE_H
#define VEHICULE_H

class Vehicule {
    public:
        Vehicule();
        Vehicule(int prix);
        virtual ~Vehicule();
        virtual void affiche() const;
        static int nombreInstances;

    protected:
        int m_prix;
};

#endif
