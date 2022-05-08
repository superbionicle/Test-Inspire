//
//  lecture ecriture.cpp
//  Inspire
//
//  Created by Arthur on 07/05/2022.
//

#include "lecture ecriture.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "scores.hpp"
#include "carte.hpp"
#include "thème.hpp"

void ecriture(string nom,highscores score){ // on sauvegarde les données dans le .txt
    int* scores=score.get_scores(); // on récupère les scores de notre classe
    string* pseudos=score.get_pseudos(); // on récupère les pseudos de notre classe
    int taille=score.get_taille(); // on récupère le nb de highscores à garder
    
    ofstream txt(nom.c_str()); // on ouvre le fichier en écriture, mode écrasement
    if(txt){ // si l'ouverture s'est bien passée
        for(int i=0;i<taille;i++){ // on copie les valeurs dans le .txt
            txt<<pseudos[i]<<" "<<scores[i]<<endl; // on écrit les couples (pseudo,score) dans le .txt
        }
    }
    else{ // s'il y a eu un problème
        cout<<"Erreur d'ouverture du fichier"<<endl;
    }
    txt.close(); // on ferme le fichier
}

vector<string> lecture_pseudos(string nom){ // on récupère les pseudos du .txt
    vector<string> pseudos_temp; // on crée la variable de retour
    ifstream lecture(nom.c_str()); // on ouvre le fichier en lecture
    if(lecture){ // si l'ouverture s'est bien passée
        string pseudo_user;
        while(lecture>>pseudo_user){ //on récupère les scores
            pseudos_temp.push_back(pseudo_user);
        }
    }
    else{ // s'il y a eu un problème
        cout<<"Erreur d'ouverture du fichier"<<endl;
    }
    lecture.close(); // on ferme le fichier
    return(pseudos_temp);
}

vector<int> lecture_scores(string nom){ // on récupère les scores du .txt
    vector<int> scores_temp; // on crée la variable de retour
    ifstream lecture(nom.c_str()); // on ouvre le fichier en lecture
    if(lecture){ // si l'ouverture s'est bien passée
        int score_user;
        while(lecture>>score_user){ // on récupère les pseudos
            scores_temp.push_back(score_user);
        }
        
    }
    else{ // s'il y a eu un problème
        cout<<"Erreur d'ouverture du fichier"<<endl;
    }
    lecture.close(); // on ferme le fichier
    return(scores_temp);
}

void affichage_contenu(string nom){
    ifstream lecture(nom.c_str()); // on ouvre le fichier en lecture
    if(lecture){ // si l'ouverture s'est bien passée
        string line;
        while(getline(lecture,line)){ // on affiche les lignes
            cout<<line<<endl;
        }
    }
    else{ // s'il y a eu un problème
        cout<<"Erreur d'ouverture du fichier"<<endl;
    }
    cout<<endl;
    lecture.close(); // on ferme le fichier
}

highscores init(string nom){
    ofstream open(nom.c_str()); // on ouvre une premiere fois le fichier pour le créer éventuellement
    open.close(); // on le ferme directement
    vector<string> pseudos=lecture_pseudos(nom); // on récupère les valeurs des pseudos
    vector<int> scores=lecture_scores(nom); // on récupère les valeurs des scores
    int vide=scores.size(); // on récupère la taille des vecteurs (ils ont meme taille)
    if(vide==0){ // si c'est égal à 0, alors le fichier est vide
        //cout<<"Le fichier est vide : remplissage du fichier"<<endl;
        highscores score; // on initialise une classe de scores par défaut (cf le constructeur)
        return(score);
    }
    else{ // sinon, le fichier n'est pas vide et on a récupéré des infos existantes
        //cout<<"Le fichier n'est pas vide"<<endl;
        highscores score(pseudos,scores,scores.size()); // on attribut des valeurs à la classe de scores
        return(score);
    }
}