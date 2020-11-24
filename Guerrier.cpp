#include <iostream>
#include "Guerrier.hpp"
#include "Arme.hpp"

using namespace std;

Guerrier::Guerrier(const float santeMax, const float santeAct, const float res,
const int exp, const int lvl, const string name, const int rage): 
Perso(santeMax,santeAct, res, exp, lvl,name), _rage(rage)
{
    set_type("Guerrier");
}

Guerrier::Guerrier(const float santeMax, const float santeAct, const float res,
const int exp, const int lvl, const string name, Arme &a,const int rage): 
Perso(santeMax,santeAct, res, exp, lvl,name, a), _rage(rage)
{
    set_type("Guerrier");
}


Guerrier::Guerrier(const Guerrier &g): Perso(g), _rage(g._rage)
{
    set_type("_Guerrier");
}

int Guerrier::get_rage(void) const
{
    return _rage;
}

void Guerrier::set_rage (const int rage)
{
    _rage = rage;
}

void Guerrier::afficher(void) const
{
    Perso::afficher();
}

void Guerrier::afficher_details(void) const
{
    Perso::afficher_details();
    cout << "Classe: "<< Perso::get_classe() << endl << endl;
}

void Guerrier::afficher_name(void) const
{
    Perso::afficher_name();
}

Guerrier::~Guerrier()
{}
