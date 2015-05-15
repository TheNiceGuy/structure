#include <iostream>
#include <cmath>
#include "Triangle.h"
#include "function.h"

using namespace std;

Triangle::Triangle() :
m_pA(A_X_DEFAUT, A_Y_DEFAUT),
m_pB(B_X_DEFAUT, B_Y_DEFAUT),
m_pC(C_X_DEFAUT, C_Y_DEFAUT) {

}

Triangle::Triangle(Point &pA, Point &pB, Point &pC) :
m_pA(pA.get_x(), pA.get_y()),
m_pB(pB.get_x(), pB.get_y()),
m_pC(pC.get_x(), pC.get_y()) {
    if(is_same_point(m_pA, m_pB) ||
       is_same_point(m_pB, m_pC) ||
       is_same_point(m_pC, m_pA)) {
        cout << "Il y a des points pareilles. Les valeurs par defauts " <<
                "sont utilisées." << endl;
        m_pA.set_point(A_X_DEFAUT, A_Y_DEFAUT);
        m_pB.set_point(B_X_DEFAUT, B_Y_DEFAUT);
        m_pC.set_point(C_X_DEFAUT, C_Y_DEFAUT);
    }
}

Triangle::~Triangle() {
}

double Triangle::get_longueur_A() {
    double dx, dy;

    dx = m_pB.get_x() - m_pC.get_x();
    dy = m_pB.get_y() - m_pC.get_y();

    return sqrt(pow(dx, 2)+pow(dy, 2));
}

double Triangle::get_longueur_B() {
    double dx, dy;

    dx = m_pA.get_x() - m_pC.get_x();
    dy = m_pA.get_y() - m_pC.get_y();

    return sqrt(pow(dx, 2)+pow(dy, 2));
}

double Triangle::get_longueur_C() {
    double dx, dy;

    dx = m_pA.get_x() - m_pB.get_x();
    dy = m_pA.get_y() - m_pB.get_y();

    return sqrt(pow(dx, 2)+pow(dy, 2));
}

double Triangle::get_angle_A() {
    double l_A, l_B, l_C, temp;

    l_A = get_longueur_A();
    l_B = get_longueur_B();
    l_C = get_longueur_C();

    temp = (pow(l_B, 2)+pow(l_C, 2)-pow(l_A, 2))/(2*l_B*l_C);

    return rad_to_deg(acos(temp));
}

double Triangle::get_angle_B() {
    double l_A, l_B, l_C, temp;

    l_A = get_longueur_A();
    l_B = get_longueur_B();
    l_C = get_longueur_C();

    temp = (pow(l_A, 2)+pow(l_C, 2)-pow(l_B, 2))/(2*l_A*l_C);

    return rad_to_deg(acos(temp));
}

double Triangle::get_angle_C() {
    double l_A, l_B, l_C, temp;

    l_A = get_longueur_A();
    l_B = get_longueur_B();
    l_C = get_longueur_C();

    temp = (pow(l_A, 2)+pow(l_B, 2)-pow(l_C, 2))/(2*l_A*l_B);

    return rad_to_deg(acos(temp));
}
