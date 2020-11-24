#ifndef PERSO_HPP_INCLUDED
#define PERSO_HPP_INCLUDED
#include "Interface.hpp"
#include "Arme.hpp"
#include "ListeAdapt.hpp"
#include "Objet.hpp"

class Perso: public Interface
{
    public:
        // Constructeur
        Perso(const float, const float, const float ,const int ,const int,const std::string);
        Perso(const float, const float, const float ,const int ,const int,const std::string, Arme &);
        Perso(const Perso &);
        
        //Affichage
        void afficher(void) const;
        void afficher_details(void) const;
        virtual void afficher_name(void) const;
        void afficherSante(void) const;
        void afficherExp(void) const;

        //Que peut faire le personnage ?
        void attaquer(Perso &);
        void attaquer(Mob *);

        void ajouter_inventaire(Objet*);
        void ajouter_inventaire(Objet*, const int nb_elmt);
        void afficher_inventaire(void) const; 
        void enlever_inventaire(const int emplacement);
        bool est_vivant(void);
        void recevoir_dmg(const float dmg_recu);
        void update_lvl(void);
        void gagner_exp(const int);
        void gagner_gold(const int);
        void vendre_item(const int emplacement_item);
        void acheter_item(Objet *);
        void revive(void);
        void set_santeAct(const float); // Equivaut à recevoir dmg
        
        //Setteurs
        void set_name(const std::string);
        void set_santeMax(const float);
        void set_resistance(const float);
        void change_weapon(Arme *);
        void set_exp(const int);
        void set_level(const int);
        void mettre_santeAct(const int);
        void set_gold(const int);
        void set_type(const std::string);    
        void set_expMax(const int exp);

        //Getteurs
        int get_gold(void) const;
        float get_santeMax(void) const;
        float get_santeAct(void) const;
        float get_resistance(void) const;
        int get_exp(void) const;
        virtual int get_level(void) const;
        int get_expMax(void) const;
        std::string get_name(void) const;
        std::string get_classe(void) const;
        Arme* get_arme(void) const;
        virtual ListeAdapt* get_inventaire(void) const;

        //Destructeur
        virtual ~Perso();

    private:
        int _level;
        float _santeMax;
        float _santeAct;
        float _resistance;
        int _exp;
        
        int _expMax;
        std::string _name;
        Arme* _arme;
        ListeAdapt* _inventaire;
        std::string _classe;
        int _gold;
};

#endif // PERSO_HPP_INCLUDED