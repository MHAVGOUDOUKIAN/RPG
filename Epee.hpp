#ifndef EPEE_HPP_INCLUDED
#define EPEE_HPP_INCLUDED
#include "Arme.hpp"

class Epee : public Arme
{
    public:
        Epee(const float dmg, const float puiss, const float val_gold ,const std::string name, const float dmgt);
        Epee(const Epee &);

        std::string get_name(void) const;
        float get_dmg_tranchant(void) const;
        void set_dmg_tranchant(const float);


        void afficher(void) const;
        virtual void afficher_name(void) const;
        
        virtual ~Epee();

    private:
        float _dmg_tranchant;
};

#endif // EPEE_HPP_INCLUDED