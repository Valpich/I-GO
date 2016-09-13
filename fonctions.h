//
//  fonctions.h
//  Mini projet en c
//
//  Created by Valentin Pich' on 20/10/2014.
//  Copyright (c) 2014 ESEO. All rights reserved.
//

#ifndef __Mini_projet_en_c__fonctions__
#define __Mini_projet_en_c__fonctions__
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#define Normal          "\E[0m"
#define PVert 			"\E[0;32;40m"
#define PJaune          "\E[1;33;40m"
#define PBleu 			"\E[0;34;40m"
#define PRouge          "\E[1;31;40m"
#define PViolet 		"\E[0;35;40m"
#define POrange 		"\E[0;33;40m"
#define PRose 			"\E[1;35;40m"
#define PNoir 			"\E[1;37;40m"
#define PBleuClair      "\E[1;34;40m"
#define PVertClair      "\E[1;32;40m"
#define WIDTHCARD 50
#define HEIGHTCARD 100

typedef enum{Vert,Jaune,Bleu,Rouge,Violet,Orange,Rose,Noir,BleuClair,VertClair,Test} Couleur;
typedef enum{Un,Deux}Joueur;
/*! \struct Carte
 * \brief Définition d'une carte
 */
typedef struct{
    int valeur; /*!< la Valeur de la carte. de 1 à 11 */
    Couleur couleur;  /*!< la Couleur de la carte. */
} Carte;

void initpioche(Carte *pioche,int joueurs,Carte *deck);// Cette procédure initialise la pioche
void initrangee(Carte *rangee,int joueurs,Carte *deck);//Cette procédure initialise la rangée
void initjoueur(Carte *joueur,Carte *deck);//Cette procédure initialise la main du joueur
void initdefausse(Carte *defausse,Carte *pioche);//Cette procédure initialise la defausse
void gererdefausse(Carte *def,bool add,Carte a);//Cette procédure gere la defausse d'une carte par le joueur
void gererrangee(Carte *rangee);//Cette procédure gere la pioche dans la rangee
Carte gererpioche(Carte *pioche,int NBJOUEUR);//Cette fonction gere la pioche et renvoie la carte piochée
void choixjoueurdefausse(Carte *joueur,Carte *defausse,int numeroj);//Cette procédure permet au joueur de choisir de quelle carte il veut se defausser
void choixjoueurpioche(Carte *pioche,Carte *defausse,Carte *joueur,Carte *rangee,int NBJOUEUR);//Cette procédure permet au joueur de choisir quelle carte il veut piocher
int gererigo(Carte *joueur,Carte *adversaire,int colorangee,int colorsuiteun,int colorsuitedeux);//Cette procédure permet de gérer un I GO lancé par le joueur
bool valeurcartepresent(Carte *test,Carte a);//Cette fonction retourne si une carte est présente dans un paquet de cartes ou non
void ajoutercarte(Carte *a,Carte *add);//Cette procédure ajoute une carte dans un paquet de cartes
void ordonnersuite(Carte *suite);//Cette procédure ordonne de façon croissante une suite de cartes de valeur différentes
int jouerigo(Carte *pioche,Carte *defausse, Carte *joueur,Carte *adversaire,Carte *rangee,int NBJOUEUR,int numeroj);//Cette fonction gére une phase de jeu d'un joueur, si celui-ci lance I GO elle retourne sa victoire/defaite, sinon elle donne un code permettant au main de poursuivre le jeu

#endif /* defined(__Mini_projet_en_c__fonctions__) */
