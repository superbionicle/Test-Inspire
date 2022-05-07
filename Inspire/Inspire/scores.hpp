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
    int taille=10;
    vector<string> pseudos;
    vector<int> scores;
public:
    highscores();
    ~highscores();
    void insertion(string pseudo,int score);
    void changer_taille(int new_taille){taille=new_taille;}
    void fin_partie(string pseudo,int score);
    vector<string> get_pseudos(){return(pseudos);}
    vector<int> get_scores(){return(scores);}
};

#endif /* scores_hpp */
