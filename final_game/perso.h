#ifndef perso_h
#define perso_h
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>

typedef struct{
  	SDL_Surface *image_p;
  	SDL_Rect pos_perso;
}personnage;


void initialiserperso(personnage *p);
void initialiserperso2(personnage *p);
void deplacer_perso(personnage *p,SDL_Event event);
void deplacer_perso2(personnage *p,SDL_Event event);
void afficher_perso(SDL_Surface *screen,personnage p);
void free_perso(personnage p);



#endif
