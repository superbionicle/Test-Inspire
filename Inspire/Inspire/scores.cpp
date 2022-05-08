//
//  scores.cpp
//  Inspire
//
//  Created by Arthur on 07/05/2022.
//


// Importation des libraries
#include <iostream>
#include <fstream>

// Importation des headers
#include "scores.hpp"
#include "lecture ecriture.hpp"

using namespace std;

void highscores::insertion(string pseudo,int score){ // On veut rajouter un nouveau joueur et son score aux highscores
    scores.push_back(score); // On push le score dans le vector des scores
    pseudos.push_back(pseudo); // On push le pseudo dans le vector des pseudos
    for(int i=0;i<taille;i++){ // Tri à bulle des vectors pour remonter les meilleurs en début du vecteurs
        for(int j=0;j<taille-i;j++){ // on effectue le tri en fonction du score (du plus haut au plus bas)
            if(scores[j]<scores[j+1]){
                swap(scores[j],scores[j+1]); // permet d'échanger les position
                swap(pseudos[j],pseudos[j+1]); // permet d'échanger les positions
            }
        }
    }
    scores.pop_back(); // on retire le dernier pour etre raccord avec la taille
    pseudos.pop_back(); // on retire le dernier pour etre raccord avec la taille
}

highscores::highscores(vector<string> users,vector<int>scores_users,int taille_user){ // init selon des données
    pseudos=users;
    scores=scores_users;
    taille=taille_user;
}

highscores::highscores(int taille_user){ // init selon un nb d'affichage max
    taille=taille_user;
    for(int i=0;i<taille;i++){
        pseudos.push_back("Bot"); // on met par défaut le nom "Bot"
        scores.push_back(0); // avec un score de 0
    }
}


highscores::~highscores(){ // destructeur
    pseudos.clear();
    scores.clear();
    
}

void highscores::display_contenu(){ // on affiche le contenu des highscores
    cout<<"Highscores"<<endl<<endl;
    for(int i=0;i<taille;i++){ // on affiche les lignes des scores (classement | pseudo | score)
        cout<<"n°"<<i+1<<". \t"<<pseudos[i]<<" | Score : "<<scores[i]<<endl;
    }
    cout<<endl;
}


void highscores::fin_partie(string pseudo,int score,string nom_pseudos,string nom_scores){ // on arrive en fin de partie
    // Test pour rentrer dans le highscore
    bool rentre=false;
    for(int i=0;i<taille;i++){ // on parcourt tous les scores du highscores
        if(score>scores[i]){ // on regarde si on a battu au moins un score
            rentre=true; // si oui, on pourra rentrer dans les highscores
        }
    }
    //Si on a battu un score
    if(rentre){
        insertion(pseudo,score); // on insert le pseudo et le score dans les highscores
        cout<<"\t Bienvenue dans les highscores"<<endl;
    }
    //Si on a pas battu de scores
    else{
        cout<<"\t Dommage, soyez meilleur(e) la prochaine fois"<<endl;
    }
    cout<<endl<<"....................................................................."<<endl<<endl;
    display_contenu(); // on affiche le contenu des highscores
}


string* highscores::get_pseudos(){ // on recupere la liste des pseudos du highscores
    string* retour=new string[taille];
    for(int i=0;i<taille;i++){
        retour[i]=pseudos[i];
    }
    return (retour);
}


int* highscores::get_scores(){ // on recupere la liste des scores du highscores
    int* retour=new int[taille];
    for(int i=0;i<taille;i++){
        retour[i]=scores[i];
    }
    return(retour);
}

