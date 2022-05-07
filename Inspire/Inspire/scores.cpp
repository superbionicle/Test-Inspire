//
//  scores.cpp
//  Inspire
//
//  Created by Arthur on 07/05/2022.
//

#include "scores.hpp"
#include <iostream>
#include <fstream>
using namespace std;

void highscores::insertion(string pseudo,int score){
    scores.push_back(score);
    pseudos.push_back(pseudo);
    for(int i=0;i<taille;i++){
        for(int j=0;j<taille-i;j++){
            if(scores[j]<scores[j+1]){
                swap(scores[j],scores[j+1]);
                swap(pseudos[j],pseudos[j+1]);
            }
        }
    }
    scores.pop_back();
    pseudos.pop_back();
}

highscores::highscores(vector<string> users,vector<int>scores_users,int taille_user){
    pseudos=users;
    scores=scores_users;
    taille=taille_user;
}

highscores::highscores(int taille_user){
    taille=taille_user;
    for(int i=0;i<taille;i++){
        pseudos.push_back("Bot");
        scores.push_back(0);
    }
}


highscores::~highscores(){
    pseudos.clear();
    scores.clear();
    
}

void highscores::display_contenu(){
    string* pseudos_temp=new string[taille];
    int* scores_temp=new int[taille];
    
    cout<<"Highscores"<<endl<<endl;

    for(int i=0;i<taille;i++){
        pseudos_temp[i]=pseudos[i];
        scores_temp[i]=scores[i];
    }
    
    for(int i=0;i<taille;i++){
        cout<<"n°"<<i+1<<". \t"<<pseudos_temp[i]<<" | Score : "<<scores_temp[i]<<endl;
    }
}


void highscores::fin_partie(string pseudo,int score){
    // Test pour rentrer dans le highscore
    bool rentre=false;
    for(int i=0;i<taille;i++){
        if(score>scores[i]){
            rentre=true;
        }
    }
    //Si on a battu un score
    if(rentre){
        insertion(pseudo,score);
        cout<<"\t Bienvenue dans les highscores"<<endl;
    }
    //Si on a pas battu de scores
    else{
        cout<<"\t Dommage, soyez meilleur(e) la prochaine fois"<<endl;
    }
    cout<<endl<<"....................................................................."<<endl<<endl;
    display_contenu();
}


string* highscores::get_pseudos(){
    string* retour=new string[taille];
    for(int i=0;i<taille;i++){
        retour[i]=pseudos[i];
    }
    return (retour);
}


int* highscores::get_scores(){
    int* retour=new int[taille];
    for(int i=0;i<taille;i++){
        retour[i]=scores[i];
    }
    return(retour);
}

