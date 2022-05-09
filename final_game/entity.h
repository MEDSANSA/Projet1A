/**
* @file entity.h
*/

#ifndef entite_H_INCLUDED 
#define entite_H_INCLUDED

#include <stdio.h>     
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include"perso.h" 
#include<time.h>

/**
* @struct entity
* @brief struct for entity
*/

typedef struct {   
	  

	SDL_Surface *entity;  /*!< Surface. */
	SDL_Rect pos_entity;  /*!< Rectangle*/
	SDL_Rect anim_entity[30];  /*!< TabDeRectangle*/
	int frame_entity;  /*!NbdeLimageaffiche*/
	int direction;
	int col ;  /*!collision*/
	int show;  /*!affichage si = 1*/

}entity ;


void init_tab_anim_entity(SDL_Rect* clip,entity *e);   
void initentity (entity *e) ;
void afficherentity(entity e , SDL_Surface *screen);
void animerentity(entity *e);
void deplacer(entity *e);
void update_entity(entity *e);
int detect_collision(personnage *p, entity* e);  
void gestion(entity *e);



#endif 
