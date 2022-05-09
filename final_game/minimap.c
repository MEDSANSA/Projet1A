#include "minimap.h"
#include "perso.h"

void initminimap(map *m,SDL_Surface *screen)
{
//load de minimap
    m->map=IMG_Load("tools/mini_backgg.png");
//position minimap fel ecran
    m->pos_map.x =800;
    m->pos_map.y =50;
//load de mini perso
    m->mini_perso=IMG_Load("tools/salah.png");
}

void MAJminimap(personnage p,map *m,SDL_Rect camera,int redimensionnement)
{
    SDL_Rect posJoueurABS;
    posJoueurABS.x = 0;
    posJoueurABS.y = 0;
    posJoueurABS.x = p.pos_perso.x + camera.x;
    posJoueurABS.y = p.pos_perso.y + camera.y;
    m->perso_pos_map.x=(posJoueurABS.x * redimensionnement/100)+802;
    m->perso_pos_map.y=(posJoueurABS.y * redimensionnement/100)+50;
}

void afficherminimap(map m,SDL_Surface *screen)
{
//affichage de minimap
    SDL_BlitSurface(m.map,NULL,screen,&m.pos_map);
//affichage de perso
    SDL_BlitSurface(m.mini_perso,NULL,screen,&m.perso_pos_map);
}

void liberer(Time T,map m)
{
    free(m.map);
    free(m.mini_perso);
    free(T.temps.textSurface);
    free(T.temps.police);
}

void Timer(int *tempsdebut)
{
    if( SDL_GetTicks() - *tempsdebut >= 1000 )
    {
        *tempsdebut = SDL_GetTicks() ;
    }
}

void inittemps(Time *t)
{
    int test;
    t->tempsdebut=SDL_GetTicks();
    t->mm=0;
    t->ss=0;
    test=initTexttime(&t->temps);
}

int initTexttime(Text* T)
{
    int testload;
    T->couleurTxt.r = 255;
    T->couleurTxt.g = 255;
    T->couleurTxt.b = 255;
    strcpy(T->txt, "");
    T->positionText.x = 1100;
    T->positionText.y = 10;
    testload=loadFonttime(T,"tools/avocado.ttf");
    T->textSurface=NULL;
    return testload;
}

int loadFonttime(Text* T, char* path)
{
    TTF_Font* police = NULL;

    if(TTF_Init() == -1)
    {
        printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        return -1;
    }
    T->police= TTF_OpenFont(path,30);
    return (0);
}

void update_time(Time* T)
{
    int ts;
    Timer(&T->tempsdebut);
    ts=T->tempsdebut/1000;
    T->mm=ts/ 60;
    T->ss=ts % 60;
    if(T->mm<=10&&T->ss<=9)
        sprintf(T->temps.txt,"temps: 0%.1d: 0%.1d",T->mm,T->ss);
    else if(T->mm<=10&&T->ss>=9)
        sprintf(T->temps.txt,"temps: 0%.1d: %.1d",T->mm,T->ss);
    else if(T->mm>=10&&T->ss<=9)
        sprintf(T->temps.txt,"temps: %.1d: 0%.1d",T->mm,T->ss);
    T->temps.textSurface=TTF_RenderText_Solid(T->temps.police,T->temps.txt,T->temps.couleurTxt);
    //ttfrender tekho l police o txt o couleur taa l text eli besh taficchiih
}

void displaytime(Time T,SDL_Surface *screen)
{
    SDL_BlitSurface(T.temps.textSurface,NULL,screen,&(T.temps.positionText));
}

void save_score(int score)
{
    FILE *fscore=NULL;
    fscore=fopen("score.txt","a+");
    fprintf(fscore,"%d \n",score);
    fclose(fscore);
}

void save_nom (char nom[20])
{
    FILE *fnom=NULL;
    fnom=fopen("nom.txt","a+");
    fprintf(fnom,"%s \n",nom);
    fclose(fnom);
}

int meilleur_score(int score)
{
    int bscr=50;
    FILE* fscore=NULL;
    fscore=fopen("score.txt","r");
    if(fscore!=NULL)
    {
    	while(fscanf(fscore,"%d",&score)>bscr && !feof(fscore))
    		{
    		printf("%d",score);
        	bscr=score;
        	}
    }
    fclose(fscore);
    return bscr;
}

void affichermscore(int score,SDL_Surface *ecran)
{
    int meilleur=meilleur_score(score);
    char ch[50];
    SDL_Surface *meilleurs=NULL;
    SDL_Rect posm;
    posm.x=530;
    posm.y=630;
    TTF_Font* police=TTF_OpenFont("tools/avocado.ttf",30);
    sprintf(ch,"Meilleur score: %d",meilleur);
    SDL_Color couleur= {255, 255, 255};
    meilleurs= TTF_RenderText_Blended(police,ch,couleur);
    SDL_BlitSurface(meilleurs,NULL,ecran,&posm);
}

