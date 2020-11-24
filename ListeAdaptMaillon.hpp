#ifndef LISTEADAPTMAILLON_HPP_INCLUDED
#define LISTEADAPTMAILLON_HPP_INCLUDED
#include "Objet.hpp"
// Cette classe correspond au maillon que l'on place dans la liste chaînée
class ListeAdaptMaillon
{
    public:
    //  Constructeurs
        ListeAdaptMaillon(Objet *, const int nb_element, const int ID_maillon);
        ListeAdaptMaillon(ListeAdaptMaillon &);
    
    //  Setters et Getters
        ListeAdaptMaillon *get_suiv(void) const;
        virtual Objet* get_elmt(void) const;
        int get_nbObjetDansMaillon(void) const;
        int get_IDMaillon(void) const;
        void set_suiv( ListeAdaptMaillon*);
        void set_elmt(Objet *);
        void set_nbObjetDansMaillon(const int);
        void set_IDMaillon(const int);

    //  Destructeur
        virtual ~ListeAdaptMaillon();

    private:
        ListeAdaptMaillon* _suiv;
        Objet *_elmt;
        int _nbObjetDansMaillon;
        int _IDMaillon;
};

#endif //LISTEADAPTMAILLON_HPP_INCLUDED