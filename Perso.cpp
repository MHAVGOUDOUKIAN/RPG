#include <iostream>
#include "inline.h"
#include "Perso.hpp"
#include "Mob.hpp"
#include "Arme.hpp"
#include "Objet.hpp"
#define MULT_LEVELING_PERSO_EXP 1.85
#define MULT_LEVELING_PERSO_SANTE 1.75

using namespace std;

//Constructeur
Perso::Perso(const float santeMax, const float santeAct, const float resist, const int exp, const int lvl,
const string name):Interface(), _level(lvl) ,_santeMax(100*pwd(MULT_LEVELING_PERSO_SANTE, _level-1)), _santeAct(100), _resistance(resist), _exp(exp),
_expMax(50*pwd(MULT_LEVELING_PERSO_EXP, _level-1)) ,_name(name),_arme(NULL), _classe(""), _gold(25)
{
    _inventaire = new ListeAdapt(false, true, true, "Inventaire");
}

Perso::Perso(const float santeMax, const float santeAct, const float resist, const int exp, const int lvl,
const string name, Arme &a):Interface(), _level(lvl) , _santeMax(100*pwd(MULT_LEVELING_PERSO_SANTE, _level-1)), _santeAct(100), _resistance(resist), _exp(exp)
,_expMax(50*pwd(MULT_LEVELING_PERSO_EXP, _level-1)) , _name(name), _arme(&a), _classe(""), _gold(25)
{
    _inventaire = new ListeAdapt(false, true, true, "Inventaire");
}

Perso::Perso(const Perso &p):Interface(), _level(p._level) , _santeMax(p._santeMax), _santeAct(p._santeAct),
_resistance(p._resistance), _exp(p._exp), _expMax(p._expMax) , _name(p._name),
_arme(p._arme), _classe("") , _gold(25)
{
    _inventaire = new ListeAdapt(false, true, true, "Inventaire");
}

//Affichage
void Perso::afficher(void) const
{
    cout << "~~ " << this->_name;
    afficherSante();
    cout << " ~~" << endl;
    
    return;
}

void Perso::afficher_details(void) const
{
    cout << "~~ " << this->_name << " ";
    afficherSante();
    cout << "(" << get_santeAct() << "/" << get_santeMax() << ")" <<" ~~" << endl;
    cout << "   Lvl " << this->_level << " ";
    afficherExp();
    cout << " (" << get_exp() << "/" << get_expMax() << ")" << endl;
    afficher_inventaire();
    cout << "Arme équipée: ";
    if(this->_arme == NULL) {
        cout << "Aucune arme équipée (Degats " << 10 << ")" << endl;
    }
    else {
        this->_arme->afficher();
    }
    cout << "Vous avez: " << get_gold() << " Or" << endl; 
    return;
}

void Perso::afficher_name(void) const
{
    cout << this->_name << " - " << this->_classe << "(LVL " << this->_level << ")";
}

void Perso::afficherSante(void) const
{
    int percent = int(( this->_santeAct/this->_santeMax)*10);

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

void Perso::afficherExp(void) const
{
    int percent = int(( float(get_exp())/float(get_expMax()))*10);

    if(percent == 0 && _exp != 0) {
        percent = 1;
    }

    cout << "[" ;
    for(int i=0; i<percent; i++) {
        cout << "o";
    }
    for(int i=percent; i<10; i++) {
        cout << " ";
    }
    cout << "]";

    return;
}

//Que peut faire le personnage ?
void Perso::attaquer(Perso &p)
{
    if(_arme != NULL) {
        p.set_santeAct(this->_arme->get_dmg());
        cout << this->_name << " inflige " << this->_arme->get_dmg();
    }
    else {
        p.set_santeAct(10);
        cout << this->_name << " inflige " << 10;
    }    
    cout << " dmg à " << p._name<< endl; 
    return;
}

void Perso::attaquer(Mob *mob)
{
    if(_arme != NULL) {
        mob->recevoir_dmg(this->_arme->get_dmg(),this);
        cout << this->_name << " inflige " << this->_arme->get_dmg();
    }
    else {
        mob->recevoir_dmg(10, this);
        cout << this->_name << " inflige " << 10;
    }    
    cout << " dmg à " << mob->get_name() << endl; 
    return;
}

void Perso::ajouter_inventaire(Objet *objet)
{
    this->_inventaire->empiler(objet);
}

void Perso::ajouter_inventaire(Objet *objet, const int nb_elmt)
{
    this->_inventaire->empiler(objet, nb_elmt);
}

void Perso::afficher_inventaire(void) const
{
    this->_inventaire->afficher();
}

void Perso::enlever_inventaire(const int emplacement)
{
    if(get_arme() != NULL)
    {
        if(get_arme()->get_IDObjet() == get_inventaire()->get_itemAt(emplacement)->get_elmt()->get_IDObjet())
        {
            change_weapon(NULL);
        }
    }
    
    get_inventaire()->supprimer(emplacement);
}

bool Perso::est_vivant(void)
{
    return get_santeAct() > 0;
}

void Perso::recevoir_dmg(const float dmg_recu)
{
    set_santeAct(dmg_recu);
}


void Perso::gagner_exp(const int exp_earn)
{
    set_exp(get_exp() + exp_earn);
    bool change_lvl = false;

    while(get_exp() >= get_expMax()) {
        change_lvl = true;
        set_exp(get_exp() - get_expMax());
        update_lvl();
    }

    if(change_lvl)
    {
        cout << "Nouveau niveau !" << endl;
    }

    return;
}

void Perso::gagner_gold(const int gold_earn)
{
    set_gold(get_gold() + gold_earn);
}

void Perso::update_lvl(void)
{
    set_level(get_level() + 1);
    set_expMax(int(get_expMax() * MULT_LEVELING_PERSO_EXP));
    set_santeMax(int(get_santeMax() * MULT_LEVELING_PERSO_SANTE));
    mettre_santeAct(get_santeMax());
}

void Perso::vendre_item(const int emplacement_item)
{
    gagner_gold(int(this->_inventaire->get_itemAt(emplacement_item)->get_elmt()->get_valeur_gold()));
    enlever_inventaire(emplacement_item);
}

void Perso::acheter_item(Objet * article)
{
    this->_inventaire->empiler(article);
    gagner_gold(int(article->get_valeur_gold()) *(-1));
}

void Perso::revive(void)
{
    mettre_santeAct(get_santeMax());
}

//Setteurs
void Perso::mettre_santeAct(const int santeAct)
{
    this->_santeAct = santeAct;
}

void Perso::set_name(const string new_name)
{
    this->_name = new_name;
}

void Perso::set_santeMax(const float santeMax)
{
    this->_santeMax = santeMax;
}

void Perso::set_resistance(const float res)
{
    this->_resistance = res;
}

void Perso::change_weapon(Arme *a)
{
    this->_arme = a;
}

void Perso::set_exp(const int exp)
{
    this->_exp = exp;
}

void Perso::set_level(const int lvl)
{
    this->_level = lvl;
}

void Perso::set_santeAct(const float dmg)
{
    this->_santeAct = this->_santeAct - dmg ;
    if(this->_santeAct < 0)
    {
        this->_santeAct=0;
    }
    return;
}

void Perso::set_gold(const int gold)
{
    this->_gold = gold;
}

void Perso::set_type(const string tc)
{
    this->_classe = tc;
}

void Perso::set_expMax(const int exp)
{
    this->_expMax = exp;
}

//Getteurs
int Perso::get_gold(void) const
{
    return this->_gold;
}

float Perso::get_santeMax(void) const
{
    return this->_santeMax;
}

float Perso::get_santeAct(void) const
{
    return this->_santeAct;
}

float Perso::get_resistance(void) const
{
    return this->_resistance;
}

int Perso::get_exp(void) const
{
    return this->_exp;
}

int Perso::get_level(void) const
{
    return this->_level;
}

int Perso::get_expMax(void) const
{
    return this->_expMax;
}

std::string Perso::get_name(void) const
{
    return this->_name;
}

string Perso::get_classe(void) const
{
    return this->_classe;
}

Arme* Perso::get_arme(void) const
{
    return this->_arme;
}

ListeAdapt* Perso::get_inventaire(void) const
{
    return this->_inventaire;
}

//Destructeur
Perso::~Perso()
{
    delete this->_inventaire;
}