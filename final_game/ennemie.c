/**
* @file ennemy.c
* @author lamti
* @version 1.0
*/
#include "ennemie.h"



int 
nb_frame1=12 ,
ennemie_h=100,
ennemie_w=100,
ennemie_x=100;

/**
* @brief To initialize the ennemy's table of frames.
* @param e the ennemy
* @return Nothing
*/
void init_tab_anim_ennemie(SDL_Rect *clip,Ennemie *e)
{	


for (int j=0;j<nb_frame1; j++)
	{
	clip[j].h=ennemie_h;
	clip[j].w=ennemie_w;
	clip[j].x = j*ennemie_x;
	clip[j].y = 0;
        }


}

/**
* @brief To initialize the ennemy e  .
* @param e the ennemy
* @return Nothing
*/

void initEnnemi(Ennemie *e)
{

    e->ennemie = IMG_Load("tools/ENNEMIE.png");

    e->pos_ennemie.x = 900;
    e->pos_ennemie.y = 400;
    init_tab_anim_ennemie(e->anim_ennemie,e);
    e->frame_ennemie=0;
    e->direction=0;  
    e->col=0;
    e->show=1;
    
    
}

/**
* @brief To show the ennemy e .
* @param screen the screen
* @param e the ennemy
* @return Nothing
*/

void afficherEnnemi(Ennemie e, SDL_Surface *screen)
{
   if(e.show==1)
   SDL_BlitSurface(e.ennemie,&e.anim_ennemie[e.frame_ennemie], screen, &e.pos_ennemie);
  
  

}

/**
* @brief To randomize the movement of ennemy .
* @param e the ennemy
* @return Nothing
*/

void deplaceren(Ennemie *e,personnage *p)
{	srand (time(0));
	int diff;
	int maxi_down=300+rand()%300;
	int maxi_up=150+rand()%300;

  	


if(e->pos_ennemie.y>= maxi_down)
{
e->direction =1;
}
if(e->pos_ennemie.y<=maxi_up)
{
e->direction =0;
}

if(e->direction==1)
{   
	e->pos_ennemie.y-=18;

}
if(e->direction==0)
{
	e->pos_ennemie.y+=18;
}

  diff=e->pos_ennemie.x-p->pos_perso.x;
  
  if (diff<350 && diff>50 ){

e->pos_ennemie.x-=10;
  }

if (diff >-350 && diff < 0){
  
  e->pos_ennemie.x+=10;
  }


}

/*
* @brief to animate the ennemy
* @param e the ennemy
* @return Nothing
*/

void animerEnnemi(Ennemie *e)
{   if (e->frame_ennemie >=0 && e->frame_ennemie <(nb_frame1-1)) 
 e->frame_ennemie++;
    if ( e->frame_ennemie ==(nb_frame1-1)) 
       e->frame_ennemie=0;
}

/*
* @brief to move and animate the ennemy
* @param e the ennemy
* @return Nothing
*/

void update_ennemie(Ennemie *e,personnage *p)
{ 	deplaceren(e,p);
	animerEnnemi(e);

}

    
    
/*
* @brief to detect collision
* @param e the ennemy
* @param p the main character
* @return the result of collision
*/


int detect_collision_ennemie(personnage *p, Ennemie *e)
{
	
if ((p->pos_perso.x + p->pos_perso. w< e->pos_ennemie. x) || (p->pos_perso.x> e->pos_ennemie. x + e->pos_ennemie. w) ||
(p->pos_perso.y + p->pos_perso.h< e->pos_ennemie. y) || (p->pos_perso.y> e->pos_ennemie. y + e->pos_ennemie. h ))
return 0;
else { e->col=1;
return e->col;
 }
}


/*
* @brief to change state of show
* @param e the entity
* @return Nothing
*/ 

void gerer(Ennemie *e) {
	
	e->show=0;
	
}








