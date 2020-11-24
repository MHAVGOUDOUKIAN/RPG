#include <iostream>
#include "ListeAdapt.hpp"
#include "Objet.hpp"

using namespace std;

ListeAdaptMaillon::ListeAdaptMaillon(Objet *val, const int nb_element, const int ID_maillon): _suiv(NULL),
_elmt(val), _nbObjetDansMaillon(nb_element), _IDMaillon(ID_maillon)
{
}

// Constructeur de copie
ListeAdaptMaillon::ListeAdaptMaillon(ListeAdaptMaillon &lam)

{
    _suiv = NULL;
    _elmt = lam._elmt;
    _nbObjetDansMaillon = lam._nbObjetDansMaillon;
}

// Accesseurs
ListeAdaptMaillon* ListeAdaptMaillon::get_suiv(void) const
{
    return _suiv;
}

Objet* ListeAdaptMaillon::get_elmt(void) const
{
    return _elmt;
}

int ListeAdaptMaillon::get_nbObjetDansMaillon(void) const
{
    return _nbObjetDansMaillon;
}

int ListeAdaptMaillon::get_IDMaillon(void) const
{
    return _IDMaillon;
}

// Mutateurs
void ListeAdaptMaillon::set_suiv(ListeAdaptMaillon* suiv)
{
    _suiv = suiv;
}

void ListeAdaptMaillon::set_elmt(Objet *elmt)
{
    _elmt = elmt;
}

void ListeAdaptMaillon::set_nbObjetDansMaillon(const int nb_objet)
{
    _nbObjetDansMaillon = nb_objet;
}

void ListeAdaptMaillon::set_IDMaillon(const int ID_maillon)
{
    _IDMaillon = ID_maillon;
}

ListeAdaptMaillon::~ListeAdaptMaillon()
{}