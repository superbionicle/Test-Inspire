//
//  lecture ecriture.hpp
//  Inspire
//
//  Created by Arthur on 07/05/2022.
//

#ifndef lecture_ecriture_hpp
#define lecture_ecriture_hpp

// Importation des libraries
#include <iostream>
#include <fstream>
#include <vector>

// Importation des headers
#include "scores.hpp"
#include "carte.hpp"
#include "thème.hpp"

// Fonctions affichage
void affichage_contenu(string nom);

//Fonctions lecture/ecriture des scores
void ecriture(string nom,highscores score);
vector<string> lecture_pseudos(string nom);
vector<int> lecture_score(string nom);
highscores init(string nom);

// Fonctions lecture/ecriture des cartes
void ecriture(string nom_theme,string nom_question,string nom_nb,string nom_rep,vector<carte> question);
vector<carte> lecture_cartes(string nom_theme,string nom_question,string nom_nb,string nom_rep);


#endif /* lecture_ecriture_hpp */
