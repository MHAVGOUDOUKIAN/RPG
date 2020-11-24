#ifndef ARME_HPP_INCLUDED
#define ARME_HPP_INCLUDED
#include "Interface.hpp"

class Arme : public Interface
{
    public:
        // Constructeurs
        Arme(const float dmg, const float puiss, const float val_gold, const std::string name);
        Arme(Arme *a);
        
        bool est_arme(void) const {return true;}

        //Setteurs
        float get_dmg(void) const;
        float get_puissance(void) const;
        float get_valeur_gold(void) const;
        std::string get_name(void) const;
        std::string get_typeArme(void) const;

        // Getteurs
        void set_dmg(const float);
        void set_puissance(const float);
        void set_name(const std::string);
        void set_typeArme(const std::string);
        void set_valeur_gold(const float valeur_gold);

        // Affichage
        void afficher(void) const;
        virtual void afficher_name(void) const;
        void afficher_details(void) const;

        //Destructeur
        virtual ~Arme();

    private:
        float _dmg;
        float _puissance;
        float _valeur_gold;
        std::string _name;
        std::string _type;
};

#endif // ARME_HPP_INCLUDED