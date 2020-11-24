#include <iostream>
#include "Baguette.hpp"

using namespace std;

//Constructeur
Baguette::Baguette(const float dmg, const float puiss, const float val_gold,
const std::string name, const float dmg_ele): Arme(dmg, puiss, val_gold ,name), _dmg_elementaire(dmg_ele)
{
    set_typeArme("Baguette");
}

Baguette::Baguette(const Baguette &b): Arme(b), _dmg_elementaire(b._dmg_elementaire)
{
    set_typeArme("Baguette");
}

//Getteurs
/*std::string Baguette::get_name(void) const
{
    return Arme::get_name();
}*/

float Baguette::get_dmg_elementaire(void) const
{
    return _dmg_elementaire;
}

//Setteurs
void Baguette::set_dmg_elementaire(const float dmgE)
{
    _dmg_elementaire = dmgE;
}

//Affichage
void Baguette::afficher(void) const
{
    Arme::afficher();
    cout << "BONUS - Degats elementaire: "<< _dmg_elementaire << endl << endl; 
    return;
}

void Baguette::afficher_name(void) const
{
    Arme::afficher_name();
}

//Destructeur
Baguette::~Baguette()
{}