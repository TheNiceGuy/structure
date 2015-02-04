#include <iostream>
#include "function.h"

using namespace std;

int main() {
    int a(2);

    cout << "addTwo(" << a << ") = " << addTwo(a) << endl;
    cout << "cube(" << a << ")   = " << cube(a) << endl;

    return 0;
}
