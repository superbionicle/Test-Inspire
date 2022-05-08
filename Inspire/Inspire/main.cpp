//
//  main.cpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "scores.hpp"
#include "menus.hpp"
#include "carte.hpp"
#include "thème.hpp"
#include "lecture ecriture.hpp"

using namespace std;


int main(){
    string const nom("scores.txt"); // on récupère le nom du fichier .txt
    highscores tab=init(nom);
    ecriture(nom, tab);
    affichage_contenu(nom);
    tab.display_contenu(); // on vérifie la cohérence avec ce qui a été écrit dans le .txt
    
    string const nom_theme("themes_question.txt"),nom_question("questions.txt"),nom_nb("nb_rep.txt"),nom_rep("rep.txt");
        /*ofstream init_theme(nom_theme.c_str());
        init_theme.close();
        ofstream init_quest(nom_question.c_str());
        init_quest.close();
        ofstream init_nb(nom_nb.c_str());
        init_nb.close();
        ofstream init_rep(nom_rep.c_str());
        init_rep.close();*/
        
        /*carte test;
        test.set_theme("test");
        test.set_question("Pouet");
        test.set_reponses();
        
        vector<carte> ensemble_test;
        ensemble_test.push_back(test);
        
        ecriture(nom_theme, nom_question, nom_nb, nom_rep, ensemble_test);*/
        
        vector<carte> lecture;
        lecture=lecture_cartes(nom_theme,nom_question,nom_nb,nom_rep);
        for(int i=0;i<lecture.size();i++){
            lecture[i].display();
        }
    
    
    vector<carte> liste_cartes;
    vector<theme> liste_theme;
    int choix_menu=0;
    do{
        affichage();
        cout<<"Votre choix : ";
        cin>>choix_menu;
        switch(choix_menu){
            case 1:{
                cout<<"WIP Ranked"<<endl;
            }
                break;
            case 2:{
                //int choix_2=menu_training();
                cout<<"WIP Training"<<endl;
            }
                break;
            case 3:{
                //int choix_3=menu_theme();
                cout<<"WIP Ajout/Retrait thème"<<endl;
            }
                break;
            case 4:{
                /*int choix_4=menu_carte();
                switch (choix_4) {
                    case 1:{
                        carte carte_temp;
                        cout<<"Saisir le thème de la carte : ";
                        string theme;
                        cin>>theme;
                        carte_temp.set_theme(theme);
                        carte_temp.set_question();
                        carte_temp.set_reponses();
                        liste_cartes.push_back(carte_temp);
                        
                    }
                        break;
                        
                    default:
                        break;
                }*/
                cout<<"WIP Ajout/Modif/Retrait cartes"<<endl;
            }
                break;
            case 5:{
                cout<<"WIP High-scores"<<endl;
            }
                break;
            case 0:{
                cout<<"Merci et à bientot sur Inspire_Learn_Fast.exe"<<endl;
            }
                break;
            default:
                cout<<"Mauvaise entrée, recommence batard"<<endl;
            
        }
    }while(choix_menu!=0);
    return(0);
}
