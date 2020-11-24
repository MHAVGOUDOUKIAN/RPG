#include <iostream>
#include "ListeAdapt.hpp"
#include "ListeAdaptMaillon.hpp"
#include "Objet.hpp"

using namespace std;

ListeAdapt::ListeAdapt(const bool allowing_destruction, const bool afficher_nb_elmt, const bool afficher_ID_elmt) : _first(NULL), 
_nb_maillon(0), _destruction_elemt(allowing_destruction), _afficher_nb_elmt(afficher_nb_elmt), _afficher_ID_elmt(afficher_ID_elmt),
_taille(-1), _name_liste("")
{}

ListeAdapt::ListeAdapt(const bool allowing_destruction, const bool afficher_nb_elmt, const bool afficher_ID_elmt, const std::string name) : _first(NULL),
 _nb_maillon(0), _destruction_elemt(allowing_destruction), _afficher_nb_elmt(afficher_nb_elmt), _afficher_ID_elmt(afficher_ID_elmt),
_taille(-1), _name_liste(name)
{}

ListeAdapt::ListeAdapt(const bool allowing_destruction, const bool afficher_nb_elmt, const bool afficher_ID_elmt, const std::string name, const int taille) : _first(NULL),
 _nb_maillon(0), _destruction_elemt(allowing_destruction), _afficher_nb_elmt(afficher_nb_elmt), _afficher_ID_elmt(afficher_ID_elmt),
 _taille(taille), _name_liste(name)
{}

void ListeAdapt::empiler(Objet * val, const int nb_element)
{
    if(_taille <= -1 || _nb_maillon < _taille) {
        _nb_maillon ++;
        ListeAdaptMaillon *newMaillon = new ListeAdaptMaillon(val, nb_element,_nb_maillon);
        ListeAdaptMaillon *tempMaillon = NULL;
        tempMaillon = _first;

    
        if (_first == NULL) {
            set_first(newMaillon);
        }
        else {
            while (tempMaillon->get_suiv() != NULL) {
                tempMaillon = tempMaillon->get_suiv();
            }
            tempMaillon->set_suiv(newMaillon);
        }
        
    }
    else {
        cout << "Taille maximale atteinte"<< endl;
    }
    
    return;
}

void ListeAdapt::empiler(Objet * val)
{
    if(_taille <= -1 || _nb_maillon < _taille) {
        _nb_maillon ++;
        ListeAdaptMaillon *newMaillon = new ListeAdaptMaillon(val, 1, _nb_maillon);
        ListeAdaptMaillon *tempMaillon = NULL;
        tempMaillon = _first;

    
        if (_first == NULL) {
            set_first(newMaillon);
        }
        else {
            while (tempMaillon->get_suiv() != NULL) {
                tempMaillon = tempMaillon->get_suiv();
            }
            tempMaillon->set_suiv(newMaillon);
        }

    }
    else {
        cout << "Taille maximale atteinte"<< endl;
    }
    
    return;
}

void ListeAdapt::ajouter(const int indice, Objet* val, const int nb_element)
{
    if(_taille <= -1 || _nb_maillon < _taille) {
        _nb_maillon ++;
        ListeAdaptMaillon *newMaillon = new ListeAdaptMaillon(val, nb_element, _nb_maillon);
        ListeAdaptMaillon *tempMaillon = NULL;
        tempMaillon = _first;
        int indicetemp = 1;
    
        if (_first == NULL) {
            set_first(newMaillon);
        }
        else {
            if(indice <= 1) {
                tempMaillon = _first;
                _first = newMaillon;
                newMaillon->set_suiv(tempMaillon);
            }
            else {
                while (tempMaillon->get_suiv() != NULL && indicetemp != indice-1) {
                    tempMaillon = tempMaillon->get_suiv();
                    indicetemp++;
                }
                newMaillon->set_suiv(tempMaillon->get_suiv());
                tempMaillon->set_suiv(newMaillon);
            }
        }
        
    }
    else {
        cout << "Taille maximale atteinte"<< endl;
    }

    return;
}

void ListeAdapt::depiler(void)
{
    ListeAdaptMaillon *tempMaillon = NULL;
    tempMaillon = _first;

    if (_first != NULL) {
        if (_first->get_suiv() == NULL) {
            if(_destruction_elemt == true)
            {
                delete _first->get_elmt();
            }
            delete _first;
            _first = NULL;
        }
        else {
            while (tempMaillon->get_suiv()->get_suiv() != NULL) {
                tempMaillon = tempMaillon->get_suiv();
            }
            if(_destruction_elemt == true)
            {
                delete tempMaillon->get_suiv()->get_elmt();
            }
            delete tempMaillon->get_suiv();
            tempMaillon->set_suiv(NULL);
        }
        _nb_maillon --;
    }
    else {
        cout << "Liste vide" << endl;
    }

    return;
}

void ListeAdapt::supprimer(const int indice)
{
    ListeAdaptMaillon *tempMaillon1 = NULL;
    ListeAdaptMaillon *tempMaillon2 = NULL;
    tempMaillon1 = _first;
    int indicetemp = 1;

    if (_first != NULL) {
        if(indice <= get_nb_maillon() && indice > 0) {
            if(_first->get_suiv() == NULL) {
                if(_destruction_elemt == true)
                {
                    delete _first->get_elmt();
                }
                delete _first;
                _first = NULL;
            }
            else if(indice == 1) {
                tempMaillon2 = _first->get_suiv();
                if(_destruction_elemt == true)
                {
                    delete _first->get_elmt();
                }
                delete _first;
                _first = tempMaillon2;
                tempMaillon1 = _first;
                while(tempMaillon1 != NULL)
                {
                    tempMaillon1->set_IDMaillon(tempMaillon1->get_IDMaillon() - 1);
                    tempMaillon1 = tempMaillon1->get_suiv();
                }
            }
            else {
                while (tempMaillon1->get_suiv()->get_suiv() != NULL && indicetemp != indice-1) {
                    tempMaillon1 = tempMaillon1->get_suiv();
                    indicetemp++;
                }
                
                if(_destruction_elemt == true)
                {
                    delete tempMaillon1->get_suiv()->get_elmt();
                }
                tempMaillon2 = tempMaillon1->get_suiv()->get_suiv();
                delete tempMaillon1->get_suiv();
                tempMaillon1->set_suiv(tempMaillon2);

                tempMaillon1 = tempMaillon1->get_suiv();
                while(tempMaillon1 != NULL)
                {
                    tempMaillon1->set_IDMaillon(tempMaillon1->get_IDMaillon() - 1);
                    tempMaillon1 = tempMaillon1->get_suiv();
                }
            }
            _nb_maillon --;
        }
    }
    else {
        cout << "Liste vide" << endl;
    }

    return;
}

void ListeAdapt::afficher(void) const
{
    ListeAdaptMaillon *affMaillon = NULL;
    affMaillon = _first;

    cout << "> " <<_name_liste <<" < " << endl << "-------------------" << endl;
    while (affMaillon != NULL) {
        
        if(_afficher_ID_elmt == true){
            cout << affMaillon->get_IDMaillon() << " - ";
        }
        (affMaillon->get_elmt())->afficher_name();
        if(_afficher_nb_elmt == true && affMaillon->get_nbObjetDansMaillon() != 1){
            cout << "(" << affMaillon->get_nbObjetDansMaillon() << ")";
        }
        affMaillon = affMaillon->get_suiv();
        cout << endl;
    }
    if(affMaillon == _first)
    {
        cout <<"     VIDE" << endl;
    }
    cout << "-------------------" << endl;
    //=> Nombre de maillon: " << get_nb_maillon() << endl ;

    return;
}

void ListeAdapt::set_first(ListeAdaptMaillon *ptr)
{
    _first = ptr;
}

void ListeAdapt::set_destruction_elemt(const bool allowing_destruction)
{
    _destruction_elemt = allowing_destruction;
}

void ListeAdapt::set_nb_maillon(const int nb_maillon)
{
    _nb_maillon = nb_maillon;
}

int ListeAdapt::get_nb_maillon(void) const
{
    return _nb_maillon;
}

ListeAdaptMaillon* ListeAdapt::get_first(void) const
{
    return _first;
}

bool ListeAdapt::est_vide(void) const
{
    bool vide = false;

    if(get_first() == NULL) {
        vide = true;
    }

    return vide;
}

ListeAdaptMaillon* ListeAdapt::get_itemAt(const int emplacement)
{
    ListeAdaptMaillon *tempMaillon = NULL;
    tempMaillon = _first;
    
    if(emplacement > get_nb_maillon()) {
        tempMaillon = NULL;
    }
    else {
        while (tempMaillon->get_suiv() != NULL && tempMaillon->get_IDMaillon() != emplacement) {
            tempMaillon = tempMaillon->get_suiv();
        }
    }
    
    return tempMaillon;
}

void ListeAdapt::clear_all(void)
{
    ListeAdaptMaillon *tmp = NULL;
    ListeAdaptMaillon *toDelete = NULL;

    if (_first != NULL) {
        tmp = _first->get_suiv();
        while (tmp != NULL) {
            toDelete = tmp->get_suiv();
            if(_destruction_elemt == true)
            {
                delete tmp->get_elmt();
            }
            delete tmp;
            tmp = toDelete;
            _nb_maillon --;
        }
        if(_destruction_elemt == true)
        {
            delete _first->get_elmt();
        }
        delete _first;
        _first = NULL;
        _nb_maillon --;
    }
}

ListeAdapt::~ListeAdapt()
{ 
    clear_all();
}