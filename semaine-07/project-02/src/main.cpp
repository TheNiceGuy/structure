#include <iostream>

using namespace std;

int main() {
    int  nombre(420);
    int *ptr(0);

    ptr = &nombre;

    cout << "La case " << ptr << " contient " << *ptr << ".\n";

    return 0;
}
