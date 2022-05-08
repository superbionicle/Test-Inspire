//
//  thème.hpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//

#ifndef the_me_hpp
#define the_me_hpp


// Importation des libraries
#include <stdio.h>
#include <vector>

// Importation des headers
#include "carte.hpp"


class theme{
    vector<carte> questions;
public:
    theme();
    ~theme();
    void ajout_question(carte question);
    void ajout_question();
    void modifier_question();
    void retirer_question();
    void lancer_revision();
    carte get_question();
};

#endif /* the_me_hpp */
