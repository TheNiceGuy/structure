#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon {
    private:
        std::string m_name;
        int m_dmg;

    public:
        Weapon();
        Weapon(std::string name, int dmg);
        ~Weapon();

        void change(std::string name, int dmg);
        void show() const;

        int get_dmg();
        std::string get_name();
};

#endif
