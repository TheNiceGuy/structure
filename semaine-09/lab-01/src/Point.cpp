#include "Point.h"

Point::Point(){
    m_x = 0.0;
    m_y = 0.0;
}

Point::Point(double x, double y) :
m_x(x),
m_y(y) {

}

void Point::set_x(double x) {
    m_x = x;
}

void Point::set_y(double y) {
    m_y = y;
}

void Point::set_point(double x, double y) {
    m_x = x;
    m_y = y;
}

double Point::get_x() {
    return m_x;
}

double Point::get_y() {
    return m_y;
}
