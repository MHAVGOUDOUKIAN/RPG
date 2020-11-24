#include <iostream>
#include "Objet.hpp"

using namespace std;

int Objet::_nb_objet = 0;
int Objet::_nb_objets_crees = 0;

Objet::Objet()
{
    _nb_objet++;
    _nb_objets_crees++;
    _IDObjet = _nb_objets_crees;
}

int  Objet::get_nb_objets(void) const
{
    return _nb_objet;
}

int Objet::get_IDObjet(void) const
{
    return _IDObjet;
}

Objet::~Objet()
{
    _nb_objet--;
}