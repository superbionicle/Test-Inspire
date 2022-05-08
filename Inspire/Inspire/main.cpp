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
#include "thème.hpp"
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
    vector<carte> liste_cartes=lecture_cartes(nom_theme,nom_question,nom_nb,nom_rep);
    // on récupère les infos pour récupérer les cartes
    
    vector<string> themes=recup_themes(nom_theme);
    vector<int> themes_occurences=recup_nb_themes(nom_theme, themes);
    
    clear();
    
    int choix_menu=0;
    do{
        clear();
        affichage();
        cout<<"Votre choix : ";
        cin>>choix_menu;
        switch(choix_menu){
            case 1:{
                clear();
                string pseudo;
                int score=0;
                cout<<"Entrez votre pseudo : ";
                cin>>pseudo;
                cout<<"Entrez votre score : ";
                cin>>score;
                
                // Note pour modification : ces trois lignes vont toujours ensemble
                tab.fin_partie(pseudo, score, nom_pseudos, nom_scores); // on regarde si on bat un des meilleurs scores
                ecriture_pseudos(nom_pseudos, tab); // on réécrit les pseudos classés
                ecriture_scores(nom_scores, tab); // on réécrit les scores classés
                // Si on souhaite rajouter un potentiel nouveau meilleur joueur
                
                cout<<endl<<"WIP Ranked"<<endl;
            }
                break;
            case 2:{
                clear();
                string theme_train;
                affichage_themes(themes, themes_occurences);
                cout<<"Quel thème voulez vous choisir ? : ";
                cin>>theme_train;
                vector<carte> cartes_theme=revision(theme_train, themes, liste_cartes);
                cout<<endl;
                for(int i=0;i<cartes_theme.size();i++){
                    cartes_theme[i].display();
                }
                cout<<"WIP Training"<<endl;
            }
                break;
            case 3:{
                clear();
                cout<<"WIP Ajout/Retrait thème"<<endl;
            }
                break;
            case 4:{
                /*clear();
                cout<<"Cartes existantes"<<endl;
                for(int i=0;i<liste_cartes.size();i++){
                    liste_cartes[i].display();
                }*/
                int nb_ajout=0;
                do{
                    cout<<"Combien de cartes voulez vous ajouter ? : ";
                    cin>>nb_ajout;
                }while(nb_ajout<0);
                ajout_carte(nb_ajout,nom_theme, nom_question, nom_nb, nom_rep);
                //cout<<"WIP Ajout cartes"<<endl;
            }
                break;
            case 5:{
                tab.display_contenu(); // on affiche les highscores
            }
                break;
            case 0:{
                cout<<"Merci et à bientot sur Inspire_Learn_Fast.exe"<<endl;
            }
                break;
            default:
                clear();
                cout<<"Mauvaise entrée, recommencez."<<endl;
            
        }
    }while(choix_menu!=0);
    return(0);
}
