/**
* @file entity.c
* @author lamti
* @version 1.0
*/
#include "entity.h"




int 
nb_frame=11 ,
entity_h=100,
entity_w=100,
entity_x=100;

/**
* @brief To initialize the entity's table of frames.
* @param e the entity
* @return Nothing
*/								 

void init_tab_anim_entity(SDL_Rect *clip,entity *e)
{		
	for (int j=0;j<nb_frame; j++)
	{
	clip[j].h=entity_h;
	clip[j].w=entity_w;
	clip[j].x = j*entity_x;
	clip[j].y = 0;
        }  
}

/**
* @brief To initialize the entity e  .
* @param e the entity
* @return Nothing
*/

void initentity(entity *e)
{


    e->entity = IMG_Load("tools/es.png"); 

    e->pos_entity.x = 400;
    e->pos_entity.y = 100;
    init_tab_anim_entity(e->anim_entity,e); 
    e->frame_entity=0;
    e->direction=0;  
    e->col=0;
    e->show=1; 
      
}

/**
* @brief To show the entity e .
* @param screen the screen
* @param e the entity
* @return Nothing
*/
void afficherentity(entity e , SDL_Surface *screen)
{
   if(e.show==1)
   SDL_BlitSurface(e.entity,&e.anim_entity[e.frame_entity], screen, &e.pos_entity);

}

/**
* @brief To randomize the movement of entity .
* @param e the entity
* @return Nothing
*/

void deplacer(entity *e)
{	
	srand (time(0)); //trandomizi les valeurs kol mara tsir lexecution
	int maxi_down=300+rand()%300;  
	int maxi_up=50+rand()%300; 


if(e->pos_entity.y>= maxi_down)
{
e->direction =1;
}
if(e->pos_entity.y<=maxi_up)
{
e->direction =0;
}

if(e->direction==1)
{   
	e->pos_entity.y-=18;

}
if(e->direction==0)
{
        
	e->pos_entity.y+=18;

}
}

/*
* @brief to animate the entity
* @param e the entity
* @return Nothing
*/

void animerentity(entity *e)
{   
	if (e->frame_entity >=0 && e->frame_entity <(nb_frame-1)) 
	e->frame_entity++;
	
	if ( e->frame_entity ==(nb_frame-1)) 
	e->frame_entity=0;
}

/*
* @brief to move and animate the entity
* @param e the entity
* @return Nothing
*/

void update_entity(entity *e)
{ 	
	deplacer(e);
	animerentity(e);	
}


/*
* @brief to detect collision
* @param e the entity
* @param p the main character
* @return the result of collision
*/

int detect_collision(personnage *p, entity* e)
{
	
if ((p->pos_perso.x + p->pos_perso.w< e->pos_entity. x) || (p->pos_perso.x> e->pos_entity. x + e->pos_entity. w) ||
(p->pos_perso.y + p->pos_perso.h< e->pos_entity. y) || (p->pos_perso.y> e->pos_entity. y + e->pos_entity. h ))
return 0;
else 
{ e->col=1;
return e->col;
 }
 
/*
* @brief to change state of show
* @param e the entity
* @return Nothing
*/ 
}
void gestion(entity *e)
{
e->show=0; 
}






