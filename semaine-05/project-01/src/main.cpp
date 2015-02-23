#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Entrée: entier [température en fahrenheit]
 * Sortie: double [température en celsius]
 * Rôle:   convertir une température de fahrenheit en celsius
 */
double toCelsius(int fahrenheit) {
    return (fahrenheit-32)*(5.0/9.0);
}

/*
 * Entrée: entier [température en celsius]
 * Sortie: double [température en fahrenheit]
 * Rôle:   convertir une température de celsius en fahrenheit
 */
double toFahrenheit(int celsius) {
    return celsius*(9.0/5.0)+32;
}

int main() {
    int tempC;
    int tempF;

    cout << setiosflags(ios::fixed | ios::showpoint) << setprecision(1);

    for(tempC = 0; tempC < 100; tempC++) {
        cout << tempC << " ºC" << setw(20) << toFahrenheit(tempC) << " ºF" << endl;
    }

    for(tempF = 0; tempF < 100; tempF++) {
        cout << tempF << " ºF" << setw(20) << toCelsius(tempF) << " ºC" << endl;
    }

    return 0;
}
