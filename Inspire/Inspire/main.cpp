//
//  main.cpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//

#include <iostream>
#include <vector>
#include "scores.hpp"

using namespace std;


int main(){
    
    string const nom("/scores.txt");
    ofstream score(nom.c_str());
    score.close();
    
    highscores tab;
    tab.fin_partie("Arthur", 100);
    return(0);
}
