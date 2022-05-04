//
//  menus.cpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//

#include "menus.hpp"
#include <iostream>
using namespace std;

void affichage(){
    cout<<"1. Jouer une partie scorée (tout thème confondu)"<<endl;
    cout<<"2. Faire une partie de révision selon un thème"<<endl;
    cout<<"3. Ajouter/Retirer un thème"<<endl;
    cout<<"4. Ajouter/Modifier/Retirer une carte"<<endl;
    cout<<"5. Voir les high-scores"<<endl;
    cout<<"0. Quitter (vous pouvez aussi appuyer sur Echap pour quitter"<<endl;
}

int menu_ranked(){
    return(0);
}

int menu_training(){
    int choix_2=0;
    do{
        cout<<"Que voulez vous faire ?"<<endl;
        cout<<"1. Choisir un thème"<<endl;
        cout<<"0. Retour au menu précédent"<<endl;
        cout<<"Votre choix : ";
        cin>>choix_2;
    }while(choix_2!=0);
    return(choix_2);
}

int menu_theme(){
    int choix_3=0;
    do{
        cout<<"Que voulez vous faire ?"<<endl;
        cout<<"1. Ajouter un thème"<<endl;
        cout<<"2. Retirer un thème"<<endl;
        cout<<"0. Retour au menu précédent"<<endl;
        cout<<"Votre choix : ";
        cin>>choix_3;
    }while(choix_3!=0);
    return(choix_3);
}

int menu_carte(){
    int choix_4=0;
    do{
        cout<<"Que voulez vous faire ?"<<endl;
        cout<<"1. Ajouter une carte à un thème"<<endl;
        cout<<"2. Modifier une carte d'un thème"<<endl;
        cout<<"3. Retirer une carte d'un thème"<<endl;
        cout<<"0. Retour au menu précédent"<<endl;
        cout<<"Votre choix : ";
        cin>>choix_4;
    }while(choix_4!=0);
    return(choix_4);
}

