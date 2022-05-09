#ifndef background_h
#define background_h
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#define SCREEN_W 1366
#define SCREEN_H 678
#define SCREEN_W2 683
#define SCREEN_H2 678

typedef struct{
	SDL_Surface *imgback; 	
	SDL_Surface *imgbackm; 	
	SDL_Rect posback; 		
	SDL_Rect posbackm; 		
	SDL_Rect posback1;		
	SDL_Rect posbackm1;		
	SDL_Rect camera; 		
	SDL_Rect camera1; 		
	Mix_Music *son; 		
}background;

void initBack (background *b);
void initBack1 (background *b);
void afficheBack (background b,SDL_Surface *ecran);
void afficheBack1 (background b,SDL_Surface *ecran);
void scrolling (background *b,int direction);
void liberer(background b);
#endif
