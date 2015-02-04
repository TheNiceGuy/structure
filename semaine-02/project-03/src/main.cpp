#include <iostream>
#include <cstdlib>
#include "random.h"

#define THROW_NUMBER 500

using namespace std;

int main() {
    int i, nombre;
    int count[6] = {0, 0, 0, 0, 0, 0};

    srand(time(NULL));

    cout << "Here is the result for " << THROW_NUMBER <<" throws of a dice." << endl;
    for(i = 0; i < THROW_NUMBER; i++) {
        nombre = throwDice();
        cout << nombre+1 << " ";
        count[nombre]++;
    }

    cout << endl;

    for(i = 0; i < 6; i++) {
        cout << "Number of " << i+1 << ":\t" << count[i] << endl;
    }

    return 0;
}
