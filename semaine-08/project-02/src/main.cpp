#include <iostream>
#include "point.h"
#include "function.h"

using namespace std;

void print_variables(point &p1,point &p2) {
    cout << "Point 1:" << endl;
    print_point(p1);
    cout << "Point 2:" << endl;
    print_point(p2);
}

void print_difference(point &p1,point &p2) {
    cout << "Les deux points sont "
         << (is_same_point(p1, p2)?"pareilles":"différents")
         << "." << endl;
}

int main() {
    point p1 = point(1, 2, 3);
    point p2 = point();

    print_variables(p1, p2);
    print_difference(p1, p2);

    cout << endl << "Copie du premier point dans le deuxième..." << endl;
    copy_point(p1 ,p2);

    print_variables(p1, p2);
    print_difference(p1, p2);

    return 0;
}
