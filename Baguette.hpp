#ifndef BAGUETTE_HPP_INCLUDED
#define BAGUETTE_HPP_INCLUDED
#include "Arme.hpp"

class Baguette : public Arme
{
    public:
        //Constructeur
        Baguette(const float dmg, const float puiss, const float val_gold,const std::string name, const float dmg_ele);
        Baguette(const Baguette &);
        
        //Getteurs
        //std::string get_name(void) const;
        float get_dmg_elementaire(void) const;

        //Setteurs
        void set_dmg_elementaire(const float);

        //Affichage
        void afficher(void) const;
        virtual void afficher_name(void) const;
        
        //Destructeur
        virtual ~Baguette();

    private:
        float _dmg_elementaire;
};

#endif // BAGUETTE_HPP_INCLUDED