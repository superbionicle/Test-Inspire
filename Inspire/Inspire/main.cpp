//
//  main.cpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//

#include <iostream>

/*
 
Attentes du client :
 Faire un jeu quizz avec des cartes
 Chaque carte aura :
    - un thème
    - une question
    - 1 réponse correcte et entre 1 et 3 réponses fausses
 Ce qu'il faut faire :
    - créer un programme controlable via le terminal
        V1 : controlable avec l'écriture
        V2 : controlable avec le clavier (flèches directionnelles et echap en plus pour quitter)
    - permettre de créer un thème pouvant regrouper plusieurs cartes
    - faire une session de révision par thème (sans score en jeu)
    - faire une session de jeu avec tous les thèmes et avec score en jeu
    - permettre de rajouter des cartes d'apprentissage dans un fichier
        écriture et lecture d'un fichier
        format pour le faire ?
    - permettre de compter les points pour chaque manche gagner, les afficher au fur et à mesure de la partie
    - faire un menu des high scores
        écriture et lecture d'un fichier des scores
        format : txt ? (classement ... nom ...... score)
 
 Conception de la structure :
 Menu :
    1. Jouer une partie (tout thème confondu)
    2. Lancer une partie de révision
        2.1. Choisir un thème
        2.2 Retour au menu précédent
    3. Ajouter, modifier ou retirer une carte
        3.1. Ajouter une carte au deck
            Choisir le thèe parmis ceux existant
            Entrer la question
            Est-ce une question vrai/faux ?
            Si non, alors :
                Entrer la bonne réponse
                Choisir le nombre de mauvaises réponses
                Entrer les mauvaises réponses
            Ajouter une nouvelle carte ? oui/non
            Si oui
                On boucle
            Si non
                Retour au menu précédent
            Bouton "Annuler" toujours précédent pendant l'ajout
        3.2. Modifier une carte existante
        3.3. Supprimer une carte existante
        3.4. Retour au menu précédent
    4. Voir les high scores
        4.1. (Affichage des 10 meilleurs)
        4.2. Retour au menu précédent
    5. Créer un nouveau thème pour le deck
    0. Quitter (Echap pour quitter)
 
*/

int main(){
    return 0;
}
