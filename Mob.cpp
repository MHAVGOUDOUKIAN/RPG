#include <iostream>
#include "Mob.hpp"
#include "Perso.hpp"

using namespace std;

// Constructeurs
Mob::Mob(const float santeMax, const float santeAct, const float armure, const float resistance,
const int level, const std::string name, const int val_gold, const int val_exp, const float dmg): Interface() ,_santeMax(santeMax),
_santeAct(santeAct), _armure(armure), _resistance(resistance), _level(level), _name(name),
_val_gold(val_gold), _val_exp(val_exp), _cible(NULL), _dmg(dmg)
{}

Mob::Mob(const float santeMax, const float santeAct, const float armure, const float resistance,
const int level, const std::string name, const int val_gold, const int val_exp, const float dmg, Perso *cible):Interface() , _santeMax(santeMax),
_santeAct(santeAct), _armure(armure), _resistance(resistance), _level(level), _name(name),
_val_gold(val_gold), _val_exp(val_exp), _cible(cible), _dmg(dmg)
{}

//Affichage
void Mob::afficher() const
{
    cout << "~~ " << _name;
    afficherSante();
    cout << " ~~" << endl;
    
    return;
}

void Mob::afficher_details() const
{
    cout << "~~ " << _name;
    afficherSante();
    cout << " ~~" << endl;
    cout << "Lvl: " << get_level() << endl;
    return;
}


void Mob::afficher_name(void) const
{
    cout <<_name << "(LVL " << _level << ")";
    afficherSante();
}

void Mob::afficherSante(void) const
{
    int percent = int(( _santeAct/_santeMax)*10);

    if(percent == 0 && _santeAct != 0) {
        percent = 1;
    }

    cout << "[" ;
    for(int i=0; i<percent; i++) {
        cout << "#";
    }
    for(int i=percent; i<10; i++) {
        cout << " ";
    }
    cout << "]";

    return;
}

// Setteurs
void Mob::set_santeMax(const float santeMax)
{
    _santeMax = santeMax;
}

void Mob::set_santeAct(const float santeAct)
{
    _santeAct = santeAct;
}

void Mob::set_armure(const float armure)
{
    _armure = armure;
}

void Mob::set_resistance(const float res)
{
    _resistance = res;
}

void Mob::set_level(const int level)
{
    _level = level;
}

void Mob::set_name(const std::string name)
{
    _name = name;
}

void Mob::set_val_gold(const int val_gold)
{
    _val_gold = val_gold;
}

void Mob::set_val_exp(const int val_exp)
{
    _val_exp = val_exp;
}

void Mob::set_cible(Perso * cible)
{
    _cible = cible;
}

void Mob::set_dmg(const float dmg)
{
    _dmg = dmg;
}

// Getteurs
float Mob::get_santeMax(void) const
{
    return _santeMax;
}

float Mob::get_santeAct(void) const
{
    return _santeAct;
}

float Mob::get_armure(void) const
{
    return _armure;
}

float Mob::get_resistance(void) const
{
    return _resistance;
}

int Mob::get_level(void) const
{
    return _level;
}

string Mob::get_name(void) const
{
    return _name;
}

int Mob::get_val_gold(void) const
{
    return _val_gold;
}

int Mob::get_val_exp(void) const
{
    return _val_exp;
}

Perso* Mob::get_cible(void) const
{
    return _cible;
}

float Mob::get_dmg(void) const
{
    return _dmg;
}

//Comportement Mob
void Mob::attaquer_cible(void) const
{
    _cible->recevoir_dmg(this->get_dmg());
    cout << get_name() << " inflige " << get_dmg() << " à " << _cible->get_name() << endl; 
}

void Mob::recevoir_dmg(const float dmg_recu, Perso * p)
{
    set_cible(p);
    set_santeAct(get_santeAct() - dmg_recu);
    est_mort();
}

bool Mob::est_mort(void) const
{
    return (get_santeAct() <= 0);
}

// Destructeur
Mob::~Mob()
{
    cout << "   Il est mort sur le coup !" << endl;
}