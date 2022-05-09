#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct{
	SDL_Surface *background;//background a afficher
	SDL_Surface *question;//question a afficher
	SDL_Surface *reponses[3];//reponse a afficher
	SDL_Surface *button;//button non selectionner
	SDL_Surface *button_s;//button selectionner
	int pos_selected;//position de reponse selectionner
	SDL_Rect pos_question;//position de qustion
	SDL_Rect pos_reponse1;//position de reponse 1
	SDL_Rect pos_reponse2;//position de reponse 2
	SDL_Rect pos_reponse3;//position de reponse 3
	int num_question;//numero de question
	SDL_Rect pos_reponse1txt;//position de reponse 1
	SDL_Rect pos_reponse2txt;//position de reponse 2
	SDL_Rect pos_reponse3txt;//position de reponse 3
	int vrai_reponse;//numero de bon reponse
	int positionVraiReponse;//position de bon reponse
	Mix_Chunk *sound;//son bref
	SDL_Surface *anim[10];
	SDL_Rect posanim;
	int num;
}enigme;

void init_enigme(enigme *e);//generer un enigme
void afficher_enigme(enigme *e,SDL_Surface *ecran);//affichage de l'enigme
void verify_enigme(enigme *e,SDL_Surface*ecran);//verification et affichage de resultat
void free_enigme(enigme *e);//liberation
/*
//hedhom zeydin lel validation ejjeya
void SaveGame(personne p);//tkhabilek positioon el joueur fi ekher game
void loadGame(personne *p);//tloadi position el joueur lekhrenin
*/

#endif
