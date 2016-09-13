//
//  fonctionsgraphiques.c
//  Mini projet en c
//
//  Created by Valentin Pich' on 20/10/2014.
//  Copyright (c) 2014 ESEO. All rights reserved.
//

#ifndef FONCTIONSGRAPHIQUES_H
#define FONCTIONSGRAPHIQUES_H
#include <string.h>
#define WIDTHCARD 50
#define HEIGHTCARD 100
#define HEIGHT 700
#define WIDTH 1000
#define DX11 disp,win,gc
/*
Cette procédure permet de nettoyer l'écran d'affichage
*/
void nettoyer(void){ 
	XClearArea(disp,win,0,0,WIDTH,HEIGHT,0);
	XFlush(disp);
}
/*
Cette procédure permet de modifier la couleur à afficher
*/
void SetCardColor(Carte a){
	switch(a.couleur){
		case 0:
		XSetForeground(disp,gc,0x00A611);
		break;
		case 1:
		XSetForeground(disp,gc,0xE9DC24);
		break;
		case 2:
		XSetForeground(disp,gc,0x2424E9);
		break;
		case 3:
		XSetForeground(disp,gc,0xEC0000);
		break;
		case 4:
		XSetForeground(disp,gc,0x7E00EC);
		break;
		case 5:
		XSetForeground(disp,gc,0xEC8600);
		break;
		case 6:
		XSetForeground(disp,gc,0xEC00C5);
		break;
		case 7:
		XSetForeground(disp,gc,0xEEEEEE);
		break;
		case 8:
		XSetForeground(disp,gc,0x23DCC4);
		break;
		case 9:
		XSetForeground(disp,gc,0x16DF74);
		break;
		case 10:
		XSetForeground(disp,gc,0x000000);
		break;
		default:
		XSetForeground(disp,gc,0xFFFFFF);
		break;
	}

}
/*
Cette procédure permet de dessiner les numeros de cartes, si le numero est invalide, le programme s'arrete
*/
void DrawCardString(Carte a,int x,int y){
	switch(a.valeur){
		case 1:
		XSetForeground(disp,gc,0x000000);
		XDrawString(DX11,x,y,"01",2);
		break;
		case 2:
		XSetForeground(disp,gc,0x000000);
		XDrawString(DX11,x,y,"02",2);
		break;
		case 3:
		XSetForeground(disp,gc,0x000000);
		XDrawString(DX11,x,y,"03",2);
		break;
		case 4:
		XSetForeground(disp,gc,0x000000);
		XDrawString(DX11,x,y,"04",2);
		break;
		case 5:
		XSetForeground(disp,gc,0x000000);
		XDrawString(DX11,x,y,"05",2);
		break;
		case 6:
		XSetForeground(disp,gc,0x000000);
		XDrawString(DX11,x,y,"06",2);
		break;
		case 7:
		XSetForeground(disp,gc,0x000000);
		XDrawString(DX11,x,y,"07",2);
		break;
		case 8:
		XSetForeground(disp,gc,0x000000);
		XDrawString(DX11,x,y,"08",2);
		break;
		case 9:
		XSetForeground(disp,gc,0x000000);
		XDrawString(DX11,x,y,"09",2);
		break;
		case 10:
		XSetForeground(disp,gc,0x000000);
		XDrawString(DX11,x,y,"10",2);
		break;
		case 11:
		XSetForeground(disp,gc,0x000000);
		XDrawString(DX11,x,y,"11",2);
		break;
		default:
		puts("Numero de carte errone, arret du programme");
		printf("%d",a.valeur);
		puts("");
		exit(EXIT_FAILURE);
		break;
	}
}
/*
Cette procédure permet l'affichage d'un cercle
*/
void affichercercle(Carte a,int x,int y){
	XSetForeground(disp,gc,0xBBBBBB);
	usleep(500);
	XFillArc(DX11,x,y,30,30,0,360*64);
	}
/*
Cette procédure permet l'afficahge d'un rectangle
*/
void afficherrectangle(Carte a,int x,int y,int z,int w,int h){
	SetCardColor(a);
	usleep(500);
	XFillRectangle(DX11,x,y,w,h);
}
/*
Cette procédure permet de dessiner une carte sur l'ecran
*/
void dessinercarte(Carte a,int x, int y,int z,int w,int h){
	Carte b;
	b.couleur=11;
	Carte c;
	c.couleur=10;
	if(z){
		afficherrectangle(a,x,y,z,w,h);
		afficherrectangle(b,x+0.9*WIDTHCARD-w/5.5-1,y+0.9*HEIGHTCARD-3,z,w/3.5,h/8.5);
		afficherrectangle(b,x+2,y+2,z,w/3.5,h/8.5);
		DrawCardString(a,x+3,y+12);
		DrawCardString(a,x+36,y+97);
		XFlush(disp);
	}else{
		afficherrectangle(c,x,y,z,w,h);
		affichercercle(b,x+10,y+30);
		XFlush(disp);
	}
}
/*
Cette procédure permet de dessiner les series de cartes à l'écran
*/
void dessinerseriecarte(Carte *joueur1,Carte *joueur2,Carte *defausse,Carte *rangee,Carte *pioche,int w,int h,Joueur u){
	int i=0;
	nettoyer();
	if(u==1){
		for(i=0;(joueur1+i)->valeur!=-1;i++){
			dessinercarte(joueur1[i],150+60*i,50,1,w,h);
			XSetForeground(disp,gc,0x000000);		
		}
		for(i=0;(joueur2+i)->valeur!=-1;i++){
			dessinercarte(joueur2[i],150+60*i,550,0,w,h);
			XSetForeground(disp,gc,0x000000);
		}
	}
	if(u==2){
		for(i=0;(joueur1+i)->valeur!=-1;i++){
			dessinercarte(joueur1[i],150+60*i,550,1,w,h);
			XSetForeground(disp,gc,0x000000);
		}
		for(i=0;(joueur2+i)->valeur!=-1;i++){
			dessinercarte(joueur2[i],150+60*i,50,0,w,h);
			XSetForeground(disp,gc,0x000000);		
		}
	}
	for(i=0;(rangee+i)->valeur!=-1;i++){
			dessinercarte(rangee[i],150+60*i,350,1,w,h);
			XSetForeground(disp,gc,0x000000);
			if((rangee+i+1)->valeur!=-1)XDrawString(DX11,200+60*i,400,"->",2);
	}
	for(i=0;(defausse+i)->valeur!=-1;i++){
			dessinercarte(defausse[i],150+60*i,200,1,w,h);
			XSetForeground(disp,gc,0x000000);
	}
	for(i=0;i<1;i++){
			dessinercarte(pioche[i],350+60*i,200,0,w,h);
			XSetForeground(disp,gc,0x000000);
		}
}
/*
Cette procédure permet de dessiner les chaines de caractères du jeu en cours à l'écran
*/
void dessinerchainearactere(int joueur){
	XSetForeground(disp,gc,0x000000);
	char ch0[]={"Main du joueur 1 : "};
	char ch1[]={"Pioche : "};
	char ch2[]={"Defausse : "};
	char ch3[]={"Rangee : "};
	char ch4[]={"Main du joueur 2 : "};
	char ch5[50];
	sprintf(ch5,"Le tour est actuellement au joueur numero %d",joueur);
	XDrawString(DX11,20,100,ch0,strlen(ch0));
	XDrawString(DX11,270,250,ch1,strlen(ch1));
	XDrawString(DX11,20,250,ch2,strlen(ch2));
	XDrawString(DX11,20,400,ch3,strlen(ch3));
	XDrawString(DX11,20,600,ch4,strlen(ch4));
	XDrawString(DX11,350,30,ch5,strlen(ch5));
	XFlush(disp);
}
/*
Cette procédure permet d'afficher l'écran de demarrage
*/
void presentationdujeu(void){
    nettoyer();
    static XEvent event;
    char presentation0[]={"Bonjour et bienvenue dans ce jeu de I GO"};
    char presentation1[]={"Vous allez jouer en un contre un, le premier a gagner 4 manche est le gagnant"};
    char presentation2[]={"Vous devrez succesivement, piocher une carte puis se defausse d'une carte "};
    char presentation3[]={"Vous aurez egalement la possibilitee de faire I GO a la fin de chaque tour"};
    char presentation4[]={"Le joueur avec le moins de penalite a la fin du I GO gagne la manche"};
    char presentation5[]={"Pour plus de details concernant la procedure de I GO consulter internet"};
    char presentation6[]={"Pour jouer, vous devez suivre les instructions a l'ecran de jeu"};
    char presentation7[]={"Celui-ci est prevu pour recevoir directement vos clics!"};
    char presentation8[]={"Pour continuer, cliquez n'importe ou ! Que le meilleur gagne !"};
    XSetForeground(disp,gc,0xFFAA66);
    XFillRectangle(DX11,0,0,WIDTH,HEIGHT);
    XSetForeground(disp,gc,0x000000);
    XPoint clic={0,0};
    while(clic.x==0&&clic.y==0){
        XDrawString(DX11,10*WIDTH/27,1*HEIGHT/18.,presentation0,strlen(presentation0));
        XDrawString(DX11,7.*WIDTH/27,3*HEIGHT/18.,presentation1,strlen(presentation1));
        XDrawString(DX11,7.25*WIDTH/27,5*HEIGHT/18.,presentation2,strlen(presentation2));
        XDrawString(DX11,7.2*WIDTH/27,7*HEIGHT/18.,presentation3,strlen(presentation3));
        XDrawString(DX11,7.65*WIDTH/27,9*HEIGHT/18.,presentation4,strlen(presentation4));
        XDrawString(DX11,7.25*WIDTH/27,11*HEIGHT/18.,presentation5,strlen(presentation5));
        XDrawString(DX11,7.85*WIDTH/27,13*HEIGHT/18.,presentation6,strlen(presentation6));
        XDrawString(DX11,8.25*WIDTH/27,15*HEIGHT/18.,presentation7,strlen(presentation7));
        XDrawString(DX11,7.75*WIDTH/27,17*HEIGHT/18.,presentation8,strlen(presentation8));
        XFlush(disp);
        XCheckWindowEvent(disp,win,ButtonPressMask,&event);
        clic.x=event.xbutton.x;
        clic.y=event.xbutton.y;
        usleep(100000);
    }
    nettoyer();
}
/*
Cette fonction permet au joueur de choisir quelle carte piocher et retourne le numero de la carte à piocher
*/
int choixpioche(void){
	int attentechoix=1;
	XPoint clic={0,0};
	XEvent event;
	int test;
	char ch0[]={"Choisir dans quel paquet piocher la carte, pour cela cliquer sur la premiere carte du paquet"};
	XSetForeground(disp,gc,0x000000);
  	XDrawString(DX11,420,240,ch0,strlen(ch0));
	while(attentechoix){
		if((clic.y>=350)&&(clic.y<450)){
			if ((clic.x>=150)&&(clic.x<=200)){
				attentechoix=0;
				test=1;
			}else{
				XCheckWindowEvent(disp,win,ButtonPressMask,&event);
				clic.x=event.xbutton.x;
				clic.y=event.xbutton.y;
			}
		}else{
			XCheckWindowEvent(disp,win,ButtonPressMask,&event);
			clic.x=event.xbutton.x;
			clic.y=event.xbutton.y;
		}
		if((clic.y>=200)&&(clic.y<300)){
			if ((clic.x>=150)&&(clic.x<=200)){
				attentechoix=0;
				test=2;
			}else{
				XCheckWindowEvent(disp,win,ButtonPressMask,&event);
				clic.x=event.xbutton.x;
				clic.y=event.xbutton.y;
			}
		}else{
			XCheckWindowEvent(disp,win,ButtonPressMask,&event);
			clic.x=event.xbutton.x;
			clic.y=event.xbutton.y;
		}
		if((clic.y>=200)&&(clic.y<300)){
			if ((clic.x>=350)&&(clic.x<=400)){
				attentechoix=0;
				test=3;
			}else{
				XCheckWindowEvent(disp,win,ButtonPressMask,&event);
				clic.x=event.xbutton.x;
				clic.y=event.xbutton.y;
			}
		}else{
			XCheckWindowEvent(disp,win,ButtonPressMask,&event);
			clic.x=event.xbutton.x;
			clic.y=event.xbutton.y;
		}
	}
	return test;
}
/*
Cette fonction permet au joueur de choisir quel carte il veut supprimer de son jeu et retourne la position de celle-ci
*/
int choixdefausse(int joueur,bool def){
	int attentechoix=1;
	XPoint clic={0,0};
	XEvent event;
	event.xbutton.x=clic.x;
	event.xbutton.y=clic.y;
	int test=0;
	char ch0[]={"Choisir quel carte defausser en cliquant dessus !"};
	XSetForeground(disp,gc,0x000000);
  	if(def==1)XDrawString(DX11,450,240,ch0,strlen(ch0));
	while(attentechoix){
		if((clic.y>=(50+(joueur-1)*500))&&(clic.y<(150+(joueur-1)*500))){
			if ((clic.x>=150)&&(clic.x<=200)){
				attentechoix=0;
				test=1;
			}
			if ((clic.x>=210)&&(clic.x<=260)){
				attentechoix=0;
				test=2;
			}
			if ((clic.x>=270)&&(clic.x<=320)){
				attentechoix=0;
				test=3;
			}
			if ((clic.x>=330)&&(clic.x<=380)){
				attentechoix=0;
				test=4;
			}
			if ((clic.x>=390)&&(clic.x<=440)){
				attentechoix=0;
				test=5;
			}
			if ((clic.x>=450)&&(clic.x<=500)){
				attentechoix=0;
				test=6;
			}
			if ((clic.x>=510)&&(clic.x<=560)){
				attentechoix=0;
				test=7;
			}
			if ((clic.x>=570)&&(clic.x<=620)){
				attentechoix=0;
				test=8;
			}
			if ((clic.x>=630)&&(clic.x<=680)){
				attentechoix=0;
				test=9;
			}
			if ((clic.x>=690)&&(clic.x<=740)){
				attentechoix=0;
				test=10;
			}
			if ((clic.x>=750)&&(clic.x<=800)){
				attentechoix=0;
				test=11;
			}
			if ((clic.x>=810)&&(clic.x<=860)){
				attentechoix=0;
				test=12;
			}
			if(test<1||test>13){
				XCheckWindowEvent(disp,win,ButtonPressMask,&event);
				clic.x=event.xbutton.x;
				clic.y=event.xbutton.y;
			}
		}else{
				XCheckWindowEvent(disp,win,ButtonPressMask,&event);
				clic.x=event.xbutton.x;
				clic.y=event.xbutton.y;
		}
	}
	return test;
}
/*
Cette fonction propose au joueur de faire I GO et retourne si oui ou non il lance un I GO
*/
int choixigo(void){
	XSetForeground(disp,gc,0x00CC00);
	XFillRectangle(DX11,560,200,100,100);
	XSetForeground(disp,gc,0xCC0000);
	XFillRectangle(DX11,670,200,100,100);
	XSetForeground(disp,gc,0x000000);
	char ch0[]={"Voulez-vous faire"};
	char ch1[]={"    un I GO ?!   "};
	char ch2[]={"Oui !"};
	char ch3[]={"Non"};
  	XDrawString(DX11,450,240,ch0,strlen(ch0));
  	XDrawString(DX11,450,270,ch1,strlen(ch1));
  	XDrawString(DX11,600,250,ch2,strlen(ch2));
  	XDrawString(DX11,710,250,ch3,strlen(ch3));
	XFlush(disp);
	int attentechoix=1;
	XPoint clic={0,0};
	XEvent event;
	event.xbutton.x=clic.x;
	event.xbutton.y=clic.y;
	int test=-1;
	while(attentechoix){
		if((clic.y>=200)&&(clic.y<300)){
			if ((clic.x>=560)&&(clic.x<=660)){
				attentechoix=0;
				test=1;
			}
			if ((clic.x>=670)&&(clic.x<=770)){
				attentechoix=0;
				test=0;
			}
			if(test<0||test>2){
				XCheckWindowEvent(disp,win,ButtonPressMask,&event);
				clic.x=event.xbutton.x;
				clic.y=event.xbutton.y;
			}
		}else{
				XCheckWindowEvent(disp,win,ButtonPressMask,&event);
				clic.x=event.xbutton.x;
				clic.y=event.xbutton.y;
		}
	}
	return test;
}
/*
Cette procédure permet l'affichage en cas où la pioche est vidé par le joueur
*/
void piochevide(void){
	XSetForeground(disp,gc,0x000000);
	char ch0[]={"Vous avez vide la pioche, vous lancer automatique un I GO ! Bonne chance !"};
  	XDrawString(DX11,450,240,ch0,strlen(ch0));
	XFlush(disp);
}
/*
Cette procédure affiche l'écran de selection de la première etape de l'I GO
*/
void firstepigo(void){
	XSetForeground(disp,gc,0x000000);
 	char ch0[]={"          Indiquer la position de la premiere carte pour creer la suite de 1 a 12           "};
	XDrawString(DX11,450,240,ch0,strlen(ch0));
	char ch1[]={"Vous ne devez pas utiliser les cartes de meme couleur que la premiere carte de la rangee"};
	XDrawString(DX11,450,260,ch1,strlen(ch1));
	XFlush(disp);
}
/*
Cette procédure affiche l'écran de selection de la seconde etape de l'I GO
*/
void secondstepigo(void){
	XSetForeground(disp,gc,0x000000);
  	char ch0[]={"          Indiquer la position de la deuxieme carte pour creer la suite de 1 a 12           "};
	XDrawString(DX11,450,240,ch0,strlen(ch0));
	char ch1[]={"Vous ne devez pas utiliser les cartes de meme couleur que la premiere carte de la rangee"};
	XDrawString(DX11,450,260,ch1,strlen(ch1));
	char ch2[]={"                     Elle peut etre identique a la carte precedente                     "};
	XDrawString(DX11,450,280,ch2,strlen(ch2));
	XFlush(disp);
}
/*
Cette procédure permet d'afficher le plateau de jeu après réalisation d'un I GO
*/
void dessinerigo(Carte *joueur1,Carte *joueur2,Carte *rangee,Carte *elimsuite,int w,int h,int score){
	nettoyer();
	XSetForeground(disp,gc,0x000000);
	char ch0[]={"Restant joueur 1 : "};
	char ch1[]={"Elimine par la suite : "};
	char ch2[]={"Elimine par la rangee :"};
	char ch3[]={"Restant joueur 2 : "};
	char ch4[50];
	sprintf(ch4,"Le joueur qui gagne la manche est le joueur %d",score);
	XDrawString(DX11,10,100,ch0,strlen(ch0));
	XDrawString(DX11,10,250,ch1,strlen(ch1));
	XDrawString(DX11,10,400,ch2,strlen(ch2));
	XDrawString(DX11,10,600,ch3,strlen(ch3));
	XDrawString(DX11,350,30,ch4,strlen(ch4));
	XFlush(disp);
	int i=0;
	for(i=0;(joueur1+i)->valeur!=-1;i++){
		dessinercarte(joueur1[i],150+60*i,50,1,w,h);
		XSetForeground(disp,gc,0x000000);		
	}
	for(i=0;(joueur2+i)->valeur!=-1;i++){
		dessinercarte(joueur2[i],150+60*i,550,1,w,h);
		XSetForeground(disp,gc,0x000000);
	}
	for(i=0;(rangee+i)->valeur!=-1;i++){
		dessinercarte(rangee[i],150+60*i,350,1,w,h);
		XSetForeground(disp,gc,0x000000);
	}
	for(i=0;(elimsuite+i)->valeur!=-1;i++){
		dessinercarte(elimsuite[i],150+60*i,200,1,w,h);
		XSetForeground(disp,gc,0x000000);
	}
}
/*
Cette fonction affiche l'écran de fin de jeu et retourne si la personne veut ou non continuer
*/
int gameover(int gagnant){
	nettoyer();
	XSelectInput(disp,win,ButtonPressMask); 
	XEvent event;
	char ch0[100];
	sprintf(ch0,"Le gagnant de cette partie est le joueur %d ",gagnant);
	XSetForeground(disp,gc,0xFFAA66);
	XFillRectangle(DX11,0,0,WIDTH,HEIGHT);
	XSetForeground(disp,gc,0x66AAFF);
	XFillRectangle(DX11,2.*WIDTH/8,HEIGHT/2,WIDTH/8,HEIGHT/8);
	XSetForeground(disp,gc,0xAA66FF);
	XFillRectangle(DX11,5.*WIDTH/8,HEIGHT/2,WIDTH/8,HEIGHT/8);
	XSetForeground(disp,gc,0x000000);
	XDrawString(DX11,2.35*WIDTH/6,1.5*HEIGHT/6,ch0,strlen(ch0));
	char ch1[]={"Recommencer"};
	XDrawString(DX11,1.55*WIDTH/6,3.4*HEIGHT/6,ch1,strlen(ch1));
	char ch2[]={"Abandonner"};
	XDrawString(DX11,3.85*WIDTH/6,3.4*HEIGHT/6,ch2,strlen(ch2));;
	XFlush(disp);
	XNextEvent(disp,&event);
	XPoint tmp;
	tmp.x=event.xbutton.x;
	tmp.y=event.xbutton.y;
	if(tmp.y>=(HEIGHT/2)&&tmp.y<5*HEIGHT/8){
		if (tmp.x>=(2.*WIDTH/8) && tmp.x<=(3.*WIDTH/8)){
			return 1;
		}
		if (tmp.x>=(5.*WIDTH/8) && tmp.x<=(6.*WIDTH/8)){
			exit(EXIT_SUCCESS);
		}
    }
	return gameover(gagnant);	
}

#endif   /* defined(__Mini_projet_en_c__fonctionsgraphiques__) */
