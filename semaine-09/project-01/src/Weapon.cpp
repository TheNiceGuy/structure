#include "Weapon.h"

using namespace std;

Weapon::Weapon() :
m_name("ses mains"),
m_dmg(5){

}

Weapon::Weapon(string name, int dmg) :
m_name(name),
m_dmg(dmg){

}

Weapon::~Weapon() {

}

void Weapon::change(string name, int dmg) {
    m_name = name;
    m_dmg  = dmg;
}

void Weapon::show() const {
    cout << "Arme : " << m_name << " (Dégâts : " << m_dmg << ")"
<< endl;
}

int Weapon::get_dmg() {
    return m_dmg;
}

string Weapon::get_name() {
    return m_name;
}
