//
//  fonctions theme.hpp
//  Inspire
//
//  Created by Arthur on 08/05/2022.
//

#ifndef fonctions_theme_hpp
#define fonctions_theme_hpp

// Importation des libraries
#include <iostream>
#include <vector>

// Importation des headers
#include "carte.hpp"


using namespace std;

vector<string> recup_themes(string nom_theme);
vector<int> recup_nb_themes(string nom_theme,vector<string> liste_themes);
void affichage_themes(vector<string> liste_themes,vector<int> occurence_themes);
vector<carte> revision(string nom_theme,vector<string> nom_themes,vector<carte> cartes);


#endif /* fonctions_theme_hpp */
