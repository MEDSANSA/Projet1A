/**
* @file enigme.h 
* @brief  Program components.
* @author h Team
* @version 0.1
* @date Apr 19,2022
*
* le .h  de l enigme
*
*
*/
#ifndef ENIGMEIMAGE_H_INCLUDED
#define ENIGMEIMAGE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<math.h>
/**
* @struct enigme
* @brief  struct for enigme
*/
typedef struct {
      SDL_Surface* img; /*!<Surface. */
      SDL_Rect p;       /*!<Rectangle */
      SDL_Surface *reponse1; /*!<Surface. */
      SDL_Surface *reponse2; /*!<Surface. */
      SDL_Surface *reponse3; /*!<Surface. */
      SDL_Rect p1; /*!<Rectangle */
      SDL_Rect p2; /*!<Rectangle */
      SDL_Rect p3; /*!<Rectangle */
      SDL_Surface *correct; /*!<Surface. */
      SDL_Surface *wrong; /*!<Surface. */
      SDL_Rect pos_w; /*!<Rectangle */
      SDL_Rect pos_c; /*!<Rectangle */
      int reponse_correcte; /*!<Integer */
      int reponse_choisie;  /*!<Integer */
      SDL_Surface *anim[10]; /*!<Surface. */
      SDL_Rect posanim; /*!<Rectangle */
      int num; /*!<Integer */
}enigmeimage;
typedef struct
{
 SDL_Surface *img;
 SDL_Rect 	p;
 int reponse_choisie; 
}choix;

/*
void remplir_fichier(char nomfichier[]);
void remplir_fichier1(char nomfichier[]);
*/
void genererEnigmee(enigmeimage *e,char nomfichier[],char nomfichier1[]);
void afficherEnigmee(SDL_Surface * screen ,enigmeimage *e);
void choisir(enigmeimage *e, SDL_Surface* screen,int *run);
void afficher_resultat (SDL_Surface * screen,enigmeimage *e);
void init_enigmee(enigmeimage * e);
void Free(enigmeimage *e);
void init_choix(choix *c) ;
void  generate_afficher (SDL_Surface * screen,choix *c);
void choisirchoix(choix *c,int *run);
void Freechoix(choix *c);
#endif
