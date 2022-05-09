#include "enigme.h"

void init_enigme(enigme *e){
	//numero de question a selectionner
	e->pos_selected=0;
	//background de l'nigme
	e->background= IMG_Load("img/background.png");
	//button de reponse
	e->button=IMG_Load("img/button.png");
	e->button_s=IMG_Load("img/button_s.png");
	
	TTF_Init();
	//initialisation de police a utuliser
	TTF_Font *police = NULL,*police1=NULL;
	//initialisation de couleur a utuliser
	SDL_Color couleur = {0,0,0};
	//police
	police = TTF_OpenFont("img/arial.ttf", 20);
	police1 = TTF_OpenFont("img/arial.ttf", 15);
	//initialisation de texte a afficher
	SDL_Surface *texte;
	//initialisation de lanimation
	e->posanim.x=560;
	e->posanim.y=500;
	e->num=0;
	e->anim[0]=IMG_Load("img/sab.png");
	e->anim[1]=IMG_Load("img/sab1.png");
	e->anim[2]=IMG_Load("img/sab2.png");
	e->anim[3]=IMG_Load("img/sab3.png");
	e->anim[4]=IMG_Load("img/sab4.png");
	e->anim[5]=IMG_Load("img/sab5.png");
	e->anim[6]=IMG_Load("img/sab6.png");
/* ------------------------------------------------------------------------------------*/
	//chaine bech nkhabiw fiha el question
	char questionn[50];

	srand(time(NULL));
	//selection d'un question aleatoire
	e->num_question=rand()%3;
	//ken souel taadech iaawed iloadi wehed ekher
	while(e->num_question==0){
		srand(time(NULL));
		e->num_question=rand()%3;
	}
	//fichier des question
	FILE *fquestion=NULL;
	//ouverture de fichier
	fquestion=fopen("questions.txt","r+");
	//test ala numero el qustion kenou egale lel question nekhdhouh snn n9admou
	if(fquestion!=NULL){
		int test=1;
		while (fgets(questionn,50,fquestion)&&(test!=e->num_question)){
			test++;
		}
		fclose(fquestion);
	}
	//chaine fiha el reponse
	char reponse[30];

	int min,max;
	//numero el reponse fel fichier hasb el question
    switch(e->num_question)
    {
    	case 1:
    		min=0;
    		max=2;
    		break;
    	case 2:
    		min=3;
    		max=5;
    		break;
    	case 3:
    		min=6;
    		max=8;
    		break;
    }
	//ouverture de fichier de reponse
	FILE *freponse=NULL;
	freponse=fopen("reponses.txt","r+");
	//test de reponse
	if(freponse!=NULL){
		int test=0;
		while (fgets((reponse),30,freponse)&&(test<max)){//parcour
			if(test>=min){
				//reponse elli bech yafichiha
				e->reponses[test-min]=TTF_RenderText_Blended(police1,reponse,couleur);//3ibara 7ahert el police wel couleur bech nafichi bihom el reponse baed
			}
			test++;
		}	
		fclose(freponse);
	}

	//ouverture de fichier bon reponse
	FILE *fvraireponse=NULL;
	fvraireponse=fopen("vraireponses.txt","r+");
	//test de bon reponse
	if(fvraireponse!=NULL){
		int test=1;
		while (fgets((reponse),30, fvraireponse)){
			if(test==e->num_question){
				//affichage de bon reponse dans le console
				printf("%s\n",reponse);
				//tekhou el bon reponse mta3 el question
				e->reponses[2]=TTF_RenderText_Blended(police1,reponse,couleur);
			}
			test++;
		}
		fclose(freponse);
	}

	srand(time(NULL));
	e->positionVraiReponse=rand()%3;
	//tthabet fi numero el reponse eshiha
	while(e->positionVraiReponse==0){
		srand(time(NULL));
		e->positionVraiReponse=rand()%3;
	}
	//afficher dans le console numero de reponse vrai
	printf("%d\n",e->positionVraiReponse);
/* ------------------------------------------------------------------------------------------------------------------*/
	//initialisation de question a afficher
	e->question = TTF_RenderText_Blended(police, questionn, couleur);

	//position de question
	e->pos_question.x=440;
	e->pos_question.y=150;
	//position de button de reponse 1
	e->pos_reponse1.x=400;
	e->pos_reponse1.y=300;
	//position de button de reponse 2
	e->pos_reponse2.x=650;
	e->pos_reponse2.y=300;
	//position de button de reponse 3
	e->pos_reponse3.x=520;
	e->pos_reponse3.y=400;
	//position de texte de reponse 1
	e->pos_reponse1txt.x=430;
	e->pos_reponse1txt.y=320;
	//position de texte de reponse 2
	e->pos_reponse2txt.x=680;
	e->pos_reponse2txt.y=320;
	//position de texte de reponse 3
	e->pos_reponse3txt.x=550;
	e->pos_reponse3txt.y=420;
	
	//initialisation de son pour click
	Mix_AllocateChannels(20);
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){

	}
	//load de son click
	e->sound=Mix_LoadWAV("img/clic.wav");
	//initialisation de volume
	Mix_VolumeMusic(MIX_MAX_VOLUME);

}

void afficher_enigme(enigme *e,SDL_Surface *ecran){
	//affichage de background
	SDL_Rect pos;
	pos.x=350;
	pos.y=100;
	SDL_BlitSurface(e->background, NULL, ecran,&pos);
	SDL_Flip(ecran);
	//affichage de question
	SDL_BlitSurface(e->question, NULL, ecran, &e->pos_question);
	SDL_Flip(ecran);
	//animation
	if(e->num == 6)
    	{
        e->num = 0;
    	}
    	else
    	{
        e->num++;
    	}

    SDL_BlitSurface(e->anim[e->num],NULL,ecran,&e->posanim);
	//position el reponse eshiha hasb el souel
	switch(e->positionVraiReponse){
		//question 1
		case 1:{
			//numero el case howwa numero el reponse elli selectionnitha
			switch(e->pos_selected){
			case 1:
			{
				//affichage des button
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				//affichage des button
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				//affichage des button
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				//affichage des button
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
			}
						}	
			break;
			}	
		//question 2
		case 2:{
			switch(e->pos_selected){
			case 1:
			{
				//affichage des button
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				//affichage des button
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				//affichage des button
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				//affichage des button
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}
			break;
		}
		//question 3
		case 3:{
			switch(e->pos_selected){
			case 1:
			{
				//affichage des button
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);

			}
			break;
			case 2:
			{
				//affichage des button
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
			
			}
			break;
			case 3:
			{
				//affichage des button
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button_s, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
	
			}
			break;
			default:
			{
				//affichage des button
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse1);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse2);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->button, NULL, ecran, &e->pos_reponse3);
				SDL_Flip(ecran);
				//affichage du texte
				SDL_BlitSurface(e->reponses[0], NULL, ecran, &e->pos_reponse1txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[1], NULL, ecran, &e->pos_reponse2txt);
				SDL_Flip(ecran);
				SDL_BlitSurface(e->reponses[2], NULL, ecran, &e->pos_reponse3txt);
				SDL_Flip(ecran);
				}
			}

			break;
		}
	}
	SDL_Delay(100);
}

void verify_enigme(enigme *e,SDL_Surface *ecran)
{
	//position daffichage de reponse
	SDL_Rect pos={430,300};
	//ken el reponse shiha yaffichi win
	if(e->positionVraiReponse==e->pos_selected)
	{
		SDL_Surface *win;
		win=IMG_Load("img/youwin.png");
		SDL_BlitSurface(win, NULL, ecran,&pos);
		SDL_Flip(ecran);
	}
	//ken el reponse ghalta yaffichi lost
	else
	{
		SDL_Surface *lost;
		lost=IMG_Load("img/youlost.png");
		SDL_BlitSurface(lost, NULL, ecran, &pos);
		SDL_Flip(ecran);
	}
	SDL_Delay(2000);
}

void free_enigme(enigme *e){
	//liberation
	SDL_FreeSurface(e->background);
	SDL_FreeSurface(e->question);
	SDL_FreeSurface(e->reponses[0]);
	SDL_FreeSurface(e->reponses[1]);
	SDL_FreeSurface(e->reponses[2]);
	SDL_FreeSurface(e->button);
	SDL_FreeSurface(e->button_s);
}

/*
 //hedhy fel validation ejjeya 
void SaveGame(personne p)
	{
		FILE *f;
		f=fopen("savegame.txt","w");
			//bech ikhabi fel fichier position el joueur ekher marra saker el jeux
			fprintf(f," %d %d \n ",(p.pos->x),(p.pos->y));
		fclose(f);
	}

void loadGame(personne *p)
{
	FILE *f;
		f=fopen("savegame.txt","r");

		if (f != NULL)
		{
			//iloadi ekher marar el joueur win ken we9ef
			fscanf(f," %hu %hu ",&(p->pos->x),&(p->pos->y));
		}
		else 
		{
			//snn yekhou position hedhy
			p->pos->x=60;
			p->pos->y=540;
		}
		fclose(f);
}
*/

