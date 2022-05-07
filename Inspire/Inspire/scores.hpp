//
//  scores.hpp
//  Inspire
//
//  Created by Arthur on 07/05/2022.
//

#ifndef scores_hpp
#define scores_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class highscores{
    int taille;
    vector<string> pseudos;
    vector<int> scores;
public:
    highscores(vector<string> users,vector<int>scores_users,int taille_user=10);
    highscores(int taille_user=10);
    ~highscores();
    void display_contenu();
    void insertion(string pseudo,int score);
    void changer_taille(int new_taille){taille=new_taille;}
    void fin_partie(string pseudo,int score);
    string* get_pseudos();
    int* get_scores();
};

#endif /* scores_hpp */
