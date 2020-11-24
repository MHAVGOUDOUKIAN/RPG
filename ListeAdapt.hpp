#ifndef LISTEADAPT_HPP_INCLUDED
#define LISTEADAPT_HPP_INCLUDED
#include "ListeAdaptMaillon.hpp"

// Cette classe correspond à la liste chaînée qui contient le premier maillon _first
// qui lui permet d'accèder aux suivants
class ListeAdapt
{
    public:
    //  Constructeur
        ListeAdapt(const bool allowing_destruction, const bool afficher_nb_elmt, const bool afficher_ID_elmt);
        ListeAdapt(const bool allowing_destruction, const bool afficher_nb_elmt, const bool afficher_ID_elmt, const std::string name);
        ListeAdapt(const bool allowing_destruction, const bool afficher_nb_elmt, const bool afficher_ID_elmt, const std::string name, const int taille);
   
        void empiler(Objet *, const int nb_element); // Ajoute "nb_element" dans un nouveau maillon de type Objet à la fin de la liste
        void empiler(Objet *); //Ajoute 1 element de type Objet à la fin de la liste
        void ajouter(const int indice, Objet*, const int nb_element);
        void depiler(void); //retire le dernier élément de la liste
        void supprimer(const int indice); // supprime l'élement à l'indice i de la liste
        void afficher(void) const; // afficher tous les eléments de la liste
        void clear_all(void); // Retire tous les elements de la liste
        

    //  Setters
        void set_first(ListeAdaptMaillon*);
        void set_destruction_elemt(const bool);
        void set_nb_maillon(const int);

    //Getters
        int get_nb_maillon(void) const;
        ListeAdaptMaillon* get_first(void) const;
        bool est_vide(void) const;
        ListeAdaptMaillon* get_itemAt(const int emplacement);

    //  Destructeur
        ~ListeAdapt();

    private:
        ListeAdaptMaillon *_first;
        int _nb_maillon;
        bool _destruction_elemt;
        bool _afficher_nb_elmt;
        bool _afficher_ID_elmt;
        int _taille; // _taille > -1 => taille max = _taille // _taille <= -1 => taille max = pas de limite
        std::string _name_liste;
};

#endif //LISTEADAPT_HPP_INCLUDED