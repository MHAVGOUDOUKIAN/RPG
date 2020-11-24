#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include "Game.hpp"
#include "Guerrier.hpp"
#include "Mage.hpp"
#include "Objet.hpp"
#include "Mob.hpp"
#include "Epee.hpp"
#include "inline.h"

using namespace std;

Game::Game(): _exit_game(false), _id_monde(0)
{
    _liste_Perso = new ListeAdapt(true, false, false,"Votre Personnage", 1);
    _liste_Arme = new ListeAdapt(false, false, true, "Inventaire de la Boutique");
    _liste_Mob = new ListeAdapt(true, false, true, "ENNEMIS", 3);
    srand(time(NULL));
}

void Game::run(void)
{
    int choix;
    init_liste_Arme();
    while(!_exit_game) {
        display_banner();
        cout << "1 - Lancer une partie" << endl;
        cout << "2 - Modifier joueur" << endl;
        cout << "3 - Quitter" << endl;
        cout << endl << "Votre Choix: ";
        cin >> choix;

        switch(choix) {
            case 1:
                if(_liste_Perso->est_vide() == true) {
                    add_perso();
                }
                if(_liste_Perso->est_vide() != true) {
                    play();
                }
                break;

            case 2:
                menu_chg_perso();
                break;

            case 3:
                _exit_game = true;
                clear();
                break;
        }
    }
}

//DEROULEMENT DU JEU
void Game::init_liste_Arme(void)
{
    ifstream fichier ("ressources/init_items.txt");
    fichier.seekg(0, ios::beg);
    string ligne="";
    int compteur;
    while(compteur != 14){
        //Enregistrement des données avant la création de l'arme
        std::string name_arme;
        float temp[4];

        fichier >> name_arme >> temp[0] >> temp[1] >> temp[2] >> temp[3];

        // Suppression des espaces dans le nom
        erase_space(name_arme);

        // Création de l'arme
        get_liste_Arme()->empiler(new Epee(temp[0], temp[1], temp[2], name_arme, temp[3]),1);
        compteur ++;
    }

    fichier.close();
}

void Game::menu_chg_perso(void)
{
    int choix;
    bool back=false;
    while(!back) {
        display_banner();
        _liste_Perso->afficher();
        if(_liste_Perso->est_vide()) {
            cout << "1 - Nouveau Personnage" << endl;
        }
        cout << "2 - Supprimer Personnage" << endl;
        cout << "3 - Retour" << endl;
        cout << endl << "Votre Choix: ";
        cin >> choix;

        switch(choix) {
            case 1:
                if(_liste_Perso->est_vide()) {
                    add_perso();
                }
                break;

            case 2:
                delete_perso();
                break;

            case 3:
                back = true;
                break;
        }
    }
}

void Game::play(void)
{
    bool back=false;
    int choix=0;

    while(!back && get_id_monde() <= 3) {
        clear();
        display_story();
        cout << endl << "Votre Choix: ";
        cin >> choix;
        switch(choix)
        {
            case 1:
                combat(0);
                break;

            case 2:
                if(combat(1))
                {
                    set_id_monde(get_id_monde() +1);
                }
                break;

            case 3:
                boutique();
                break;

            case 4:
                afficher_perso_details();
                break;

            case 5:
                back=true;
                break;
        }
    }

    if(!back)
    {
        set_id_monde(1);
        display_end();
        delete_perso();
    }
    return;
}

bool Game::combat(const int ID)
{
    int nb_mob = 0;
    if(ID == 0) {
        if(_liste_Perso->get_first()->get_elmt()->get_level() < 3)
        {
            nb_mob = randomInt(1, _liste_Perso->get_first()->get_elmt()->get_level());
        }
        else
        {
            nb_mob = randomInt(1,3);
        }

        for(int i=1; i <= nb_mob; i++)
        {
            generer_mob();
            get_liste_Mob()->get_itemAt(i)->get_elmt()->set_cible((Perso *) get_liste_Perso()->get_first()->get_elmt());
        }
    }
    else
    {
        if(_id_monde == 1)
        {
            get_liste_Mob()->empiler(new Mob(30,30,5,5,3,"JEUNE POUSSE", 10, 100, 35),1);
            get_liste_Mob()->get_itemAt(1)->get_elmt()->set_cible((Perso *) get_liste_Perso()->get_first()->get_elmt());
            get_liste_Mob()->empiler(new Mob(500,500,5,5,4,"PLANTE CARNIVORE GEANTE", 100, 150, 25),1);
            get_liste_Mob()->get_itemAt(2)->get_elmt()->set_cible((Perso *) get_liste_Perso()->get_first()->get_elmt());
            get_liste_Mob()->empiler(new Mob(30,30,5,5,3,"JEUNE POUSSE", 10, 100, 35),1);
            get_liste_Mob()->get_itemAt(3)->get_elmt()->set_cible((Perso *) get_liste_Perso()->get_first()->get_elmt());
        }
        else if(_id_monde == 2)
        {
            get_liste_Mob()->empiler(new Mob(205, 205,5,5,6,"BANDIT", 150, 210, 60),1);
            get_liste_Mob()->get_itemAt(1)->get_elmt()->set_cible((Perso *) get_liste_Perso()->get_first()->get_elmt());
            get_liste_Mob()->empiler(new Mob(1000,1000,5,5,8,"LE FLEAU", 350, 450, 90),1);
            get_liste_Mob()->get_itemAt(2)->get_elmt()->set_cible((Perso *) get_liste_Perso()->get_first()->get_elmt());
            get_liste_Mob()->empiler(new Mob(205, 205,5,5,6,"BANDIT", 150, 210, 60),1);
            get_liste_Mob()->get_itemAt(3)->get_elmt()->set_cible((Perso *) get_liste_Perso()->get_first()->get_elmt());
        }
        else if(_id_monde == 3)
        {
            get_liste_Mob()->empiler(new Mob(420,420,5,5,8,"SOLDAT ELITE", 30, 5, 105),1);
            get_liste_Mob()->get_itemAt(1)->get_elmt()->set_cible((Perso *) get_liste_Perso()->get_first()->get_elmt());
            get_liste_Mob()->empiler(new Mob(1500,1500,5,5,11,"COMMANDANT DE LA GARDE", 500, 1000, 168),1);
            get_liste_Mob()->get_itemAt(2)->get_elmt()->set_cible((Perso *) get_liste_Perso()->get_first()->get_elmt());
            get_liste_Mob()->empiler(new Mob(420,420,5,5,8,"SOLDAT ELITE", 30, 5, 105),1);
            get_liste_Mob()->get_itemAt(3)->get_elmt()->set_cible((Perso *) get_liste_Perso()->get_first()->get_elmt());
        }
        nb_mob = 3;
    }

    int choix;
    int fuite=0;
    int gold_gagne=0;
    int exp_gagne=0;
    bool res = false;
    while(!get_liste_Mob()->est_vide() && fuite != 1 && get_liste_Perso()->get_first()->get_elmt()->est_vivant())
    {
        clear();
        cout << "Vous vous faites attaquer par:" <<endl;
        get_liste_Mob()->afficher();
        cout << endl << endl;
        get_liste_Perso()->get_first()->get_elmt()->afficher_details();
        cout << endl << "Que voulez-vous faire ?" << endl << endl;
        cout << "1 - Attaquer" << endl;
        cout << "2 - Passer votre tour" << endl;
        cout << "3 - Tenter de Fuir" << endl;
        cout << endl << "Votre choix: ";

        std::cin >> choix;
        switch (choix)
        {
        case 1:
            cout << "Ennemi à cibler ? "<< endl;
            cout << "(Entrez son emplacement dans la liste d'ennemis)" << endl << "Votre choix: ";
            std::cin >> choix;
            if(get_liste_Mob()->get_itemAt(choix) != NULL) {
                get_liste_Perso()->get_first()->get_elmt()->attaquer((Mob *) get_liste_Mob()->get_itemAt(choix)->get_elmt());
            }
            break;

        case 2:
            cout << "Vous passer votre tour" << endl;
            break;

        case 3:
            fuite = randomInt(0,1);
            if(fuite == 0)
            {
                cout << "Vos ennemis vous ont rattrapé.." << endl;
            }
            break;
        }

        if(fuite == 0)
        {
            for(int i=1; i <= nb_mob; i++)
            {
                if(get_liste_Mob()->get_itemAt(i)->get_elmt()->est_mort()) {
                    gold_gagne += get_liste_Mob()->get_itemAt(i)->get_elmt()->get_val_gold();
                    exp_gagne += get_liste_Mob()->get_itemAt(i)->get_elmt()->get_val_exp();
                    get_liste_Mob()->supprimer(i);
                    nb_mob--;
                    i--;
                }
                else {
                    get_liste_Mob()->get_itemAt(i)->get_elmt()->attaquer_cible();
                    cout << endl;
                }
            }
            cout <<" (Entrez une touche pour continuer)" ;
            cin >> choix;
            std::cin.ignore(10000, '\n');
            cout << endl;
        }

    }

    if(get_liste_Mob()->est_vide())
    {
        cout << "Vous avez gagné ! Vous avez obtenu:" << endl;
        cout << gold_gagne << " Gold et " << exp_gagne << " Exp" << endl;
        get_liste_Perso()->get_first()->get_elmt()->gagner_gold(gold_gagne);
        get_liste_Perso()->get_first()->get_elmt()->gagner_exp(exp_gagne);
        res = true;
    }
    else if (fuite == 1)
    {
        cout << "Vous avez pris la fuite" << endl;
    }
    else if (!get_liste_Perso()->get_first()->get_elmt()->est_vivant())
    {
        cout << "Vous avez perdu le combat" << endl;
        cout << "Vous avez n'avez rien obtenu" << endl << endl;
    }

    cout <<" (Appuyer sur Entrée pour continuer)" ;
    std::cin.ignore(10000, '\n');

    get_liste_Mob()->clear_all();
    get_liste_Perso()->get_first()->get_elmt()->revive();
    return res;
}

void Game::boutique(void)
{
    bool back=false;
    int choix=0;

    while(!back)
    {
        clear();
        display_boutique();
        get_liste_Arme()->afficher();
        cout << endl;
        get_liste_Perso()->get_first()->get_elmt()->afficher_details();
        cout << endl << "1 - Acheter un objet" << endl;
        cout << "2 - Vendre un objet" << endl;
        cout << "3 - Partir" << endl;

        if(get_liste_Perso()->get_first()->get_elmt()->get_inventaire()->est_vide())
        {
            cout << endl <<"VOUS N'AVEZ RIEN A VENDRE";
        }

        cout << endl << "Votre Choix: ";
        cin >> choix;
        switch(choix)
        {
            case 1:
                cout << "Quelle Objet voulez vous acheter ? " << endl;
                cout << "(Entrez son emplacement dans l'inventaire de la boutique): ";
                cin >> choix;
                acheter(choix);
                break;

            case 2:
                cout << "Quelle Objet voulez vous vendre ? " << endl;
                cout << "(Entrez son emplacement dans votre inventaire): ";
                cin >> choix;
                vendre(choix);
                break;

            case 3:
                back = true;
                break;
        }
    }
}

// CREATION D'OBJET

void Game::generer_mob(void)
{
    ifstream fichier ("ressources/gen_mob.txt");
    fichier.seekg(0, ios::beg);
    string ligne="";
    string lignetestwhile = "#";
    lignetestwhile += to_string(get_id_monde());
    while(ligne[0] != lignetestwhile[0] || ligne[1] != lignetestwhile[1]){
        getline(fichier,ligne);
    }
    int nb_choix_mob; // Combien de mob je peux créer ?

    fichier.seekg(-1,ios::cur);
    fichier >> nb_choix_mob;

    int choix_mob = randomInt(1,nb_choix_mob); // Lequel doit être créer ?
    int compteur = 0;

    do {
        getline(fichier,ligne);
        compteur++;
    }while(compteur != choix_mob);

    //Enregistrement des données avant la création du mob
    std::string name_temp;
    float temp1[3];
    int temp2[3];
    float temp3;

    fichier >> name_temp >> temp1[0] >> temp1[1] >> temp1[2];
    fichier >> temp2[0] >> temp2[1] >> temp2[2] >> temp3;

    // Suppression des espaces dans le nom
    erase_space(name_temp);

    // Création du mob
    get_liste_Mob()->empiler(new Mob(temp1[0], temp1[0], temp1[1], temp1[2], temp2[0], name_temp, temp2[1], temp2[2], temp3),1);

    fichier.close();
}

void Game::add_perso(void)
{
    int classe;
    string nom;

    display_banner();
    cout << "CREATION D'UN NOUVEAU PERSONNAGE"<< endl << "Nom: ";
    cin >> nom;
    cout << "Choisissez une classe : 1 - Guerrier" << endl ;
    cout << "                        2 - Mage" << endl;
    cout << "Classe: ";
    cin >> classe;
    if(classe == 1) {
        _liste_Perso->empiler(new Guerrier(150, 150, 8, 0, 1, nom, 100));
    }
    else if(classe == 2) {
        _liste_Perso->empiler(new Mage(100, 100, 3, 0, 1, nom, 500));
    }

    set_id_monde(1);
    return;
}

void Game::delete_perso(void)
{
    _liste_Perso->depiler();
    set_id_monde(1);
}

// ACTION DU PERSO DANS LE JEU

void Game::changer_arme(const int emplacement)
{
    bool arme_changee = false;
    if(!(_liste_Perso->get_first()->get_elmt()->get_inventaire()->est_vide())) {
        if(_liste_Perso->get_first()->get_elmt()->get_inventaire()->get_itemAt(emplacement) != NULL) {
            if(_liste_Perso->get_first()->get_elmt()->get_inventaire()->get_itemAt(emplacement)->get_elmt()->est_arme()) {
                _liste_Perso->get_first()->get_elmt()->change_weapon((Arme *) _liste_Perso->get_first()->get_elmt()->get_inventaire()->get_itemAt(emplacement)->get_elmt());
                arme_changee = true;
            }
        }
    }

    if(!arme_changee) {
        _liste_Perso->get_first()->get_elmt()->change_weapon(NULL);
    }
}

void Game::add_objet(Objet *objet)
{
    _liste_Perso->get_first()->get_elmt()->get_inventaire()->empiler(objet);
}

void Game::add_objet(Objet *objet, const int nb_elmt)
{
    _liste_Perso->get_first()->get_elmt()->get_inventaire()->empiler(objet, nb_elmt);
}

void Game::supp_objet(const int emplacement)
{
    if(_liste_Perso->get_first()->get_elmt()->get_inventaire()->get_itemAt(emplacement) != NULL) {
        _liste_Perso->get_first()->get_elmt()->enlever_inventaire(emplacement);
    }
}

void Game::acheter(const int emplacement)
{
    if(_liste_Arme->get_itemAt(emplacement) != NULL && _liste_Perso->get_first()->get_elmt()->get_gold() >= int(_liste_Arme->get_itemAt(emplacement)->get_elmt()->get_valeur_gold())) {
        _liste_Perso->get_first()->get_elmt()->acheter_item(_liste_Arme->get_itemAt(emplacement)->get_elmt());
    }
}

void Game::vendre(const int emplacement)
{
    if(_liste_Perso->get_first()->get_elmt()->get_inventaire()->get_itemAt(emplacement) != NULL) {
        _liste_Perso->get_first()->get_elmt()->vendre_item(emplacement);
    }
}

// AFFICHAGE DES MENUS

void Game::display_story(void)
{
    ifstream fichier ("ressources/scenario.txt");
    fichier.seekg(0, ios::beg);
    string ligne="";
    string lignetestwhile = "#";
    lignetestwhile += to_string(get_id_monde());
    while(ligne[0] != lignetestwhile[0] || ligne[1] != lignetestwhile[1]){
        getline(fichier,ligne);
    }

    while(getline(fichier,ligne) && ligne[0] != '#')
    {
        cout << ligne << endl;
    }

    fichier.close();

    return;
}

void Game::display_boutique(void)
{
    clear();
    ifstream fichier ("ressources/boutique.txt");
    fichier.seekg(0, ios::beg);
    string ligne="";
    string lignetestwhile = "#";
    lignetestwhile += to_string(get_id_monde());
    while(ligne[0] != lignetestwhile[0] || ligne[1] != lignetestwhile[1]){
        getline(fichier,ligne);
    }

    while(getline(fichier,ligne) && ligne[0] != '#')
    {
        cout << ligne << endl;
    }

    fichier.close();
}

void Game::display_end(void)
{
    clear();

    cout << "~~ Merci d'avoir joué ! ~~" << endl << endl;
    cout << "Vous avez terminé le jeu !" << endl;
    cout <<" (Appuyer sur Entrée pour retourner au menu principal) "  << endl;
    cin.ignore(10000, '\n');

    return ;
}

void Game::afficher_perso_details(void)
{
    bool back=false;
    int choix=0;
    while(!back) {
        clear();
        get_liste_Perso()->get_first()->get_elmt()->afficher_details();
        cout << endl;
        cout << "1 - Changer d'arme" << endl;
        cout << "2 - Jeter un objet" << endl;
        cout << "3 - Retour" << endl;
        cout << endl << "Votre Choix: ";
        cin >> choix;

        switch(choix)
        {
            case 1:
                cout << "Quelle arme ? (Entrez son emplacement dans l'inventaire): ";
                cin>>choix;
                changer_arme(choix);
                break;

            case 2:
                cout << "Quelle Objet voulez vous jeter ? " << endl;
                cout << "(Entrez son emplacement dans l'inventaire): ";
                cin >> choix;
                supp_objet(choix);
                break;

            case 3:
                back = true;
                break;

            case 9:
                add_objet(new Epee(480,1,1200,"EPEE ETHER",265));
                break;

            case 8:
                add_objet(new Epee(560,1,1520,"LAME MAUDITE DU FLEAU",120));
                break;
        }
    }

    return;
}



void Game::display_banner(void)
{
    clear();
    cout << "#################################################" << endl;
    cout << "##   _________      ________      ________     ##" << endl;
    cout << "##  |   __    |    |   __   |    /  ___   \\    ##" << endl;
    cout << "##  |  |__|   |    |  |__|  |   |  /   \\__|    ##" << endl;
    cout << "##  |   __   _|    |   ____/    |  |   _____   ##" << endl;
    cout << "##  |  |  \\  \\     |  |         |  |   |_  _|  ##" << endl;
    cout << "##  |  |   \\  \\    |  |		|  \\____| |    ##" << endl;
    cout << "##  |__|    \\__\\   |__|		 \\________/    ##" << endl;
    cout << "##                                             ##" << endl;
    cout << "#################################################" << endl;
    cout << " ________________RPG(Version 0.5)_______________" << endl << endl;

}

void Game::clear(void)
{
// La commande pour effacer le "effacer" contenu d'un terminal varie selon l'OS
#if defined(_WIN32)
    system("cls");
    #endif
#if defined(__unix__)
    #if defined(__linux__)
    system("clear");
    #endif
#endif
    return;
}

// GETTEURS

ListeAdapt * Game::get_liste_Perso(void) const
{
    return _liste_Perso;
}

ListeAdapt * Game::get_liste_Arme(void) const
{
    return _liste_Arme;
}

ListeAdapt * Game::get_liste_Mob(void) const
{
    return _liste_Mob;
}

int Game::get_id_monde(void) const
{
    return _id_monde;
}

// SETTEURS

void Game::set_id_monde(const int id_monde)
{
    _id_monde = id_monde;
}

Game::~Game()
{
    delete _liste_Perso;
    delete _liste_Arme;
    delete _liste_Mob;
}
