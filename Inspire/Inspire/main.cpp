//
//  main.cpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//

#include <iostream>
#include <vector>
#include "carte.hpp"
#include "thème.hpp"
#include "menus.hpp"

using namespace std;


int main(){
    
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
                int choix_2=menu_training();
                cout<<"WIP Training"<<endl;
            }
                break;
            case 3:{
                int choix_3=menu_theme();
                cout<<"WIP Ajout/Retrait thème"<<endl;
            }
                break;
            case 4:{
                int choix_4=menu_carte();
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
                }
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
