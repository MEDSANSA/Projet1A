#ifndef ENNEMIE_H_INCLUDED
#define ENNEMIE_H_INCLUDED

/**
* @file ennemy.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include<time.h>
#include "entity.h"
#include"perso.h" 

/**
* @struct ennemy
* @brief struct for ennemy
*/


typedef struct {
	SDL_Surface *ennemie ;  /*!< Surface. */ 
	SDL_Rect pos_ennemie;  /*!< Rectangle*/
	SDL_Rect anim_ennemie[30]; /*!< TabDeRectangle*/
	int frame_ennemie; /*!NbdeLimageaffiche*/
	int direction;
	int col ; /*!collision*/
	int show; /*!affichage si = 1*/ 

}Ennemie;

void init_tab_anim_ennemie (SDL_Rect* clip,Ennemie *e); 
void initEnnemi  (Ennemie *e) ;
void afficherEnnemi (Ennemie e, SDL_Surface *screen);
void animerEnnemi (Ennemie *e);
void deplaceren (Ennemie *e,personnage *p);
void update_ennemie (Ennemie *e,personnage *p);
int detect_collision_ennemie(personnage *p, Ennemie *e);
void gerer(Ennemie *e) ; 


#endif 
