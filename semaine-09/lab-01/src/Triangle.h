#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"

#define A_X_DEFAUT 0.0
#define A_Y_DEFAUT 0.0
#define B_X_DEFAUT 4.0
#define B_Y_DEFAUT 0.0
#define C_X_DEFAUT 0.0
#define C_Y_DEFAUT 3.0

class Triangle {
    private:
        Point m_pA;
        Point m_pB;
        Point m_pC;

    public:
        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Ce constructeur initialise la classe à les valeurs par defauts.
         */
        Triangle();

        /*
         * Entrée: 3 points
         * Sortie: rien
         *
         * Ce constructeur surchargé initialise la classe aux points données.
         */
        Triangle(Point &pA, Point &pB, Point &pC);

        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Ce destructeur n'a pas encore de but.
         */
        ~Triangle();

        /*
         * Entrée: rien
         * Sortie: un double contenant la longueur du coté opposé au point A
         *
         * Cette fonction renvoit la longueur du coté opposé au point A.
         */
        double get_longueur_A();

        /*
         * Entrée: rien
         * Sortie: un double contenant la longueur du coté opposé au point B
         *
         * Cette fonction renvoit la longueur du coté opposé au point B.
         */
        double get_longueur_B();

        /*
         * Entrée: rien
         * Sortie: un double contenant la longueur du coté opposé au point C
         *
         * Cette fonction renvoit la longueur du coté opposé au point C.
         */
        double get_longueur_C();

        /*
         * Entrée: rien
         * Sortie: un double contenant l'angle au point A.
         *
         * Cette fonction renvoit l'angle au point A.
         */
        double get_angle_A();

        /*
         * Entrée: rien
         * Sortie: un double contenant l'angle au point B.
         *
         * Cette fonction renvoit l'angle au point B.
         */
        double get_angle_B();

        /*
         * Entrée: rien
         * Sortie: un double contenant l'angle au point C.
         *
         * Cette fonction renvoit l'angle au point C.
         */
        double get_angle_C();
};

#endif
