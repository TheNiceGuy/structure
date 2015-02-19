#include <iostream>
#include <stdlib.h>

using namespace std;

int fillArray(int* array, int array_size) {
    int counter;

    for(counter = 0; counter < array_size; counter++) {
        cout << "Valeur #" << (counter+1) << ":";
        cin >> array[counter];
        cin.ignore();
    }

    return 0;
}

int printArray(int* array, int array_size) {
    int counter;

    for(counter = 0; counter < array_size; counter++)
        cout << "[" << array[counter] << "] ";
    cout << endl;

    return 0;
}

int main() {
    int  array_size;
    int* array;

    cout << "Quelle taille voulez-vous donner à votre tableau? ";
    do {
        cin >> array_size;
        cin.ignore();

        if(array_size == 0)
            cout << "Veuillez entrer une valeur plus grande que 0: ";
        else if(array_size < 0)
            cout << "Veuillez entrer une valeur positive: ";
    } while(array_size <= 0);

    array = (int*)malloc(sizeof(int)*array_size);

    fillArray(array, array_size);
    printArray(array, array_size);

    free(array);

    return 0;
}
