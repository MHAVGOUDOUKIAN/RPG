#ifndef INTERFACE_HPP_INCLUDED
#define INTERFACE_HPP_INCLUDED
#include "Objet.hpp"

class Mob;
class Perso;
class Arme;

class Interface : public Objet
{
    public:
        Interface(): Objet() {}
        virtual void afficher_name(void) const {return;}
        virtual int get_level(void) const {return 0;}
        virtual void afficher_details(void) const {return;}
        virtual ListeAdapt* get_inventaire(void) const {return NULL;}
        virtual bool est_arme(void) const {return false;}
        virtual void change_weapon(Arme *) {return;}
        virtual void enlever_inventaire(const int emplacement) {return;}
        virtual void vendre_item(const int) {return;}
        virtual float get_valeur_gold(void) const {return 0;}
        virtual int get_gold(void) const {return 0;}
        virtual void acheter_item(Objet *) {return;}
        virtual void attaquer(Mob *) {return;}
        virtual void attaquer_cible(void) const {return;}
        virtual void set_cible(Perso * cible) {return;}
        virtual bool est_vivant(void) {return true;}
        virtual bool est_mort(void) const {return true;}
        virtual void revive(void) {return;}
        virtual void gagner_exp(const int) {return;}
        virtual void gagner_gold(const int) {return;}
        virtual int get_val_gold(void) const {return 0;}
        virtual int get_val_exp(void) const {return 0;}
        virtual Perso* get_cible(void) const {return NULL;}
        virtual ~Interface(){}
};

#endif // INTERFACE_HPP_INCLUDED