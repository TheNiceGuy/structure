#ifndef POINT_H
#define POINT_H

class Point {
    private:
        double m_x, m_y;

    public:
        /*
         * Entrée: rien
         * Sortie: rien
         *
         * Ce constructeur initialise la classe à les valeurs par defauts.
         */
        Point();

        /*
         * Entrée: les coordonnées en x et y
         * Sortie: rien
         *
         * Ce constructeur surchargé initialise la classe aux coordonnées données.
         */
        Point(double x, double y);

        /*
         * Entrée: un double contenant la coordonnée en x
         * Sortie: rien
         *
         * Cette fonction affecte un nouvelle coordonnée en x.
         */
        void set_x(double x);

        /*
         * Entrée: un double contenant la coordonnée en y
         * Sortie: rien
         *
         * Cette fonction affecte un nouvelle coordonnée en y.
         */
        void set_y(double y);

        /*
         * Entrée: les coordonnées en x et y
         * Sortie: rien
         *
         * Cette fonction affecte de nouvelles coordonnées au point.
         */
        void set_point(double x, double y);

        /*
         * Entrée: rien
         * Sortie: un double contenant la coordonnée en x
         *
         * Cette fonction retourne la coordonnée en x.
         */
        double get_x();

        /*
         * Entrée: rien
         * Sortie: un double contenant la coordonnée en y
         *
         * Cette fonction retourne la coordonnée en y.
         */
        double get_y();
};

#endif
