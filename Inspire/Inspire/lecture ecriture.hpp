//
//  lecture ecriture.hpp
//  Inspire
//
//  Created by Arthur on 07/05/2022.
//

#ifndef lecture_ecriture_hpp
#define lecture_ecriture_hpp

#include <iostream>
#include <fstream>
#include <vector>
#include "scores.hpp"

void ecriture(string nom,highscores score);
vector<string> lecture_pseudos(string nom);
vector<int> lecture_score(string nom);
void affichage_contenu(string nom);
highscores init(string nom);

#endif /* lecture_ecriture_hpp */
