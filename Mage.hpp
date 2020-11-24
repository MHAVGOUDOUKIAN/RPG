#ifndef MAGE_HPP_INCLUDED
#define MAGE_HPP_INCLUDED
#include "Perso.hpp"

class Mage : public Perso
{
    public:
        Mage(const float santeMax, const float santeAct, const float res, const int exp, const int lvl, const std::string name, const int mana);
        Mage(const Mage &);

        int get_mana(void) const;

        void set_mana (const int mana);

        void afficher(void) const;
        void afficher_details(void) const;
        virtual void afficher_name(void) const;
        
        virtual ~Mage();

    private:
        int _mana;
};

#endif // MAGE_HPP_INCLUDED
