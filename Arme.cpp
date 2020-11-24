#include <iostream>
#include "Arme.hpp"
#include "Objet.hpp"

using namespace std;

// Constructeurs
Arme::Arme(const float dmg, const float puiss, const float val_gold, const std::string name): Interface(), _dmg(dmg),
_puissance(puiss), _valeur_gold(val_gold) ,_name(name), _type("")
{
}

Arme::Arme(Arme *a): Interface(), _dmg(a->_dmg), _puissance(a->_puissance), _name(a->_name), _type("")
{
}

//Setteurs
float Arme::get_dmg(void) const
{
    return _dmg;
}

float Arme::get_puissance(void) const
{
    return _puissance;
}

float Arme::get_valeur_gold(void) const
{
    return _valeur_gold;
}

string Arme::get_name(void) const
{
    return _name;
}

string Arme::get_typeArme(void) const
{
    return _type;
}

//Setteurs
void Arme::set_dmg(const float dmg)
{
    _dmg = dmg;
}

void Arme::set_puissance(const float puiss)
{
    _puissance = puiss;
}

void Arme::set_name(const std::string name)
{
    _name = name;
}

void Arme::set_typeArme(const std::string typedeArme)
{
    _type = typedeArme;
}

void Arme::set_valeur_gold(const float valeur_gold)
{
    _valeur_gold = valeur_gold;
}

// Affichage
void Arme::afficher(void) const
{
    cout << _name << "(Degats " << _dmg << " )" << "/ Puissance requise: " << _puissance << endl; 
    return;
}

void Arme::afficher_details(void) const
{
    cout << get_typeArme() << ": ";
    afficher();
}

void Arme::afficher_name(void) const
{
    cout << _name << "(Degats: " << _dmg << "/Valeur: " << _valeur_gold << " Gold)";
}

Arme::~Arme()
{}