/**
* @file enigme.c
*/
#include"enigmeimage.h"
/**
*  @brief  pour initialiser l enigme
*  @param e l enigme
*  @return Nothing
*/
void init_enigmee(enigmeimage * e)
{
	e->p.x=200;
	e->p.y=10;	
	e->img=NULL;
	e->p1.x=580;
	e->p1.y=275;	
	e->reponse1=NULL;
	e->p2.x=580;
	e->p2.y=350;	
	e->reponse2=NULL;
	e->p3.x=580;
	e->p3.y=425;	
	e->reponse3=NULL;
	e->correct=NULL;
	e->pos_c.x=200;
	e->pos_c.y=100;	
	e->wrong=NULL;
	e->pos_w.x=200;
	e->pos_w.y=100;
	e->reponse_correcte=-1;
	e->reponse_choisie=-1;
	e->anim[0]=IMG_Load("img/sab.png");
	e->anim[1]=IMG_Load("img/sab1.png");
	e->anim[2]=IMG_Load("img/sab2.png");
	e->anim[3]=IMG_Load("img/sab3.png");
	e->anim[4]=IMG_Load("img/sab4.png");
	e->anim[5]=IMG_Load("img/sab5.png");
	e->anim[6]=IMG_Load("img/sab6.png");
	e->posanim.x=675;
	e->posanim.y=90;
        e->num=0;


}
/*
void remplir_fichier(char nomfichier[])
{
FILE* fichier=NULL;
fichier=fopen(nomfichier,"w");
int y=1,y1=2,y2=3,y3=4,y4=5;
int x=1,x1=3,x2=2,x3=3,x4=1;
char ch1[100]="turki1.png",ch2[100]="turki2.png",ch3[100]="turki3.png";
char ch4[100]="turki4.png",ch5[100]="turki5.png";
if(fichier!=NULL)
{
fprintf(fichier,"%d %s %d\n",y,ch1,x);
fprintf(fichier,"%d %s %d\n",y1,ch2,x1);
fprintf(fichier,"%d %s %d\n",y2,ch3,x2);
fprintf(fichier,"%d %s %d\n",y3,ch4,x3);
fprintf(fichier,"%d %s %d\n",y4,ch5,x4);
}
else 
printf("il y a une erreur fichier\n");
fclose(fichier);
}
void remplir_fichier1(char nomfichier[])
{
FILE* fichier=NULL;
fichier=fopen(nomfichier,"w");
int y=1,y1=2,y2=3,y3=4,y4=5;
char ch1[100]="turki1_1.png",ch2[100]="turki1_2.png",ch3[100]="turki1_3.png";
char ch4[100]="turki2_1.png",ch5[100]="turki2_2.png",ch6[100]="turki2_3.png";
char ch7[100]="turki3_1.png",ch8[100]="turki3_2.png",ch9[100]="turki3_3.png";
char ch10[100]="turki4_1.png",ch11[100]="turki4_2.png",ch12[100]="turki4_3.png";
char ch13[100]="turki5_1.png",ch14[100]="turki5_2.png",ch15[100]="turki5_3.png";
if(fichier!=NULL)
{
fprintf(fichier,"%d %s %s %s\n",y,ch1,ch2,ch3);
fprintf(fichier,"%d %s %s %s\n",y1,ch4,ch5,ch6);
fprintf(fichier,"%d %s %s %s\n",y2,ch7,ch8,ch9);
fprintf(fichier,"%d %s %s %s\n",y3,ch10,ch11,ch12);
fprintf(fichier,"%d %s %s %s\n",y4,ch13,ch14,ch15);
}
else 
printf("il y a une erreur fichier\n");
fclose(fichier);
}
*/
/**
*  @brief  pour generer l enigme
*  @param e l enigme
*  @param nomfichier le nom du fichier
*  @param nomfichier1 le nom du fichier
*  @return Nothing
*/
void genererEnigmee(enigmeimage *e,char nomfichier[],char nomfichier1[])
{
int y,x,w,z;
int existe=0;
int existe1=0;
char s[50],s1[50],s2[50],s3[50],ch[50]="",ch1[50]="",ch2[50]="",ch3[50]="";
FILE* fichier2=NULL;
FILE* fichier3=NULL;
srand(time(NULL));
x=(rand()%5)+1;
fichier2=fopen(nomfichier,"r");
if(fichier2!=NULL)
{
while((fscanf(fichier2,"%d  %s %d\n",&w,s,&y)!=EOF) && (existe==0))
{
if(x==w)
{
sprintf(ch,"img/%s",s);
e->reponse_correcte=y;
existe=1;
}
}
}
else 
printf("il y a une erreur 1 \n");
fclose(fichier2);
e->img=IMG_Load(ch);
fichier3=fopen(nomfichier1,"r");
if(fichier3!=NULL)
{
while((fscanf(fichier3,"%d %s %s %s\n",&z,s1,s2,s3)!=EOF) && (existe1==0))
{
if(x==z)
{
sprintf(ch1,"img/%s",s1);
sprintf(ch2,"img/%s",s2);
sprintf(ch3,"img/%s",s3);
existe1=1;
}
}
}
else 
printf("il y a une erreur 1 \n");
fclose(fichier3);
e->reponse1=IMG_Load(ch1);
e->reponse2=IMG_Load(ch2);
e->reponse3=IMG_Load(ch3);
}
/**
*  @brief  pour afficher l enigme
*  @param e l enigme
*  @param screen the screen 
*  @return Nothing
*/
void afficherEnigmee(SDL_Surface * screen ,enigmeimage *e)
{
SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;
SDL_BlitSurface(e->reponse1,NULL,screen,&(e->p1)) ;
SDL_BlitSurface(e->reponse2,NULL,screen,&(e->p2)) ;
SDL_BlitSurface(e->reponse3,NULL,screen,&(e->p3)) ;
SDL_BlitSurface(e->anim[e->num],NULL,screen,&e->posanim);
if(e->num == 6)
{
//SDL_BlitSurface(e->anim[0],NULL,screen,&e->posanim);
e->num = 0;
}
else
{
e->num=e->num+1;
}
SDL_Flip(screen);
SDL_Delay(300);
}
/**
*  @brief  pour choisir une des reponses de l enigme
*  @param e l enigme
*  @param screen the screen 
*  @param run entier definissant l etat du prog
*  @return Nothing
*/
void choisir(enigmeimage *e, SDL_Surface* screen,int *run)
{                                               
	SDL_Event event ;
	while (SDL_PollEvent(&event)){//a migrg dans getinput   ---> input
	switch(event.type)
	{
		 //case SDL_QUIT:
                //*run=0;
                //break ;

       case SDL_KEYDOWN :{ 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  e->reponse_choisie= 1;//maj de la structure input
			   break ;
			   case  SDLK_b:
			   e->reponse_choisie= 2;
			   break;
			  case SDLK_c: 
			   e->reponse_choisie=3 ;
			  break;
			  //case SDLK_d: 
			   //*run=0; ;
			  //break;
			    }
       break;}

                 
	}
	}
}
/**
*  @brief  pour afficger le resultat
*  @param screen the screen 
*  @param e l enigme
*  @return Nothing
*/
void afficher_resultat (SDL_Surface * screen,enigmeimage *e)
 {
 
 	if (  e->reponse_choisie==e->reponse_correcte)
       {   e->correct=IMG_Load("img/right.png");        
 	   SDL_BlitSurface(e->correct, NULL, screen, &(e->pos_c));
 	   SDL_Flip(screen);
       }
 	else
       {  e->wrong=IMG_Load("img/wrong.png");              
          SDL_BlitSurface(e->wrong, NULL, screen, &(e->pos_w)) ;
          SDL_Flip(screen);
        }
           SDL_Delay(2000);
 }
 /**
*  @brief  pour liberer la surface
*  @param e l enigme
*  @return Nothing
*/
void Free(enigmeimage *e)
{   SDL_FreeSurface(e->img);
    SDL_FreeSurface(e->reponse1);
    SDL_FreeSurface(e->reponse2);
    SDL_FreeSurface(e->reponse3);
    SDL_FreeSurface(e->correct);
    SDL_FreeSurface(e->wrong);
    SDL_FreeSurface(e->anim[e->num]);
}
void init_choix(choix *c)
{
	c->p.x=0;
	c->p.y=0;	
	c->img=IMG_Load("img/turki2.png");
	c->reponse_choisie=0;
}

void  generate_afficher (SDL_Surface * screen,choix *c)
{
SDL_BlitSurface(c->img,NULL,screen,&(c->p)) ;
SDL_Flip(screen);
}

void choisirchoix(choix *c,int *run)
{                                               
	SDL_Event event ;
	while (SDL_PollEvent(&event)){//a migrg dans getinput   ---> input
	switch(event.type)
	{
		 case SDL_QUIT:
                *run=0;
                break ;

       case SDL_KEYDOWN :{ 
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  c->reponse_choisie= 1;//maj de la structure input
			   break ;
			   case  SDLK_b:
			   c->reponse_choisie= 2;
			   break;
			  case SDLK_d: 
			   *run=0; 
			  break;
			    }
       break;}

                 
	}
	}
}
void Freechoix(choix *c)
{
SDL_FreeSurface(c->img);
}
