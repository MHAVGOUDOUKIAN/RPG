#ifndef MOB_HPP_INCLUDED
#define MOB_HPP_INCLUDED
#include "Perso.hpp"

class Interface;

class Mob : public Interface
{
    public:
        // Constructeurs
        Mob(const float santeMax, const float santeAct, const float armure, const float resistance, const int level, const std::string name, const int val_gold, const int val_exp, const float _dmg);
        Mob(const float santeMax, const float santeAct, const float armure, const float resistance, const int level, const std::string name, const int val_gold, const int val_exp, const float _dmg, Perso*);

        //Affichage
        void afficher(void) const;
        void afficher_details(void) const;
        virtual void afficher_name(void) const;
        void afficherSante(void) const;

        // Setteurs
        void set_santeMax(const float);
        void set_santeAct(const float);
        void set_armure(const float);
        void set_resistance(const float);
        void set_level(const int);
        void set_name(const std::string);
        void set_val_gold(const int);
        void set_val_exp(const int);
        void set_cible(Perso * cible);
        void set_dmg(const float);

        // Getteurs
        float get_santeMax(void) const;
        float get_santeAct(void) const;
        float get_armure(void) const;
        float get_resistance(void) const;
        int get_level(void) const;
        std::string get_name(void) const;
        int get_val_gold(void) const;
        int get_val_exp(void) const;
        Perso* get_cible(void) const;
        float get_dmg(void) const;

        //Comportement Mob
        void attaquer_cible(void) const;
        void recevoir_dmg(const float, Perso *);
        bool est_mort(void) const;

        // Destructeur
        virtual ~Mob();

    private:
        float _santeMax;
        float _santeAct;
        float _armure;
        float _resistance;
        int _level;
        std::string _name;
        int _val_gold;
        int _val_exp;
        Perso* _cible;
        float _dmg;
        
};

#endif // MOB_HPP_INCLUDED