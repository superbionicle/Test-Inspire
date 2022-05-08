//
//  fonctions theme.cpp
//  Inspire
//
//  Created by Arthur on 08/05/2022.
//

// Importation des libraries
#include <iostream>
#include <fstream>
#include <vector>

// Importation des headers
#include "fonctions theme.hpp"
#include "fonctions menus.hpp"

using namespace std;


vector<string> recup_themes(string nom_theme){
    vector<string> theme_temp; // on crée un vector avec tous les thèmes
    ifstream lecture_theme(nom_theme.c_str()); // récupération de l'ensemble des themes des questions
    if(lecture_theme){
        string line;
        while(getline(lecture_theme,line)){
            theme_temp.push_back(line); // on récupère les thèmes de toutes les cartes
        }
    }
    else{
        cout<<"Erreur lors de l'ouverture du fichier pour la lecture des questions des cartes"<<endl;
    }
    vector<string> liste_themes; // on crée notre vector des thèmes sans doublons
    for(int i=0;i<theme_temp.size();i++){ // on parcourt tous les thèmes récupérés
        bool deja=false; // on part du principe que le thème n'a pas été vu encore
        for(int j=0;j<liste_themes.size();j++){ // on parcout toutes les cartes et leurs thèmes
            if(theme_temp[i]==liste_themes[j]){
                deja=true; // si on croise le thème, alors on ne le prendra pas
            }
        }
        if(!deja){
            liste_themes.push_back(theme_temp[i]); // si on l'a pas croisé, on l'ajoute à la liste de thèmes dispo
        }
    }
    return (liste_themes);
}

vector<int> recup_nb_themes(string nom_theme,vector<string> liste_themes){
    vector<int> nb_theme_temp; // on crée notre vector des nb d'occurences des thèmes
    vector<string> theme_temp; // on crée un vector avec tous les thèmes
    ifstream lecture_theme(nom_theme.c_str()); // récupération de l'ensemble des themes des questions
    if(lecture_theme){
        string line;
        while(getline(lecture_theme,line)){
            theme_temp.push_back(line); // on récupère tous les thèmes des cartes
        }
    }
    else{
        cout<<"Erreur lors de l'ouverture du fichier pour la lecture des questions des cartes"<<endl;
    }
    
    for(int i=0;i<liste_themes.size();i++){ // on parcourt tous les thèmes récupérés
        int occurence=1; // on commence à au moins une fois le thème existant
        for(int j=0;j<theme_temp.size();j++){
            if(liste_themes[i]==theme_temp[j]){
                occurence++; // on compte le nombre de fois où l'on rencontre le thème
            }
        }
        nb_theme_temp.push_back(occurence);
    }
    return(nb_theme_temp);
}

void affichage_themes(vector<string> liste_themes,vector<int> occurence_themes){
    for(int i=0;i<liste_themes.size();i++){
        cout<<"Thème : "<<liste_themes[i]<<" ... Nombres de cartes de ce thème : "<<occurence_themes[i]-1<<endl;
    }
}

vector<carte> revision(string nom_theme,vector<string> nom_themes,vector<carte> cartes){
    vector<carte> ensemble_cartes;
    bool existe=false;
    for(int i=0;i<nom_theme.size();i++){
        if(nom_theme==nom_themes[i]){ // on regarde si le thème saisi existe ou non
            existe=true;
        }
    }
    if(existe){
        clear();
        cout<<"Le thème que vous avez choisi existe parmi les cartes existantes"<<endl;
        for(int i=0;i<cartes.size();i++){
            if(cartes[i].get_theme()==nom_theme){
                ensemble_cartes.push_back(cartes[i]); // on récupère l'ensemble des cartes du thème
            }
        }
    }else{
        clear();
        cout<<"Le thème que vous avez choisi n'existe pas parmi les cartes existantes"<<endl;
    }
    return(ensemble_cartes);
}
