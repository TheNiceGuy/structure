#include <iostream>
#include <iomanip>
#include "function.h"

using namespace std;

void print_point(point &p1) {
    cout << std::fixed;
    cout << std::setprecision(4);

    cout << "x: " << p1.get_x() << endl;
    cout << "y: " << p1.get_y() << endl;
    cout << "z: " << p1.get_z() << endl;
}

void copy_point(point &p1, point &p2) {
    p2.set_x(p1.get_x());
    p2.set_y(p1.get_y());
    p2.set_z(p1.get_z());
}

bool is_same_point(point &p1, point &p2) {
    int sum(0);

    sum = p1.get_x() - p2.get_x() +
          p1.get_y() - p2.get_y() +
          p1.get_z() - p2.get_z();

    /*
     * Is the sum equals zero, then they are equal. By casting
     * into an bool we get false since 0 = false. We have to
     * flip the bit in order to make it true.
     */
    return !(bool)sum;
}
