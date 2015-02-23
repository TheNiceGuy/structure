#include <iostream>

#define FILLED "**"
#define SPACED "  "

using namespace std;

void draw_limit(int size, bool reversed) {
    int j;

    if(reversed) {
        for(j = 0; j < size; j++) {
            if(j >= size/2 || j == 0)
                cout << FILLED;
            else
                cout << SPACED;
        }
    } else {
        for(j = 0; j < size; j++) {
            if(j <= size/2 || j == size-1)
                cout << FILLED;
            else
                cout << SPACED;
        }
    }
    cout << endl;
}

void draw_middle(int size, bool reversed) {
    int j;

    for(j = 0; j < size; j++) {
        if(reversed) {
            if(j == 0 || j == (size-1)/2)
                cout << FILLED;
            else
                cout << SPACED;
        } else {
            if(j == size-1 || j == (size-1)/2)
                cout << FILLED;
            else
                cout << SPACED;
        }
    }
    cout << endl;
}

void draw_middle_line(int size) {
    int j;

    for(j = 0; j < size; j++) {
        cout << FILLED;
    }
    cout << endl;
}

void draw(int size) {
    int i;

    if(size%2 == 0)
        size++;

    for(i = 0; i < size; i++) {
        if(i == 0)
            draw_limit(size, false);
        else if(i == size-1)
            draw_limit(size, true);
        else if(i < (size-1)/2)
            draw_middle(size, false);
        else if(i > (size-1)/2)
            draw_middle(size, true);
        else
            draw_middle_line(size);
    }
}

int main() {
    int i;

    for(i = 0; i < 40; i = i+2) {
        draw(i);
        cout << endl;
    }
    return 0;
}
