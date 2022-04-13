#include "perso.h"

void initialiserperso(personnage *p){	
	p->image_p=IMG_Load("per.bmp");
	p->pos_perso.x=0;
	p->pos_perso.y=550;
	p->pos_perso.w=100;
	p->pos_perso.h=100;
}

void afficher_perso(SDL_Surface *ecran,personnage p){	
	SDL_BlitSurface(p.image_p,NULL,ecran,&p.pos_perso);
}

void deplacer_perso(personnage *p,SDL_Event event){	
	SDL_PollEvent(&event);
         switch(event.type){
                case SDL_KEYDOWN:
                       switch(event.key.keysym.sym){
                        case SDLK_UP:
                            p->pos_perso.y=p->pos_perso.y-4;
                            break;
                        case SDLK_DOWN:
                            p->pos_perso.y=p->pos_perso.y+4;
                            break;
                        case SDLK_RIGHT:
                            p->pos_perso.x=p->pos_perso.x+4;
                            break;
                        case SDLK_LEFT:
                            p->pos_perso.x=p->pos_perso.x-4;
                            break;
                        }
                 break;
             }
}

void free_perso(personnage p){
	SDL_FreeSurface(p.image_p);
}
