//
//  carte.cpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//


// Importation des libraries
#include <string.h>

// Importation des headers
#include "carte.hpp"


using namespace std;

void carte::set_question(){
    string question_temp;
    cout<<"Quel est votre question ?"<<endl;
    cin>>question_temp;
    question=question_temp;
}

void carte::set_reponses(){
    cout<<"Rappel de la question : "<<question<<endl;
    int nb_erreurs=1;
    string reponse_correcte;
    cout<<"Saisissez la bonne réponse à votre question :"<<endl;
    cin>>reponse_correcte; // L'user entre d'abord la bonne réponse
    reponses.push_back(reponse_correcte); // On ajoute la bonne réponse à la liste des réponses possibles
    do{
        cout<<"Combien de mauvaises réponses voulez vous (entre 1 et 3) : ";
        cin>>nb_erreurs; // On demande combien de mauvaises réponses l'user souhaite-il (entre 1 et 3)
    }while(nb_erreurs<1 || nb_erreurs>3); // On boucle tant qu'on a pas la bonne réponse
    for(int i=0;i<nb_erreurs;i++){ // Pour le nombre souhaité, on lui fait rentrer les mauvaises réponses
        string erreur;
        cout<<"Saisissez une mauvaise réponse à votre question : "<<endl;
        cin>>erreur; // L'user entre une mauvaise réponse
        reponses.push_back(erreur); // On ajoute la mauvaise réponse à la liste des réponses possibles
    }
    cout<<"Fin de l'édition de la question et de ses réponses"<<endl;
    
}

vector<string> carte::get_reponses(){
    vector<string> reponses_question;
    for(int i=0;i<reponses.size();i++){
        reponses_question.push_back(reponses[i]);
    }
    return(reponses_question);
}

void carte::set_reponses(int nb,vector<string> rep){
    for(int i=0;i<nb;i++){
        reponses.push_back(rep[i]);
    }
}

void carte::display(){
    cout<<"Thème : "<<theme_carte<<endl;
    cout<<"Question : "<<question<<endl;
    for(int i=0;i<reponses.size();i++){
        cout<<"Reponse "<<i+1<<" : "<<reponses[i]<<endl;
    }
    cout<<endl;
}

void carte::display_rep(){
    for(int i=0;i<reponses.size();i++){
        cout<<"Reponse "<<i+1<<" : "<<reponses[i]<<endl;
    }
}

bool carte::poser_question(){
    bool reussite=false;
    cout<<question<<endl;
    int reponse=0;
    do{
        display_rep();
        cout<<"Entrez le numéro de la réponse qui vous semble correcte : ";
        cin>>reponse;
    }while(reponse<-1 && reponse>reponses.size());
    if(reponse==1){
        cout<<"Bonne réponse"<<endl;
        reussite=true;
    }
    else{
        cout<<"Mauvaise réponse"<<endl;
    }
    return(reussite);
}
