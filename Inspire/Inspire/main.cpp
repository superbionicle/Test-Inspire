//
//  main.cpp
//  Inspire
//
//  Created by Arthur on 04/05/2022.
//

// Importation des libraries
#include <iostream>
#include <fstream>
#include <vector>

// Importation des headers
#include "scores.hpp"
#include "menus.hpp"
#include "carte.hpp"
#include "lecture ecriture.hpp"
#include "fonctions menus.hpp"
#include "fonctions theme.hpp"


using namespace std;



int main(){
    string tampon;
    // Zone initialisation des fichiers
    string const nom_scores("scores.txt"); // on récupère le nom du fichier .txt pour les scores
    string const nom_pseudos("pseudos.txt"); // on récupère le nom du fichier .txt pour les pseudos du highscores
    string const nom_theme("themes_question.txt"),nom_question("questions.txt"),nom_nb("nb_rep.txt"),nom_rep("rep.txt");
    
    int choix_menu=0;
    do{
        highscores tab=init(nom_scores, nom_pseudos); // on init notre tableau des highscores
        // soit on récupère les données qui existe déjà
        // soit on crée un fichier vide et on initialise le tableau des scores
        init_vecteur(nom_theme, nom_question, nom_nb, nom_rep); // on init nos fichiers pour les cartes
        // soit on récupère les données qui existe déjà
        // soit on crée les fichiers vides et on écrira dessus
        vector<carte> liste_cartes=lecture_cartes(nom_theme,nom_question,nom_nb,nom_rep); // on récupère les infos pour récupérer les cartes
        vector<string> themes=recup_themes(nom_theme); // on récupère les différents thèmes
        vector<int> themes_occurences=recup_nb_themes(nom_theme, themes); // on récupère l'occurence des thèmes
        // ces fonctions sont placées ici pour être mise à jour à chaque saisie d'une nouvelle carte ou d'une maj des scores
        //clear();
        
        clear();

        affichage(); // on affiche notre menu
        cout<<"Votre choix : ";
        cin>>choix_menu;
        
        // permet de gérer la mauvaise saisie d'un utilisateur
        if(cin.eof() || cin.bad()){
            cerr<<"Erreur interne"<<endl;
        }
        else if(cin.fail()){
            cerr<<"Mauvaise saisie"<<endl;
            choix_menu=-1; // permet de feinter l'ordi et de faire boucler jusqu'à la bonne saisie
        }
        vider_buffer();
        // fin de la gestion de la mauvaise saisie
        
        getline(cin,tampon); // permet de gérer les pb de saisie avec cin, utilisation d'un tampon pour absorber le "\n"
        switch(choix_menu){
            case 1:{ // On lance une ranked
                if(liste_cartes.size()==0){ // on regarde s'il y a des cartes
                    clear();
                    cout<<"Il n'y a pas de cartes, veuillez en enregistrer ou changer les fichiers .txt"<<endl;
                }
                else{
                    clear();
                    ranked(tab,liste_cartes,nom_pseudos,nom_scores); // on lance une partie scorée
                }
            }
                break;
            case 2:{ // On s'entraine sur les questions
                if(liste_cartes.size()==0){ // on regarde s'il y a des cartes
                    clear();
                    cout<<"Il n'y a pas de cartes, veuillez en enregistrer ou changer les fichiers .txt"<<endl;
                }
                else{
                    clear();
                    training(themes, themes_occurences, liste_cartes); // on lance le mode entrainement selon un thème
                }
            }
                break;
            case 3:{ // On ajoute des cartes
                clear();
                int nb_ajout=0;
                do{
                    cout<<"Combien de cartes voulez vous ajouter ? : ";
                    cin>>nb_ajout;
                    getline(cin,tampon);
                }while(nb_ajout<0);
                ajout_carte(nb_ajout,nom_theme, nom_question, nom_nb, nom_rep); // on ajoute n cartes
            }
                break;
            case 4:{ // On affiche les highscores
                clear();
                tab.display_contenu(); // on affiche les highscores
            }
                break;
            case 0:{ // On quitte le programme
                clear();
                cout<<"Merci et à bientot sur Inspire_Learn_Fast.exe"<<endl;
            }
                break;
            default: // On s'est trompé dans la touche pour naviguer dans le menu
                clear();
                cout<<"Mauvaise entrée, recommencez."<<endl;
            
        }
    }while(choix_menu!=0);
    return(0);
}
