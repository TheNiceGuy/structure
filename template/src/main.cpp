/*
 * Auteur:
 * Date  : 
 */

#include <iostream>

using namespace std;

int main() {

#ifdef __linux__
    cout << "Veuillez appuyer sur une touche pour continuer...";
    cin.get();
#else
    system("pause");
#endif

    return 0;
}
