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

using namespace std;

void affichage(){
    cout<<"1. Jouer une partie scorée (tout thème confondu)"<<endl;
    cout<<"2. Faire une partie de révision selon un thème"<<endl;
    cout<<"3. Ajouter/Retirer un thème"<<endl;
    cout<<"4. Ajouter/Modifier/Retirer une carte"<<endl;
    cout<<"5. Voir les high-scores"<<endl;
    cout<<"0. Quitter (vous pouvez aussi appuyer sur Echap pour quitter"<<endl;
}

int main(){
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
                cout<<"WIP Training"<<endl;
            }
                break;
            case 3:{
                cout<<"WIP Ajout/Retrait thème"<<endl;
            }
            case 4:{
                cout<<"WIP Ajout/Modif/Retrait cartes"<<endl;
            }
                break;
            case 5:{
                cout<<"WIP High-scores"<<endl;
            }
                break;
            case 0:{
                cout<<"Merci et à bientot avec Learn Fast.exe"<<endl;
            }
                break;
            default:
                cout<<"Mauvaise entrée"<<endl;
            
        }
    }while(choix_menu!=0);
    return(0);
}
