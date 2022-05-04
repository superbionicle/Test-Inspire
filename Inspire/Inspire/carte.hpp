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
    string theme_carte;
    string question;
    bool vrai_faux=true;
    vector<string> reponses={"Vrai","Faux"};
public:
    carte();
    ~carte();
    void set_theme(string nom_theme){theme_carte=nom_theme;};
    void set_question(string question_a_donner){question=question_a_donner;};
    void set_question();
    void set_reponses();
    bool lancer_question();
};

#endif /* carte_hpp */
