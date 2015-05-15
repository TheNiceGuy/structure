#include <iostream>
#include "Point.h"
#include "Triangle.h"
#include "function.h"

using namespace std;

int main() {
    Point pA(-5, -52);
    Point pB(-10,  0);
    Point pC( 5.44, -2);

    Triangle triangle(pA, pB, pC);

    cout << "Coté A: " << triangle.get_longueur_A() << endl;
    cout << "Coté B: " << triangle.get_longueur_B() << endl;
    cout << "Coté C: " << triangle.get_longueur_C() << endl;
    cout << "Angle A: " << triangle.get_angle_A() << endl;
    cout << "Angle B: " << triangle.get_angle_B() << endl;
    cout << "Angle C: " << triangle.get_angle_C() << endl;

    cout << "La somme de ces angles est de "
         << triangle.get_angle_A()+triangle.get_angle_B()+triangle.get_angle_C()
         << " degrées." << endl;

    return 0;
}
