//
//  main.c
//  Mini projet en c
//
//  Created by Valentin Pich' on 20/10/2014.
//  Copyright (c) 2014 ESEO. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "fonctions.h"
#include "bibliotheque.h" 
#include "fonctionsgraphiques.h"
#define NBJOUEUR 2
#define DX11 disp,win,gc
#define HEIGHT 700
#define WIDTH 1000
#define WIDTHCARD 50
#define HEIGHTCARD 100

int main(int argc, const char * argv[]) {
	Carte deck[110];
	Carte rangee[8];
	Carte joueur1[14];
	Carte joueur2[14];
	Carte pioche[80];
	Carte defausse[111];
	int score[2];
	int gagnant=0;
	score[0]=0;
	score[1]=0;
	int i,j;
	int test1;
        int test2;
	int firstplayer=1;
        srand((int)time(NULL));
	unsigned long white,black;
	initWindow(WIDTH,HEIGHT,"I GO");
	white=pixelByName("white");
	black=pixelByName("black");
	setWindowBackground(white);  
	setForeground(black);
	XFlush(disp);
	XSelectInput(disp,win,ButtonPressMask|KeyPress);
	XEvent event;
	XNextEvent(disp,&event);
	presentationdujeu();
	while(score[0]!=4&&score[1]!=4){
	debutjeu://Label indiquant le début de jeu avant les initialisations
		for(i=0;i<10;i++){
			for(j=0;j<11;j++){
            			deck[11*i+j].valeur=j+1;
           			 deck[11*i+j].couleur=i;
       			 }
   	 	}
   		initrangee(rangee, NBJOUEUR, deck);
    		initjoueur(joueur1,deck);
    		initjoueur(joueur2,deck);
    		initpioche(pioche,NBJOUEUR,deck);
    		initdefausse(defausse, pioche);
		test1=0;
		test2=0;
		if(firstplayer==1)goto debutj1;//Permet d'allez au tour du joueur 1
		if(firstplayer==2)goto debutj2;//Permet d'allez au tour du joueur 2
		while(test1==0&&test2==0){
		debutj1://Label indiquant le début du tour du joueur 1
			dessinerseriecarte(joueur1,joueur2,defausse,rangee,pioche,WIDTHCARD,HEIGHTCARD,1);
			dessinerchainearactere(1);
			test1=jouerigo(pioche,defausse,joueur1,joueur2,rangee,NBJOUEUR,1);
			if(test1==-1){
				firstplayer=1;
				goto debutjeu;//Permet de retourner en début de jeu si jamais le joueur 1 vide la rangee
			}
			if(test1==1)score[0]+=1;
			if(test1==2)score[1]+=1;
            if(test1==4)score[0]=4;
            if(test1==2)score[1]=0;
			if(test1==1||test2==2)firstplayer=1;
			if(test1==1||test2==1||test1==2||test2==2)continue;
		debutj2://Label indiquant le début du tour du joueur 2
			dessinerseriecarte(joueur1,joueur2,defausse,rangee,pioche,WIDTHCARD,HEIGHTCARD,2);
			dessinerchainearactere(2);
			test2=jouerigo(pioche,defausse,joueur2,joueur1,rangee,NBJOUEUR,2);
			if(test2==-2){
				firstplayer=2;
				goto debutjeu;//Permet de retourner en début de jeu si jamais le joueur 2 vide la rangee
			}
			if(test2==1)score[1]+=1;
			if(test2==2)score[0]+=1;
            if(test2==4)score[1]=4;
            if(test2==2)score[0]=0;
			if(test1==1||test2==2)firstplayer=2;
   		 }
	}
	if(score[0]==4)gagnant=1;
	if(score[1]==4)gagnant=2;
        if(gameover(gagnant)){
		score[0]=0;
		score[1]=0;
		goto debutjeu;//Permet de retourner au début du jeu si la personne a souhaiter recommencer
	}
    	return 0;
}

