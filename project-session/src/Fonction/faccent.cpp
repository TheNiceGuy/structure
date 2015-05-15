#include <iomanip>
#include <string>
#ifndef __linux__
    #include <windows.h>
#endif
#include "faccent.h"

using namespace std;

string accent(string tab) {
#ifdef __linux__
    return tab;
#else
    char buffer[512];
    CharToOemA(tab.c_str(), buffer);
    string str(buffer);
    return str;
#endif
}
