//
//  main.cpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//

// Importation des libraries
#include <iostream>
#include <fstream>
#include <vector>

// Importation des headers
#include "scores.hpp"
#include "menus.hpp"
#include "carte.hpp"
#include "lecture ecriture.hpp"
#include "fonctions menus.hpp"
#include "fonctions theme.hpp"


using namespace std;



int main(){
    // Zone initialisation des fichiers
    string const nom_scores("scores.txt"); // on récupère le nom du fichier .txt pour les scores
    string const nom_pseudos("pseudos.txt"); // on récupère le nom du fichier .txt pour les pseudos du highscores
    string const nom_theme("themes_question.txt"),nom_question("questions.txt"),nom_nb("nb_rep.txt"),nom_rep("rep.txt");
    
    highscores tab=init(nom_scores, nom_pseudos); // on init notre tableau des highscores
    // soit on récupère les données qui existe déjà
    // soit on crée un fichier vide et on initialise le tableau des scores
    
    
    clear();
    
    int choix_menu=0;
    do{
        cout<<endl<<endl<<endl;
        vector<carte> liste_cartes=lecture_cartes(nom_theme,nom_question,nom_nb,nom_rep); // on récupère les infos pour récupérer les cartes
        vector<string> themes=recup_themes(nom_theme);
        vector<int> themes_occurences=recup_nb_themes(nom_theme, themes);
        //clear();
        affichage();
        cout<<"Votre choix : ";
        cin>>choix_menu;
        switch(choix_menu){
            case 1:{ // On lance une ranked
                clear();
                ranked(tab,liste_cartes,nom_pseudos,nom_scores);
            }
                break;
            case 2:{ // On s'entraine sur les questions
                clear();
                training(themes, themes_occurences, liste_cartes);
            }
                break;
            case 3:{ // On ajoute des cartes
                clear();
                int nb_ajout=0;
                do{
                    cout<<"Combien de cartes voulez vous ajouter ? : ";
                    cin>>nb_ajout;
                }while(nb_ajout<0);
                ajout_carte(nb_ajout,nom_theme, nom_question, nom_nb, nom_rep);
            }
                break;
            case 4:{ // On affiche les highscores
                clear();
                tab.display_contenu(); // on affiche les highscores
            }
                break;
            case 0:{ // On quitte le programme
                clear();
                cout<<"Merci et à bientot sur Inspire_Learn_Fast.exe"<<endl;
            }
                break;
            default: // On s'est trompé dans la touche pour naviguer dans le menu
                clear();
                cout<<"Mauvaise entrée, recommencez."<<endl;
            
        }
    }while(choix_menu!=0);
    return(0);
}
