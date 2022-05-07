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
    for(int i=0;i<taille-1;i++){
        for(int j=0;j<taille-i-1;j++){
            if(scores[j]>scores[j+1]){
                swap(scores[j],scores[j+1]);
                swap(pseudos[j],pseudos[j+1]);
            }
        }
    }
    scores.pop_back();
    pseudos.pop_back();
}


highscores::highscores(){
    
}


highscores::~highscores(){
    pseudos.clear();
    scores.clear();
    
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
    cout<<endl<<endl<<endl;
    cout<<"Highscores"<<endl<<endl;
    for(int i=0;i<<taille;i++){
        cout<<i+1<<"\t"<<pseudos[i]<<"\t"<<scores[i]<<endl;
    }
}
