#include "background.h"
#include "perso.h"

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
//numero de l'image affiche
    b->num1=0;
    b->num1=0;
//position de l'animation 1
    b->posanim1.x = 0;
    b->posanim1.y = 450;
//position de l'animation 2
    b->posanim2.x = 50;
    b->posanim2.y = 50;
//image de l'animation 1
    b->anim1[0]=IMG_Load("tools/an0.png");
    b->anim1[1]=IMG_Load("tools/an1.png");
    b->anim1[2]=IMG_Load("tools/an2.png");
    b->anim1[3]=IMG_Load("tools/an3.png");
    b->anim1[4]=IMG_Load("tools/an4.png");
    b->anim1[5]=IMG_Load("tools/an5.png");
    b->anim1[6]=IMG_Load("tools/an6.png");
    b->anim1[7]=IMG_Load("tools/an7.png");
    b->anim1[8]=IMG_Load("tools/an8.png");
//image de l'animation 2
    b->anim2[0]=IMG_Load("tools/ois0.png");
    b->anim2[1]=IMG_Load("tools/ois1.png");
    b->anim2[2]=IMG_Load("tools/ois2.png");
    b->anim2[3]=IMG_Load("tools/ois3.png");
    b->anim2[4]=IMG_Load("tools/ois4.png");
    b->anim2[5]=IMG_Load("tools/ois5.png");
    b->anim2[6]=IMG_Load("tools/ois6.png");
    b->anim2[7]=IMG_Load("tools/ois7.png");
    b->anim2[8]=IMG_Load("tools/ois8.png");
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
//affichage de background
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
int speed=12;
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

//traja3lek l couleur taa lpixel eli fiha l personnage
SDL_Color getpixel(SDL_Surface *pSurface,int x,int y)
{
    SDL_Color color;
    Uint32 col=0;
    char* pPosition=(char* ) pSurface->pixels;
    pPosition+= (pSurface->pitch * y);
    pPosition+= (pSurface->format->BytesPerPixel *x);
    memcpy(&col,pPosition,pSurface->format->BytesPerPixel);
    SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b);
    return (color);
}

int  collisionpp(SDL_Surface *psurface,personnage p)
{
    int i,collision=0;
    SDL_Color color1,color;
    color1.r = 0;
    color1.g = 0;
    color1.b = 0;
    SDL_Rect tab[8];
    tab[0].x=p.pos_perso.x;
    tab[1].x=(p.pos_perso.x)+((p.pos_perso.w)/2);
    tab[2].x=(p.pos_perso.x+p.pos_perso.w);
    tab[3].x=p.pos_perso.x;
    tab[4].x=p.pos_perso.x;
    tab[5].x=(p.pos_perso.x)+((p.pos_perso.w)/2);
    tab[6].x=(p.pos_perso.x+p.pos_perso.w);
    tab[7].x=(p.pos_perso.x+p.pos_perso.w);
    tab[0].y=p.pos_perso.y;
    tab[1].y=p.pos_perso.y;
    tab[2].y=p.pos_perso.y;
    tab[3].y=(p.pos_perso.y)+((p.pos_perso.h)/2);
    tab[4].y=(p.pos_perso.y+p.pos_perso.h);
    tab[5].y=(p.pos_perso.y+p.pos_perso.h);
    tab[6].y=(p.pos_perso.y+p.pos_perso.h);
    tab[7].y=(p.pos_perso.y)+((p.pos_perso.h)/2);

    for(i=0; i<8 && collision==0; i++)
    {
        color=getpixel(psurface,tab[i].x,tab[i].y);
        if(color.r==color1.r && color.g==color1.g && color.b==color1.b)
        {
            collision=1;
        }
    }
    return collision;
}

void animerbackground (background *b,SDL_Surface *ecran)
{
    //animation 1
    if(b->num1 == 8)
    {
        b->num1 = 0;
    }
    else
    {
    b->num1++;
    }
    //animation 2
    if(b->num2 == 8)
    {
        b->num2 = 0;
    }
    else
    {
        b->num2++;
    }

//affichage de l'animation
    SDL_BlitSurface(b->anim1[b->num1],NULL,ecran,&b->posanim1);
    SDL_BlitSurface(b->anim2[b->num2],NULL,ecran,&b->posanim2);
}

void lib(background b)
{
	free(b.imgback);
	free(b.imgbackm);
	free(b.anim1[0]);
	free(b.anim1[1]);
	free(b.anim1[2]);
	free(b.anim1[3]);
	free(b.anim1[4]);
	free(b.anim1[5]);
	free(b.anim1[6]);
	free(b.anim1[7]);
	free(b.anim1[8]);
	free(b.anim2[0]);
	free(b.anim2[1]);
	free(b.anim2[2]);
	free(b.anim2[3]);
	free(b.anim2[4]);
	free(b.anim2[5]);
	free(b.anim2[6]);
	free(b.anim2[7]);
	free(b.anim2[8]);
	free(b.son);
}


