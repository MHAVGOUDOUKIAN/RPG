#include <iostream>
#include "Mage.hpp"
#include "Arme.hpp"

using namespace std;

Mage::Mage(const float santeMax, const float santeAct, const float res, const int exp, const int lvl,
const string name, const int mana) : Perso(santeMax, santeAct, res, exp,  lvl, name), _mana(mana)
{
        set_type("Mage");
}

Mage::Mage(const Mage &m): Perso(m), _mana(m._mana)
{
        set_type("Mage");
}

int Mage::get_mana(void) const
{
    return _mana;
}

void Mage::set_mana (const int mana)
{
    _mana = mana;
}

void Mage::afficher(void) const
{
    Perso::afficher();
}

void Mage::afficher_details(void) const
{
    Perso::afficher_details();
    cout << "Classe: "<< Perso::get_classe() << endl << endl;
}

void Mage::afficher_name(void) const
{
    Perso::afficher_name();
}

Mage::~Mage()
{}
