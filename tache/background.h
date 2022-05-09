#ifndef background_h
#define background_h
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 1366
#define SCREEN_H 678
#include "perso.h"

typedef struct{
	SDL_Surface *imgback;
	SDL_Surface *imgbackm;
	SDL_Surface *anim1[10];
	SDL_Surface *anim2[10];
	SDL_Rect posback;
	SDL_Rect posbackm;
	SDL_Rect posanim1;
	SDL_Rect posanim2;
	int num1;
	int num2;
	SDL_Rect camera;
	Mix_Music *son;
}background;

void initBack (background *b);
void afficheBack (background b,SDL_Surface *ecran);
void scrolling (background *b,int direction);
void animerbackground(background *b,SDL_Surface *ecran);
SDL_Color getpixel(SDL_Surface *pSurface,int x,int y);
int  collisionpp(SDL_Surface *psurface,personnage p);
void liberer(background b);
#endif
