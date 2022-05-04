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
void carte::set_reponses(){
    cout<<"Rappel de la question : "<<question<<endl;
    //cout<<"Est ce une question vrai/faux ? ";
    string reponse_bool;
    do{
        cout<<"Est ce une question vrai/faux ? "<<endl;
        cout<<"Si oui, tapez \"oui\""<<endl;
        cout<<"Si non, tapez \"non\""<<endl;
        cin>>reponse_bool;
    }while(reponse_bool!="oui" && reponse_bool!="non");
    if(reponse_bool=="oui"){
        reponses.push_back("Vrai");
        reponses.push_back("Faux");
    }
    else{
        int nb_erreurs=1;
        string reponse_correcte;
        cout<<"Saisissez la bonne réponse à votre question (entre 1 et 3) :"<<endl;
        cin>>reponse_correcte;
        do{
            cout<<"Combien de mauvaises réponses voulez vous : ";
            cin>>nb_erreurs;
        }while(nb_erreurs<0 && nb_erreurs>3);
    }
    
}
bool carte::lancer_question(){
    bool reussite=false;
    return(reussite);
}
