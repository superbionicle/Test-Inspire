/*
 
 Attentes du client :
 Faire un jeu quizz avec des cartes
 Chaque carte aura :
    - un thème
    - une question
    - 1 réponse correcte et entre 1 et 3 réponses fausses
 Ce qu'il faut faire :
    - permettre de créer un thème pouvant regrouper plusieurs cartes
    - faire une session de révision par thème (sans score en jeu)
    - faire une session de jeu avec tous les thèmes et avec score en jeu
    - permettre de compter les points pour chaque manche gagner, les afficher au fur et à mesure de la partie
 
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
