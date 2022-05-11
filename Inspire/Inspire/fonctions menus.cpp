//
//  fonctions menus.cpp
//  Inspire
//
//  Created by Arthur on 08/05/2022.
//

#include "fonctions menus.hpp"

// Importation des libraries
#include <iostream>
#include <fstream>
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
    
    // au dessus quand on debug
    // en dessous quand on a fini et qu'on lance le .exe
    
    /*#if defined _WIN32
        system("cls");
        //clrscr(); // including header file : conio.h
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
        //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
    #elif defined (__APPLE__)
        system("clear");
    #endif*/
}

void ajout_carte(int nb_ajout,string nom_theme,string nom_question,string nom_nb,string nom_rep){
    vector<carte> ensemble_temp;
    string tampon;
    for(int i=0;i<nb_ajout;i++){
        clear();
        carte carte_temp;
        cout<<endl<<endl<<endl;
        cout<<"Ajouter une carte ("<<i<<"/"<<nb_ajout<<")"<<endl;
        cout<<"Quel thème pour la carte : ";
        string theme;
        getline(cin,theme); // on stocke le theme de la question
        carte_temp.set_theme(theme); // on définit le theme
        carte_temp.set_question(); // on définit la question
        carte_temp.set_reponses(); // on définit les réponses
        ensemble_temp.push_back(carte_temp);
        clear();
        //cout<<endl<<endl<<endl<<endl<<endl;
    }
    for(int i=0;i<ensemble_temp.size();i++){
        cout<<"Contenu ajouté : "<<endl;
        ensemble_temp[i].display(); // on affiche ce qu'on a ajouté au deck de cartes
        cout<<endl;
    }
    ecriture(nom_theme,nom_question, nom_nb, nom_rep, ensemble_temp); // on enregistre les nouvelles cartes dans les .txt
}

void training(vector<string> themes,vector<int> themes_occurences,vector<carte> liste_cartes){
    string theme_train;
    string tampon;
    affichage_themes(themes, themes_occurences);
    cout<<"Quel thème voulez vous choisir ? : ";
    getline(cin,theme_train);
    vector<carte> cartes_theme=revision(theme_train, themes, liste_cartes); // on récupère toutes les cartes du thème
    cout<<endl;
    int points=0;
    for(int i=0;i<cartes_theme.size();i++){
        clear();
        cout<<"Question "<<i<<" sur "<<cartes_theme.size()<<endl;
        bool training=cartes_theme[i].poser_question();
        if(training){
            points++;
        }
        //cout<<endl;
        clear();
    }
    // on affiche les scores en fonction de ce qu'on a obtenu en terme de bonnes réponses
    // tout en rappelant le nombre total de questions du thème
    if(points==1){
        cout<<"Vous avez répondu correctement à "<<points<<" question sur "<<cartes_theme.size()<<"."<<endl;
    }
    else if (points==0){
        cout<<"Vous n'avez répondu correctement à aucune question."<<endl;
    }
    else{
        cout<<"Vous avez répondu correctement à "<<points<<" questions sur "<<cartes_theme.size()<<"."<<endl;
    }
}

void ranked(highscores tab,vector<carte> liste_cartes,string nom_pseudos,string nom_scores){
    string pseudo;
    string tampon;
    int total_question=liste_cartes.size();
    int score=0;
    cout<<"Entrez votre pseudo : ";
    getline(cin,pseudo);
    bool reussite=true;
    int i=0;
    do{
        clear();
        cout<<"Votre score actuel : "<<score<<endl;
        cout<<"Question "<<i<<" sur "<<total_question<<endl;
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

void init_vecteur(string nom_theme,string nom_question,string nom_nb,string nom_rep){
    ofstream lecture_theme(nom_theme.c_str(),ios::app);
    lecture_theme.close();
    
    ofstream lecture_questions(nom_question.c_str(),ios::app);
    lecture_questions.close();
    
    ofstream lecture_nb(nom_nb.c_str(),ios::app);
    lecture_nb.close();
    
    ofstream lecture_rep(nom_rep.c_str(),ios::app);
    lecture_rep.close();
}

void vider_buffer(){ // permet de nettoyer le buffer quand on foire une saisie au cin
    cin.clear();
    cin.seekg(0,ios::end);
    if(!cin.fail()){
        cin.ignore(numeric_limits<streamsize>::max());
    }
    else{
        cin.clear();
    }
}
