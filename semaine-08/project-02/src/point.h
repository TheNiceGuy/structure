#ifndef POINT_H
#define POINT_H

class point {
    private:
        double m_x, m_y, m_z;

    public:
        point();
        point(double x, double y, double z);

        void set_x(double x);
        void set_y(double y);
        void set_z(double z);
        double get_x();
        double get_y();
        double get_z();
};

#endif
