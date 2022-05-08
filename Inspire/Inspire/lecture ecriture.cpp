//
//  lecture ecriture.cpp
//  Inspire
//
//  Created by Arthur on 07/05/2022.
//

// Importation des libraries
#include <iostream>
#include <fstream>
#include <vector>

// Importation des headers
#include "lecture ecriture.hpp"
#include "scores.hpp"
#include "carte.hpp"
#include "thème.hpp"

// Fonctions affichages

void affichage_contenu(string nom){
    ifstream lecture(nom.c_str()); // on ouvre le fichier en lecture
    if(lecture){ // si l'ouverture s'est bien passée
        string line;
        while(getline(lecture,line)){ // on affiche les lignes
            cout<<line<<endl;
        }
    }
    else{ // s'il y a eu un problème
        cout<<"Erreur lors de l'ouverture du fichier pour l'affichage du contenu"<<endl;
    }
    cout<<endl;
    lecture.close(); // on ferme le fichier
}







// Fonctions écriture/lecture scores

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
        cout<<"Erreur lors de l'ouverture du fichier pour l'écriture des highscores"<<endl;
    }
    txt.close(); // on ferme le fichier
}

vector<string> lecture_pseudos(string nom){ // on récupère les pseudos du .txt
    vector<string> pseudos_temp; // on crée la variable de retour
    ifstream lecture(nom.c_str()); // on ouvre le fichier en lecture
    if(lecture){ // si l'ouverture s'est bien passée
        cout<<"Ouverture lecture pseudos ok"<<endl;
        string pseudo_user;
        while(lecture>>pseudo_user){ //on récupère les scores
            cout<<"Ajout de "<<pseudo_user<<endl;
            pseudos_temp.push_back(pseudo_user);
        }
    }
    else{ // s'il y a eu un problème
        cout<<"Erreur lors de l'ouverture du fichier pour la lecture des pseudos"<<endl;
    }
    lecture.close(); // on ferme le fichier
    return(pseudos_temp);
}

vector<int> lecture_scores(string nom){ // on récupère les scores du .txt
    vector<int> scores_temp; // on crée la variable de retour
    ifstream lecture(nom.c_str()); // on ouvre le fichier en lecture
    if(lecture){ // si l'ouverture s'est bien passée
        cout<<"Ouverture lecture score ok"<<endl;
        int score_user;
        while(lecture>>score_user){ // on récupère les pseudos
            cout<<"Ajout du score "<<score_user;
            scores_temp.push_back(score_user);
        }
        
    }
    else{ // s'il y a eu un problème
        cout<<"Erreur lors de l'ouverture du fichier pour la lecture des scores"<<endl;
    }
    lecture.close(); // on ferme le fichier
    return(scores_temp);
}

highscores init(string nom){
    ofstream open(nom.c_str()); // on ouvre une premiere fois le fichier pour le créer éventuellement
    if(open){
        cout<<"Présence du fichier confirmée"<<endl;
    }
    else{
        cout<<"Erreur avec le fichier"<<endl;
    }
    open.close(); // on le ferme directement
    vector<string> pseudos=lecture_pseudos(nom); // on récupère les valeurs des pseudos
    for(int i=0;i<pseudos.size();i++){
        cout<<"Pseudo n°"<<i+1<<" : "<<pseudos[i]<<endl;
    }
    vector<int> scores=lecture_scores(nom); // on récupère les valeurs des scores
    for(int i=0;i<scores.size();i++){
        cout<<"Score n°"<<i+1<<" : "<<pseudos[i]<<endl;
    }
    int vide=scores.size(); // on récupère la taille des vecteurs (ils ont meme taille)
    cout<<"scores.size() = "<<vide<<endl;
    if(vide==0){ // si c'est égal à 0, alors le fichier est vide
        cout<<"Le fichier est vide : remplissage du fichier"<<endl;
        highscores score; // on initialise une classe de scores par défaut (cf le constructeur)
        ecriture(nom, score);
        return(score);
    }
    else{ // sinon, le fichier n'est pas vide et on a récupéré des infos existantes
        cout<<"Le fichier n'est pas vide"<<endl;
        highscores score(pseudos,scores,scores.size()); // on attribut des valeurs à la classe de scores
        return(score);
    }
}




















// Fonctions lecture/ecriture cartes

void ecriture(string nom_theme,string nom_question,string nom_nb,string nom_rep,vector<carte> question){
    ofstream txt_theme(nom_theme.c_str(),ios::app); // on écrit en mode append pour ne pas écraser le contenu
    if(txt_theme){ // ecriture des themes des question des cartes
        //cout<<"Ouverture réussie"<<endl;
        for(int i=0;i<question.size();i++){
            txt_theme<<question[i].get_theme()<<endl; // on ajoute au fichier .txt
        }
    }
    else{
        cout<<"Erreur lors de l'ouverture du fichier pour l'écriture des thèmes des cartes"<<endl;
    }
    txt_theme.close(); // on ferme le fichier
    
    
    ofstream txt_questions(nom_question.c_str(),ios::app); // on écrit en mode append pour ne pas écraser le contenu
    if(txt_questions){ // ecriture des questions des cartes
        //cout<<"Ouverture réussie"<<endl;
        for(int i=0;i<question.size();i++){
            txt_questions<<question[i].get_question()<<endl; // on ajoute au fichier .txt
        }
    }
    else{
        cout<<"Erreur lors de l'ouverture du fichier pour l'écriture des questions des cartes"<<endl;
    }
    txt_questions.close(); // on ferme le fichier
    
    
    ofstream txt_nb(nom_nb.c_str(),ios::app); // on écrit en mode append pour ne pas écraser le contenu
    if(txt_nb){ // ecriture des nb de reponses des questions pour retrouver les reponses après
        //cout<<"Ouverture réussie"<<endl;
        for(int i=0;i<question.size();i++){
            txt_nb<<question[i].get_nb()<<endl; // on ajoute au fichier .txt
        }
    }
    else{
        cout<<"Erreur lors de l'ouverture du fichier pour l'écriture du nb de réponses aux questions des cartes"<<endl;
    }
    txt_nb.close(); // on ferme le fichier
    
    
    ofstream txt_rep(nom_rep.c_str(),ios::app); // on écrit en mode append pour ne pas écraser le contenu
    if(txt_rep){ // ecriture des nb de reponses des questions pour retrouver les reponses après
        //cout<<"Ouverture réussie"<<endl;
        for(int i=0;i<question.size();i++){
            vector<string> temp=question[i].get_reponses();
            for(int i=0;i<temp.size();i++){
                txt_rep<<temp[i]<<endl; // on ajoute au fichier .txts
            }
            //txt_rep<<endl;
            //txt_rep<<question[i].get_reponses()<<endl;
        }
    }
    else{
        cout<<"Erreur lors de l'ouverture du fichier pour l'écriture des réponses des questions des cartes"<<endl;
    }
    txt_rep.close(); // on ferme le fichier
    
}

vector<carte> lecture_cartes(string nom_theme,string nom_question,string nom_nb,string nom_rep){
    vector<carte> cartes_temp;
    
    vector<string> nb_theme;
    vector<string> questions;
    vector<int> nb_rep;
    vector<string> rep;
    
    ifstream lecture_theme(nom_theme.c_str()); // reconstruction de l'ensemble des themes des questions
    if(lecture_theme){
        string line;
        while(getline(lecture_theme,line)){
            nb_theme.push_back(line);
        }
    }
    else{
        cout<<"Erreur lors de l'ouverture du fichier pour la lecture des questions des cartes"<<endl;
    }
    
    ifstream lecture_question(nom_question.c_str()); // reconstruction de l'ensemble des questions
    if(lecture_question){
        string line;
        while(getline(lecture_question,line)){
            questions.push_back(line);
        }
    }
    else{
        cout<<"Erreur lors de l'ouverture du fichier pour la lecture des questions des cartes"<<endl;
    }
    
    ifstream lecture_nb(nom_nb.c_str()); // recontruction de l'ensemble des nb de rep
    if(lecture_nb){
        int line;
        while(lecture_nb>>line){
            nb_rep.push_back(line);
        }
    }
    else{
        cout<<"Erreur lors de l'ouverture du fichier pour la lecture du nb de réponses aux questions des cartes"<<endl;
    }
    
    ifstream lecture_rep(nom_rep.c_str()); // reconstructuon de l'ensemble des réponses
    if(lecture_rep){
        string line;
        while(getline(lecture_rep,line)){
            rep.push_back(line);
        }
    }
    else{
        cout<<"Erreur lors de l'ouverture du fichier pour la lecture des réponses des questions des cartes"<<endl;
    }
    
    int cumul_rep=0;
    for(int i=0;i<nb_theme.size();i++){
        //cout<<"Nombre de réponses : "<<nb_rep[i]<<endl;
        carte carte_temp;
        //cumul_rep+=nb_rep[i];
        carte_temp.set_theme(nb_theme[i]);
        carte_temp.set_question(questions[i]);
        vector<string> rep_temp;
        for(int j=0;j<nb_rep[i];j++){
            //cout<<"Entrée"<<endl;
            rep_temp.push_back(rep[i+j+cumul_rep]);
            //cout<<rep[i+j+cumul_rep]<<endl;
        }
        cumul_rep+=nb_rep[i]-1;
        carte_temp.set_reponses(nb_rep[i],rep_temp);
        cartes_temp.push_back(carte_temp);
    }
    
    lecture_theme.close(); // fermeture du fichier
    lecture_question.close(); // fermeture du fichier
    lecture_nb.close(); // fermeture du fichier
    lecture_rep.close(); // fermeture du fichier
    // reconstruire les classes mineures pour refaire la classe principale
    return(cartes_temp);
}
