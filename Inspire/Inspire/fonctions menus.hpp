//
//  fonctions menus.hpp
//  Inspire
//
//  Created by Arthur on 08/05/2022.
//

#ifndef fonctions_menus_hpp
#define fonctions_menus_hpp


// Importation des libraries
#include <iostream>
#include <vector>

// Importation des headers
#include "scores.hpp"
#include "carte.hpp"

using namespace std;

void clear();
void ajout_carte(int nb_ajout,string nom_theme,string nom_question,string nom_nb,string nom_rep);
void training(vector<string> themes,vector<int> themes_occurences,vector<carte> liste_cartes);
void ranked(highscores tab,vector<carte> liste_cartes,string nom_pseudos,string nom_scores);
void init_vecteur(string nom_theme,string nom_question,string nom_nb,string nom_rep);
void vider_buffer();

#endif /* fonctions_menus_hpp */
