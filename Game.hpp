#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED
#include "Objet.hpp"
#include "ListeAdapt.hpp"

class Game
{
    public:
        Game();
        
        // Lancer le jeu
        void run(void);

        //Deroulement du jeu
        
        /** 
         * \relates Game
         * \brief Initialise la liste contenants toutes les armes du jeu
         * \param void
         * \return Création de la liste
         */
        void init_liste_Arme(void);

        void menu_chg_perso(void);
        void play(void);
        bool combat(const int id_monde);
        void boutique(void);

        // Création d 'objet
        void generer_mob(void);
        void add_perso(void);
        void delete_perso(void);

        //Action du perso dans le jeu
        void changer_arme(const int emplacement);
        void add_objet(Objet *);
        void add_objet(Objet *objet, const int nb_elmt);
        void supp_objet(const int emplacement);
        void acheter(const int emplacement);
        void vendre(const int emplacement);

        //Affichage des menus
        void display_story(void);
        void display_boutique(void);
        void display_end(void);
        void afficher_perso_details(void);
        void display_banner();
        void clear();

        //Getteurs
        ListeAdapt * get_liste_Perso(void) const;
        ListeAdapt * get_liste_Arme(void) const;
        ListeAdapt * get_liste_Mob(void) const;
        int get_id_monde(void) const;
        
        //Setteurs
        void set_id_monde(const int);

        //Destructeur
        ~Game();

    private:
        ListeAdapt *_liste_Perso;
        ListeAdapt *_liste_Arme;
        ListeAdapt *_liste_Mob;
        bool _exit_game;
        int _id_monde;
};

#endif // GAME_HPP_INCLUDED