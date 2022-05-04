//
//  main.cpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//


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
 
 Remarque : trouver le moyen de clear la console terminal pour avoir un affichage propre à chaque fois qu'on se balade dans les menus
 Bonus : essayer de mettre en place un chrono en arrière plan et donner le temps à la fin d'une session de jeu
 
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
 
 Etapes :
    1. Faire le menu
    2. Créer les classes "Carte" et "Thème"
    3. Faire les options du menu pour ajouter cartes et thèmes
    4. Trouver la manière de faire de l'écriture et de la lecture de fichier pour enregistrer des données
 
*/

#include <iostream>
#include <vector>
#include "carte.hpp"
#include "thème.hpp"
#include "menus.hpp"

using namespace std;


int main(){
    vector<carte> liste_cartes;
    vector<theme> liste_theme;
    int choix_menu=0;
    do{
        affichage();
        cout<<"Votre choix : ";
        cin>>choix_menu;
        switch(choix_menu){
            case 1:{
                cout<<"WIP Ranked"<<endl;
            }
                break;
            case 2:{
                int choix_2=menu_training();
                cout<<"WIP Training"<<endl;
            }
                break;
            case 3:{
                int choix_3=menu_theme();
                cout<<"WIP Ajout/Retrait thème"<<endl;
            }
                break;
            case 4:{
                int choix_4=menu_carte();
                switch (choix_4) {
                    case 1:{
                        carte carte_temp;
                        cout<<"Saisir le thème de la carte : ";
                        string theme;
                        cin>>theme;
                        carte_temp.set_theme(theme);
                        carte_temp.set_question();
                        carte_temp.set_reponses();
                        liste_cartes.push_back(carte_temp);
                        
                    }
                        break;
                        
                    default:
                        break;
                }
                cout<<"WIP Ajout/Modif/Retrait cartes"<<endl;
            }
                break;
            case 5:{
                cout<<"WIP High-scores"<<endl;
            }
                break;
            case 0:{
                cout<<"Merci et à bientot sur Inspire_Learn_Fast.exe"<<endl;
            }
                break;
            default:
                cout<<"Mauvaise entrée, recommence batard"<<endl;
            
        }
    }while(choix_menu!=0);
    return(0);
}
