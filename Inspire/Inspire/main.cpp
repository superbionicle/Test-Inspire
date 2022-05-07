//
//  main.cpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "scores.hpp"
#include "lecture ecriture.hpp"

using namespace std;


int main(){
    string const nom("scores.txt"); // on récupère le nom du fichier .txt
    highscores tab=init(nom);
    ecriture(nom, tab);
    affichage_contenu(nom);
    tab.display_contenu(); // on vérifie la cohérence avec ce qui a été écrit dans le .txt
    
    return(0);
}
