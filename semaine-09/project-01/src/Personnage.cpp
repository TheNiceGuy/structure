#include <iostream>
#include <string>
#include "Personnage.h"

using namespace std;

Personnage::Personnage(string name) :
m_hp(MAX_HP),
m_name(name) {

}

Personnage::Personnage(string name, string weapon, int dmg) :
m_hp(MAX_HP),
m_name(name),
m_weapon(weapon, dmg) {

}

Personnage::~Personnage() {

}

void Personnage::hurt(int dmg) {
    m_hp = m_hp-dmg;

    if(!is_alive())
        m_hp = 0;
}

void Personnage::attack(Personnage &target) {
    target.hurt(m_weapon.get_dmg());

    cout << m_name << " utilise " << m_weapon.get_name()
         << " et inflige " << m_weapon.get_dmg()
         << (m_weapon.get_dmg()>1?" points":" point")
         << " de dégâts à " << target.m_name
         << "." << endl;
}

void Personnage::drink_potion(int hp) {
    m_hp = m_hp+hp;

    if(m_hp > MAX_HP)
        m_hp = MAX_HP;

    cout << m_name << " boit une potion de "
         << hp << (hp>1?" points":" point")
         << " de vie." << endl;
}

void Personnage::change_weapon(string weapon_name, int weapon_dmg) {
    m_weapon.change(weapon_name, weapon_dmg);

    cout << m_name << " change d'arme pour "
         << weapon_name << "." << endl;
}

bool Personnage::is_alive() {
    return (m_hp > 0);
}
