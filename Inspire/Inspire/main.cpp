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


using namespace std;


int main(){
    string const nom("scores.txt"); // on récupère le nom du fichier .txt des scores
    highscores tab=init(nom); // on initialise le fichier des scores
    // soit on récupère les données qui existe déjà
    // soit on crée un fichier vide et on initialise le tableau des scores
    string const nom_theme("themes_question.txt"),nom_question("questions.txt"),nom_nb("nb_rep.txt"),nom_rep("rep.txt");
    vector<carte> liste_cartes=lecture_cartes(nom_theme,nom_question,nom_nb,nom_rep);
    //vector<theme> liste_theme;
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
                cout<<"WIP Training"<<endl;
            }
                break;
            case 3:{
                cout<<"WIP Ajout/Retrait thème"<<endl;
            }
                break;
            case 4:{
                for(int i=0;i<liste_cartes.size();i++){
                    liste_cartes[i].display();
                }
                vector<carte> ensemble_temp;
                int rep=0;
                do{
                    carte carte_temp;
                    cout<<"Ajouter une carte : "<<endl;
                    cout<<"Quel thème pour la carte : ";
                    string theme;
                    cin>>theme;
                    carte_temp.set_theme(theme);
                    carte_temp.set_question();
                    carte_temp.set_reponses();
                    ensemble_temp.push_back(carte_temp);
                    cout<<"Que voulez vous faire ?"<<endl;
                    cout<<"Entrez 0 si vous avez fini d'ajouter des cartes"<<endl;
                    cout<<"Entrez un autre chiffre si vous voulez continuez à en ajouter"<<endl;
                    cout<<"Votre choix : ";
                    cin>>rep;
                }while(rep!=0);
                for(int i=0;i<liste_cartes.size();i++){
                    cout<<"Contenu ajouté : "<<endl;
                    ensemble_temp[i].display();
                    cout<<endl;
                }
                ecriture(nom_theme,nom_question, nom_nb, nom_rep, ensemble_temp);
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
                cout<<"Mauvaise entrée, recommencez."<<endl;
            
        }
    }while(choix_menu!=0);
    return(0);
}
