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

using namespace std;

void clear(){
    for(int i=0;i<40;i++){
        cout<<endl;
    }
}

void ajout_carte(int nb_ajout,string nom_theme,string nom_question,string nom_nb,string nom_rep){
    vector<carte> ensemble_temp;
    for(int i=0;i<nb_ajout;i++){
        carte carte_temp;
        cout<<endl<<endl<<endl;
        cout<<"Ajouter une carte"<<endl;
        cout<<"Quel thème pour la carte : ";
        string theme;
        cin>>theme;
        carte_temp.set_theme(theme);
        carte_temp.set_question();
        carte_temp.set_reponses();
        ensemble_temp.push_back(carte_temp);
        //cout<<ensemble_temp[ensemble_temp.size()].display();
        clear();
    }
    for(int i=0;i<ensemble_temp.size();i++){
        cout<<"Contenu ajouté : "<<endl;
        ensemble_temp[i].display();
        cout<<endl;
    }
    ecriture(nom_theme,nom_question, nom_nb, nom_rep, ensemble_temp);
}
