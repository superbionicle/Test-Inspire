//
//  carte.cpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//

#include "carte.hpp"
#include <stdlib.h>
#include <string.h>
using namespace std;

carte::carte(){
    
}
carte::~carte(){
    
}

void carte::set_question(){
    string question_temp;
    cout<<"Quel est votre questio ?"<<endl;
    cin>>question_temp;
    question=question_temp;
}

void carte::set_reponses(){
    cout<<"Rappel de la question : "<<question<<endl;
    string reponse_bool;
    do{ // On cherche à savoir s'il s'agit d'un vrai/faux
        cout<<"Est ce une question vrai/faux ? "<<endl;
        cout<<"Si oui, tapez \"oui\""<<endl;
        cout<<"Si non, tapez \"non\""<<endl;
        cin>>reponse_bool;
    }while(reponse_bool!="oui" && reponse_bool!="non"); // On boucle tant qu'on a pas la bonne réponse
    if(reponse_bool=="oui"){ // S'il s'agit d'un vrai/faux, on met directement les réponses
        reponses.push_back("Vrai");
        reponses.push_back("Faux");
    }
    else{// Sinon, on demande à l'utilisateur d'entrer les réponses lui même
        int nb_erreurs=1;
        string reponse_correcte;
        cout<<"Saisissez la bonne réponse à votre question (entre 1 et 3) :"<<endl;
        cin>>reponse_correcte; // L'user entre d'abord la bonne réponse
        reponses.push_back(reponse_correcte); // On ajoute la bonne réponse à la liste des réponses possibles
        do{
            cout<<"Combien de mauvaises réponses voulez vous : ";
            cin>>nb_erreurs; // On demande combien de mauvaises réponses l'user souhaite-il (entre 1 et 3)
        }while(nb_erreurs<0 && nb_erreurs>3); // On boucle tant qu'on a pas la bonne réponse
        for(int i=0;i<nb_erreurs;i++){ // Pour le nombre souhaité, on lui fait rentrer les mauvaises réponses
            string erreur;
            cout<<"Saisissez une mauvaise réponse à votre question : "<<endl;
            cin>>erreur; // L'user entre une mauvaise réponse
            reponses.push_back(erreur); // On ajoute la mauvaise réponse à la liste des réponses possibles
        }
        cout<<"Fin de l'édition de la question et de ses réponses"<<endl;
    }
    
}
bool carte::lancer_question(){
    bool reussite=false;
    return(reussite);
}
