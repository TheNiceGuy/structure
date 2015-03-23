#include <iostream>
#include <string>
#include "Personnage.h"

using namespace std;

int main() {
    Personnage stallman = Personnage("Richard Stallman", "les Logiciels Libres", 5);
    Personnage liam = Personnage("Liam Neeson", "un Magnum", 20);

    stallman.attack(liam);
    liam.drink_potion(20);

    cout << endl;
    stallman.attack(liam);
    liam.attack(stallman);

    cout << endl;
    stallman.change_weapon("un AA-12", 60);
    stallman.attack(liam);
    liam.attack(stallman);

    return 0;
}
