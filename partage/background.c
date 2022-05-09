#include "background.h"

void initBack (background *b)
{
//background load et position
    b->imgback=IMG_Load("tools/background.png");
    b->posback.x=0;
    b->posback.y=0;
//background masque load et position
    b->imgbackm=IMG_Load("tools/backgroundmas.png");
    b->posbackm.x=0;
    b->posbackm.y=0;
//camera position et taille
    b->camera.x=0;
    b->camera.y=0;
    b->camera.w=SCREEN_W;
    b->camera.h=SCREEN_H;
//musique
    b->son=Mix_LoadMUS("tools/music.mp3"); //Chargement de la musique
    Mix_PlayMusic(b->son, -1); //Jouer infiniment la musique
}

void initBack1 (background *b)
{
//background load et position
    b->imgback=IMG_Load("tools/background.png");
    b->posback1.x=SCREEN_W2;
    b->posback1.y=0;
//background masque load et position
    b->imgbackm=IMG_Load("tools/backgroundmas.png");
    b->posbackm1.x=SCREEN_W2;
    b->posbackm1.y=0;
//camera position et taille
    b->camera1.x=0;
    b->camera1.y=0;
    b->camera1.w=SCREEN_W2;
    b->camera1.h=SCREEN_H2;
}

void afficheBack (background b, SDL_Surface *ecran)
{
    SDL_BlitSurface(b.imgbackm,&b.camera,ecran,&b.posbackm);
    //SDL_BlitSurface(b.imgback,&b.camera,ecran,&b.posback);
}

void afficheBack1 (background b, SDL_Surface *ecran)
{
    SDL_BlitSurface(b.imgbackm,&b.camera1,ecran,&b.posbackm1);
    //SDL_BlitSurface(b.imgback,&b.camera1,ecran,&b.posback1);
}

void scrolling (background *b,int direction)
{
int speed=6;
    if (direction ==0 && b->camera.x + speed < 2034)//right
    {
        b->camera.x+=speed;
    }
    else
    {
        if(direction==1 && b->camera.x - speed > 0)//left
        {
            b->camera.x-=speed;
        }
        else if(direction==2 && b->camera.y + speed < 0)//up
        {
            b->camera.y-=speed;
        }
        else if(direction==3 && b->camera.y - speed < 0)//down
        {
            b->camera.y+=speed;
        }else
        //camera2
        if(direction==4 && b->camera1.x + speed < 2034)//right
        {
            b->camera1.x+=speed;
        }
        else if(direction==5 && b->camera1.x - speed > 0)//left
        {
            b->camera1.x-=speed;
        }
        else if(direction==6 && b->camera1.y + speed < 0)//up
        {
            b->camera1.y-=speed;
        }else
        if(direction==7 && b->camera1.y - speed < 0)//down
        {
            b->camera1.y+=speed;
        }
    }
}

void liberer(background b)
{
	free(b.imgback);
	free(b.imgbackm);
	free(b.son);
}


