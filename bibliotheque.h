#include <X11/Xlib.h>
#include <X11/Xutil.h>
#ifndef _STDLIB_H_
	#include <stdlib.h> // Pour la fonction atexit()
#endif
Display * disp; 	// canal de communication avec le serveur X
int scr;			// Le num�ro de l'�cran o� s'affiche notre fen�tre
Window win;		// La fen�tre du programme (il peut y en avoir plusieurs)
GC gc;			// modes graphiques (�paisseur de trait, couleurs, ...)
unsigned long BLACK,WHITE,red_mult,green_mult,blue_mult;
void initColors(void){ 
	BLACK=BlackPixel(disp,scr);	
	WHITE=WhitePixel(disp,scr);
	XColor redcolor,greencolor,bluecolor,aux;
	XAllocNamedColor(disp,DefaultColormap(disp,scr),"red",&redcolor,&aux);
	XAllocNamedColor(disp,DefaultColormap(disp,scr),"green",&greencolor,&aux);
	XAllocNamedColor(disp,DefaultColormap(disp,scr),"blue",&bluecolor,&aux);
	red_mult=(redcolor.pixel-BLACK)/0xFF;
	green_mult=(greencolor.pixel-BLACK)/0xFF;
	blue_mult=(bluecolor.pixel-BLACK)/0xFF;
}
unsigned long pixel(unsigned short r,unsigned short g,unsigned short b){
	return BLACK+r*red_mult+g*green_mult+b*blue_mult;
}
unsigned long pixelByName(char colorName[]){
	XColor color,aux;
	XAllocNamedColor(disp,DefaultColormap(disp,scr),colorName,&color,&aux);
	return color.pixel;
}
void dealloc(void){
	if(disp) XCloseDisplay(disp);   
}
void initWindow(int width,int height,char name[]){
	atexit(dealloc);
	if(!(disp=XOpenDisplay(""))) exit(-1);		// Ouvre la connexion au serveur X11
	scr=DefaultScreen(disp);				// choix de l'�cran parmi ceux g�r�s par le serveur		
	initColors();							// adaptation � la palette de couleurs du serveur 
	win=XCreateSimpleWindow(disp,RootWindow(disp,scr),0,0,width,height,2,BLACK,WHITE);
	if(!win) exit(-1);						// Si �chec lors de la cr�ation de la fen�tre
	if(!(gc=XCreateGC(disp,win,0,0))) exit(-1);	// Cr�ation d'un contexte graphique, sortie si �chec
	XStoreName(disp,win,name);				// Choix du nom de la fen�tre
	XMapWindow(disp,win);					// Dire au serveur qu'une fen�tre est cr��e 	
		
	XSetWindowAttributes xsetwinAtt;			// Pour �viter que le dessin disparaisse
	xsetwinAtt.bit_gravity=NorthWestGravity;	// lors d'un changement de la position ou taille de la fen�tre
	XChangeWindowAttributes(disp,win,CWBitGravity,&xsetwinAtt);
  
	XFlush(disp);							// Afficher ce qui a �t� cr��
}
void setWindowBackground(unsigned long pix){
	XSetWindowBackground(disp,win,pix);	
	XClearWindow(disp,win);				// Efface la fen�tre
	XFlush(disp);							// Redessine avec les nouvelles donn�es
}

void setForeground(unsigned long pix){
	XSetForeground(disp,gc,pix);
}
void drawLine(int xA,int yA,int xB,int yB){
	XDrawLine(disp,win,gc, xA,yA,xB,yB);		// Demande de trac� d'une ligne
	XFlush(disp);							// Transmission de la demande
}

