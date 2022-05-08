//
//  carte.hpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//

#ifndef carte_hpp
#define carte_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;


class carte{
    string theme_carte="";
    string question="";
    vector<string> reponses;
public:
    // Constructeur et destructeur
    //carte();
    ~carte(){reponses.clear();};
    
    // Méthodes pour définir les attributs
    void set_theme(string nom_theme){theme_carte=nom_theme;};
    void set_question(string question_a_donner){question=question_a_donner;};
    void set_question();
    void set_reponses();
    void set_reponses(int nb,vector<string> rep);
    
    // Méthodes pour récupérer les attributs
    int get_nb(){return(reponses.size());}
    string get_theme(){return(theme_carte);};
    string get_question(){return(question);};
    vector<string> get_reponses();
    
    // Méthode d'affichage
    void display();
    void display_rep();
};

#endif /* carte_hpp */
