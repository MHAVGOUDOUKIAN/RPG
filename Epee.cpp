#include <iostream>
#include "Epee.hpp"

using namespace std;

Epee::Epee(const float dmg, const float puiss, const float val_gold ,
const std::string name, const float dmgt): Arme(dmg, puiss, val_gold ,name), _dmg_tranchant(dmgt)
{
    set_typeArme("Epee");
}

Epee::Epee(const Epee &e): Arme(e), _dmg_tranchant(e._dmg_tranchant)
{
    set_typeArme("Epee");
}

float Epee::get_dmg_tranchant(void) const
{
    return _dmg_tranchant;
}

void Epee::set_dmg_tranchant(const float dmgT)
{
    _dmg_tranchant = dmgT;
}

std::string Epee::get_name(void) const
{
    return Arme::get_name();
}

void Epee::afficher(void) const
{
    Arme::afficher();
    cout << "BONUS - Degats tranchant: "<< _dmg_tranchant << endl << endl; 
    return;
}

void Epee::afficher_name(void) const
{
    Arme::afficher_name();
}

Epee::~Epee()
{}