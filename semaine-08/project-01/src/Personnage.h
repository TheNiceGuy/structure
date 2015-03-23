#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <string>

#define MAX_HP 100

class Personnage {
    private:
        int m_hp;
        int m_mp;
        int m_weapon_dmg;
        std::string m_name;
        std::string m_weapon_name;

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
