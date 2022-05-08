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
#include "fonctions menus.hpp"


using namespace std;

void carte::set_question(){
    string question_temp;
    cout<<"Quel est votre question ?"<<endl;
    //cin>>question_temp;
    getline(cin,question_temp);
    question=question_temp;
}

void carte::set_reponses(){
    string tampon;
    cout<<"Rappel de la question : "<<question<<endl;
    int nb_erreurs=1;
    string reponse_correcte;
    cout<<"Saisissez la bonne réponse à votre question :"<<endl;
    //cin>>reponse_correcte; // L'user entre d'abord la bonne réponse
    getline(cin,reponse_correcte);
    //getline(cin,tampon);
    reponses.push_back(reponse_correcte); // On ajoute la bonne réponse à la liste des réponses possibles
    do{
        cout<<"Combien de mauvaises réponses voulez vous (entre 1 et 3) : ";
        cin>>nb_erreurs; // On demande combien de mauvaises réponses l'user souhaite-il (entre 1 et 3)
        // permet de gérer la mauvaise saisie d'un utilisateur
        if(cin.eof() || cin.bad()){
            cerr<<"Erreur interne"<<endl;
        }
        else if(cin.fail()){
            cerr<<"Mauvaise saisie"<<endl;
            nb_erreurs=-1;
        }
        vider_buffer();
        // fin de la gestion de la mauvaise saisie
        getline(cin,tampon);
    }while(nb_erreurs<1 || nb_erreurs>3); // On boucle tant qu'on a pas la bonne réponse
    for(int i=0;i<nb_erreurs;i++){ // Pour le nombre souhaité, on lui fait rentrer les mauvaises réponses
        string erreur;
        cout<<"Saisissez une mauvaise réponse à votre question : "<<endl;
        //cin>>erreur; // L'user entre une mauvaise réponse
        getline(cin,erreur);
        //getline(cin,tampon);
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
    string tampon;
    cout<<question<<endl;
    int reponse=0;
    int nb_rep=reponses.size();
    do{
        display_rep();
        cout<<"Entrez le numéro de la réponse qui vous semble correcte ";
        cout<<"(Entre 1 et "<<reponses.size()<<") : "<<endl;
        cin>>reponse;
        
        // permet de gérer la mauvaise saisie d'un utilisateur
        if(cin.eof() || cin.bad()){
            cerr<<"Erreur interne"<<endl;
        }
        else if(cin.fail()){
            cerr<<"Mauvaise saisie"<<endl;
            reponse=-2;
        }
        vider_buffer();
        // fin de la gestion de la mauvaise saisie
        
        getline(cin,tampon);
        /*cout<<"Reponse : "<<reponse<<endl;
        cout<<"Nombre de réponses possibles : "<<reponses.size()<<endl;
        
        if(reponse<0){
            cout<<"Reponse < 0"<<endl;
        }
        else{
            cout<<"Reponse > 0"<<endl;
        }
        int nb_rep=reponses.size();
        if(reponse>nb_rep){
            cout<<"Reponse > "<<reponses.size()<<endl;
        }
        else{
            cout<<"Reponse < "<<reponses.size()<<endl;
        }*/
            }while(reponse<1 || reponse>nb_rep);
    if(reponse==1){
        cout<<"Bonne réponse"<<endl;
        reussite=true;
    }
    else{
        cout<<"Mauvaise réponse"<<endl;
    }
    return(reussite);
}
