#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Weapon.h"

#define MAX_HP 100

class Personnage {
    private:
        int m_hp;
        int m_mp;
        std::string m_name;

        Weapon m_weapon;

        void hurt(int dmg);
        bool is_alive();

    public:
        Personnage(std::string name);
        Personnage(std::string name, std::string weapon, int dmg);
        ~Personnage();

        void attack(Personnage &target);
        void drink_potion(int hp);
        void change_weapon(std::string weapon_name, int weapon_dmg);
};

#endif
