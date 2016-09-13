//
//  fonctions.c
//  Mini projet en c
//
//  Created by Valentin Pich' on 20/10/2014.
//  Copyright (c) 2014 ESEO. All rights reserved.
//
#include "fonctions.h"

void initpioche(Carte *pioche,int joueurs,Carte *deck){
    int i;
    for(i=0;i<(102-12*joueurs);i++){
        pioche[i].valeur=-1;
    }
    int a=0;
    int x=(rand()%(110));
    while(a<(102-12*joueurs)){
        if((pioche[a].valeur==-1)&&(deck[x].valeur!=-1)){
            pioche[a].couleur=deck[x].couleur;
            pioche[a].valeur=deck[x].valeur;
            deck[x].valeur=-1;
            a++;
        }
        x=(rand()%(110));
    }
}

void initrangee(Carte *rangee,int joueurs,Carte *deck){
    int i;
    for(i=0;i<(8);i++){
        rangee[i].valeur=-1;
    }
    int a=0;
    int x=(rand()%(110));
    while(a<(5+joueurs)){
        if((rangee[a].valeur==-1)&&(deck[x].valeur!=-1)){
            rangee[a].couleur=deck[x].couleur;
            rangee[a].valeur=deck[x].valeur;
            deck[x].valeur=-1;
            a++;
        }
        x=(rand()%(110));
    }
}

void initjoueur(Carte *joueur,Carte *deck){
    int i;
    for(i=0;i<14;i++){
        joueur[i].valeur=-1;
        
    }
    int a=0;
    int x=(rand()%(110));
    while(a<(12)){
        if((joueur[a].valeur==-1)&&(deck[x].valeur!=-1)){
            joueur[a].couleur=deck[x].couleur;
            joueur[a].valeur=deck[x].valeur;
            deck[x].valeur=-1;
            a++;
        }
        x=(rand()%(110));
    }
}

void initdefausse(Carte *defausse,Carte *pioche){
    Carte aux;
    aux=gererpioche(pioche,1);
    defausse->valeur=aux.valeur;
    defausse->couleur=aux.couleur;
    (defausse+1)->valeur=-1;
}

void gererdefausse(Carte *def,bool add,Carte a){
    int i=0;
    int j=0;
    if(add){
        for(i=0;i<110;i++){
            if((def+i)->valeur==-1)break;
        }
        for(j=0;j<i;j++){
            (def+i+1)->valeur=(def+i)->valeur;
            (def+i+1)->couleur=(def+i)->couleur;
        }
        def->valeur=a.valeur;
        def->couleur=a.couleur;
    }else{
        for(i=0;((def+i)->valeur)!=-1;i++){
            (def+i)->valeur=(def+i+1)->valeur;
            (def+i)->couleur=(def+i+1)->couleur;
        }
        (def+i+1)->valeur=-1;
        def[i].valeur=-1;
    }
}

void gererrangee(Carte *rangee){
    int i=0;
    for(i=0;((rangee+i)->valeur)!=-1;i++){
        (rangee+i)->valeur=(rangee+i+1)->valeur;
        (rangee+i)->couleur=(rangee+i+1)->couleur;
    }
}

Carte gererpioche(Carte *pioche,int NBJOUEUR){
    int i=0;
    Carte a;
    a.valeur=pioche->valeur;
    a.couleur=pioche->couleur;
    for(i=0;((pioche+i)->valeur)!=-1;i++){
        (pioche+i)->valeur=(pioche+i+1)->valeur;
        (pioche+i)->couleur=(pioche+i+1)->couleur;
    }
    return a;
}

void choixjoueurpioche(Carte *pioche,Carte *defausse,Carte *joueur,Carte *rangee,int NBJOUEUR){
    int c=-1;
    int i=0;
    Carte u;
    u.valeur=-1;
    bool test=0;
    do{
      	c=choixpioche();
        if(c==1&&rangee->valeur!=-1)test=1;
        if(c==2&&defausse->valeur!=-1)test=1;
        if(c==3&&pioche->valeur!=-1)test=1;
    }while(!test);
    for(i=0;i<12;i++){
        if((joueur+i)->valeur==-1)break;
    }
    if(c==1){
        (joueur+i)->couleur=rangee->couleur;
        (joueur+i)->valeur=rangee->valeur;
        (joueur+i+1)->valeur=-1;
        gererrangee(rangee);
    }
    if(c==2){
        (joueur+i)->couleur=defausse->couleur;
        (joueur+i)->valeur=defausse->valeur;
        (joueur+i+1)->valeur=-1;
        gererdefausse(defausse,0, u);
    }
    if(c==3){
        (joueur+i)->couleur=pioche->couleur;
        (joueur+i)->valeur=pioche->valeur;
        (joueur+i+1)->valeur=-1;
        gererpioche(pioche,NBJOUEUR);
        if(i==11){
            (joueur+i+1)->valeur=-1;
        }else{
            for(;i<13;i++){
                if((joueur+i)->valeur==-1)(joueur+i+1)->valeur=-1;
            }
        }
    }
}

void choixjoueurdefausse(Carte *joueur,Carte *defausse,int numeroj){
    int a=0;
    int b=0;
    while(a<1||a>13){
          a=choixdefausse(numeroj,1);
    }
    Carte tampon;
    tampon.valeur=(joueur+a-1)->valeur;
    tampon.couleur=(joueur+a-1)->couleur;
    if(a==13){
        gererdefausse(defausse,1,tampon);
        (joueur+a-1)->valeur=-1;
    }else{
        gererdefausse(defausse,1,tampon);
        (joueur+a-1)->valeur=-1;
        for(b=a-1;b<13;b++){
            (joueur+b)->valeur=(joueur+b+1)->valeur;
            (joueur+b)->couleur=(joueur+b+1)->couleur;
            
        }
        (joueur+b)->valeur=-1;
    }
}

int gererigo(Carte *joueur,Carte *adversaire,int colorangee,int colorsuiteun,int colorsuitedeux){
    int score=1;
    int i=0;
    int player=0;
    int opponent=0;
    Carte couleur[13];
    couleur->valeur=-1;
    couleur->couleur=-1;
    Carte playerigo[13];
    playerigo->valeur=-1;
    playerigo->couleur=-1;
    Carte opponentigo[13];
    opponentigo->valeur=-1;
    opponentigo->couleur=-1;
    Carte suite[13];
    suite->valeur=-1;
    suite->couleur=-1;
    for(i=0;i<13;i++){
        if((joueur+i)->couleur==colorangee){
             ajoutercarte(couleur, joueur+i);
        }
    }
    for(i=0;i<13;i++){
        if(((joueur+i)->couleur==colorsuiteun)||((joueur+i)->couleur==colorsuitedeux)){
            if(valeurcartepresent(suite,joueur[i])==0) {
                ajoutercarte(suite, joueur+i);
            }
        }
    }
    for(i=0;i<13;i++){
        if(((adversaire+i)->couleur==colorsuiteun)||((adversaire+i)->couleur==colorsuitedeux)){
            if(valeurcartepresent(suite,adversaire[i])==0) {
                ajoutercarte(suite, adversaire+i);
            }
        }
    }
    for(i=0;i<13;i++){
        if((joueur+i)->valeur!=-1)player+=(joueur+i)->valeur;
	if((adversaire+i)->valeur!=-1)opponent+=(adversaire+i)->valeur;
    }
    for(i=0;i<13;i++){
        if((joueur+i)->valeur!=-1){
             ajoutercarte(playerigo, joueur+i);
        }
    }
    for(i=0;i<13;i++){
        if((adversaire+i)->valeur!=-1){
             ajoutercarte(opponentigo, adversaire+i);
        }
    }
    if(opponent<=player)score=2;
    ordonnersuite(suite);
    if(player==0)score=4;
    dessinerigo(playerigo,opponentigo,couleur,suite,WIDTHCARD,HEIGHTCARD,score);
    return score;
}

bool valeurcartepresent(Carte *test,Carte a){
    int i=0;
    for(i=0;((test+i)->valeur)!=-1;i++){
        if(a.valeur==(test+i)->valeur) return 1;
    }
    return 0;
}

void ajoutercarte(Carte *a,Carte *add){
    int i=0;
    for(i=0;(a+i)->valeur!=-1;i++){
    }
    (a+i+1)->valeur=(a+i)->valeur;
    (a+i)->valeur=add->valeur;
    (a+i)->couleur=add->couleur;
    add->valeur=-1;
}

void ordonnersuite(Carte *suite){
    int tmp=-1;
    int i=0;
    int j=0;
    for(j=0;j<12;j++){
        for(i=0;(suite+i+1)->valeur!=-1;i++){
            if(((suite+i)->valeur)>((suite+i+1)->valeur)){
                tmp=(suite+i)->valeur;
                (suite+i)->valeur=(suite+i+1)->valeur;
                (suite+i+1)->valeur=tmp;
            }
        }
    }
}

int jouerigo(Carte *pioche,Carte *defausse, Carte *joueur,Carte *adversaire, Carte *rangee,int NBJOUEUR,int numeroj){
    int test=-1;
    int carte1=-1;
    int carte2=-1;
    int score=0;
    choixjoueurpioche(pioche, defausse, joueur, rangee, NBJOUEUR);
    dessinerseriecarte(joueur,adversaire,defausse,rangee,pioche,WIDTHCARD,HEIGHTCARD,numeroj);
    dessinerchainearactere(numeroj);
    choixjoueurdefausse(joueur, defausse,numeroj);
    dessinerseriecarte(joueur,adversaire,defausse,rangee,pioche,WIDTHCARD,HEIGHTCARD,numeroj);
    dessinerchainearactere(numeroj);
    if(rangee->valeur==-1){
        if(numeroj==1)score=-1;
	if(numeroj==2)score=-2;
 	return score;
    }
    if(pioche->valeur!=-1){
        while(test!=0&&test!=1){
            test=choixigo();
        }
    }else{
        test=1;
       	piochevide();
    }
    if(test){
	dessinerseriecarte(joueur,adversaire,defausse,rangee,pioche,WIDTHCARD,HEIGHTCARD,numeroj);
    	dessinerchainearactere(numeroj);
        firstepigo();
        do{
        	carte1=choixdefausse(numeroj,0);
        	carte1=(joueur+carte1-1)->couleur;
        } while(rangee->couleur==carte1);
	dessinerseriecarte(joueur,adversaire,defausse,rangee,pioche,WIDTHCARD,HEIGHTCARD,numeroj);
    	dessinerchainearactere(numeroj);        
	secondstepigo();
        do{
        	carte2=choixdefausse(numeroj,0);
        	carte2=(joueur+carte2-1)->couleur;
        } while(rangee->couleur==carte2);
        dessinerseriecarte(joueur,joueur,defausse,rangee,pioche,WIDTHCARD,HEIGHTCARD,numeroj);
        dessinerchainearactere(numeroj);
        if(numeroj==1)score=gererigo(joueur, adversaire,rangee->couleur, carte1, carte2);
        if(numeroj==2)score=gererigo(adversaire,joueur,rangee->couleur, carte1, carte2);
	usleep(10000000);
    } 
    return score;
}
