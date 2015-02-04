#include <iostream>

using namespace std;

int addTwo(int a) {
    return a+2;
}

int cube(int a) {
    return a*a*a;
}

int main() {
    int a(2);

    cout << "addTwo(" << a << ") = " << addTwo(a) << endl;
    cout << "cube(" << a << ")   = " << cube(a) << endl;

    return 0;
}
