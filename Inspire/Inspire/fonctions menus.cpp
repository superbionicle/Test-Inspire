//
//  fonctions menus.cpp
//  Inspire
//
//  Created by Arthur on 08/05/2022.
//

#include "fonctions menus.hpp"

// Importation des libraries
#include <iostream>
#include <vector>

// Importation des headers
#include "carte.hpp"
#include "lecture ecriture.hpp"
#include "fonctions theme.hpp"

using namespace std;

void clear(){
    for(int i=0;i<40;i++){
        cout<<endl;
    }
}

void ajout_carte(int nb_ajout,string nom_theme,string nom_question,string nom_nb,string nom_rep){
    vector<carte> ensemble_temp;
    string tampon;
    for(int i=0;i<nb_ajout;i++){
        carte carte_temp;
        cout<<endl<<endl<<endl;
        cout<<"Ajouter une carte"<<endl;
        cout<<"Quel thème pour la carte : ";
        string theme;
        //cin>>theme;
        getline(cin,theme);
        //getline(cin,tampon);
        carte_temp.set_theme(theme);
        carte_temp.set_question();
        carte_temp.set_reponses();
        ensemble_temp.push_back(carte_temp);
        //cout<<ensemble_temp[ensemble_temp.size()].display();
        //clear();
        cout<<endl<<endl<<endl<<endl<<endl;
    }
    for(int i=0;i<ensemble_temp.size();i++){
        cout<<"Contenu ajouté : "<<endl;
        ensemble_temp[i].display();
        cout<<endl;
    }
    ecriture(nom_theme,nom_question, nom_nb, nom_rep, ensemble_temp);
}

void training(vector<string> themes,vector<int> themes_occurences,vector<carte> liste_cartes){
    string theme_train;
    string tampon;
    affichage_themes(themes, themes_occurences);
    cout<<"Quel thème voulez vous choisir ? : ";
    //cin>>theme_train;
    getline(cin,theme_train);
    getline(cin,tampon);
    vector<carte> cartes_theme=revision(theme_train, themes, liste_cartes);
    cout<<endl;
    int points=0;
    for(int i=0;i<cartes_theme.size();i++){
        //cartes_theme[i].display();
        bool training=cartes_theme[i].poser_question();
        if(training){
            points++;
        }
        cout<<endl;
    }
    if(points==1){
        cout<<"Vous avez répondu correctement à "<<points<<" question."<<endl;
    }
    else if (points==0){
        cout<<"Vous n'avez répondu correctement à aucune question."<<endl;
    }
    else{
        cout<<"Vous avez répondu correctement à "<<points<<" questions."<<endl;
    }
}

void ranked(highscores tab,vector<carte> liste_cartes,string nom_pseudos,string nom_scores){
    string pseudo;
    string tampon;
    int score=0;
    cout<<"Entrez votre pseudo : ";
    //cin>>pseudo;
    getline(cin,pseudo);
    getline(cin,tampon);
    bool reussite=true;
    int i=0;
    do{
        clear();
        cout<<"Votre score actuel : "<<score<<endl;
        reussite=liste_cartes[i].poser_question();
        if(reussite){
            score++;
        }
        i++;
    }while(reussite && i<liste_cartes.size());
    
    // Note pour modification : ces trois lignes vont toujours ensemble
    tab.fin_partie(pseudo, score, nom_pseudos, nom_scores); // on regarde si on bat un des meilleurs scores
    ecriture_pseudos(nom_pseudos, tab); // on réécrit les pseudos classés
    ecriture_scores(nom_scores, tab); // on réécrit les scores classés
    // Si on souhaite rajouter un potentiel nouveau meilleur joueur
}
