#ifndef OBJET_HPP_INCLUDED
#define OBJET_HPP_INCLUDED

class Mob;
class Perso;
class Arme;
class ListeAdapt;

class Objet
{
    public:
        Objet();
        int get_IDObjet(void) const;
        int get_nb_objets(void) const;
        virtual void afficher_name(void) const =0;
        virtual int get_level(void) const =0;
        virtual void afficher_details(void) const =0;
        virtual ListeAdapt* get_inventaire(void) const =0;
        virtual bool est_arme(void) const =0;
        virtual void change_weapon(Arme *) =0;
        virtual void enlever_inventaire(const int emplacement) =0 ;
        virtual void vendre_item(const int) =0;
        virtual float get_valeur_gold(void) const =0;
        virtual int get_gold(void) const =0;
        virtual void acheter_item(Objet *) =0;
        virtual void attaquer(Mob *) =0 ;
        virtual void attaquer_cible(void) const =0;
        virtual void set_cible(Perso * cible) =0;
        virtual bool est_vivant(void) =0;
        virtual bool est_mort(void) const =0;
        virtual void revive(void) =0;
        virtual void gagner_exp(const int) =0;
        virtual void gagner_gold(const int) =0;
        virtual int get_val_gold(void) const =0;
        virtual int get_val_exp(void) const =0;
        virtual Perso* get_cible(void) const =0;
        virtual ~Objet();

    private:
        static int _nb_objets_crees;
        static int _nb_objet;
        int _IDObjet;
};

#endif //OBJET_HPP_INCLUDED