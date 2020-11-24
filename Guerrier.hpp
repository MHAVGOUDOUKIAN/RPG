#ifndef GUERRIER_HPP_INCLUDED
#define GUERRIER_HPP_INCLUDED
#include "Perso.hpp"

class Guerrier: public Perso
{
    public:
        Guerrier(const float santeMax, const float santeAct, const float res, const int exp, const int lvl, const std::string name, const int rage);
        Guerrier(const float santeMax, const float santeAct, const float res,const int exp, const int lvl, const std::string name, Arme &a,const int rage);
        Guerrier(const Guerrier &);
        
        int get_rage(void) const;

        void set_rage (const int);

        void afficher(void) const;
        void afficher_details(void) const;
        virtual void afficher_name(void) const;
        
        virtual ~Guerrier();

    private:
        int _rage;
};

#endif // GUERRIER_HPP_INCLUDED
