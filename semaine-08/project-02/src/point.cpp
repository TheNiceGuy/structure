#include "point.h"

point::point(){
    m_x = 0.0;
    m_y = 0.0;
    m_z = 0.0;
}

point::point(double x, double y, double z) :
m_x(x),
m_y(y),
m_z(z) {

}

void point::set_x(double x) {
    m_x = x;
}

void point::set_y(double y) {
    m_y = y;
}

void point::set_z(double z) {
    m_z = z;
}

double point::get_x() {
    return m_x;
}

double point::get_y() {
    return m_y;
}

double point::get_z() {
    return m_z;
}
