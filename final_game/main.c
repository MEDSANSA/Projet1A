#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "minimap.h"
#include "perso.h"
#include "enigme.h"
#include "entity.h"
#include "ennemie.h"
#include "enigmeimage.h"
#include "arduino.h"

int main(int argc, char *argv[])
{

    SDL_Surface *ecran = NULL, *imageDeFond = NULL,*optionbackground=NULL,*play1[2],*play2[2],*options1[2],*quit1[2],*back[2],*texte=NULL;
    SDL_Surface *imageDeFond2 = NULL;
    Mix_Music *son;
    Mix_Chunk *clic;
    int continuer = 1;
    int i,settingg,playy,playy2=1;
    float vol=120;

    SDL_Init(SDL_INIT_EVERYTHING);// Initialisation de la SDL

    SDL_Rect positionFond,positionplay1,positionoptions1,positionscoreboard1,positionquit1,positiontexte,positionClic,positionoptionbackground;
    SDL_Rect positionplay2;
    SDL_Event event,event1,event2,event3;

    //load des button

    play1[1]=IMG_Load("menu/single2.png");
    play1[2]=IMG_Load("menu/single1.png");

    play2[1]=IMG_Load("menu/multi2.png");
    play2[2]=IMG_Load("menu/multi1.png");

    options1[1] = IMG_Load("menu/optionoff.png");
    options1[2]= IMG_Load("menu/optionon.png");

    quit1[1] = IMG_Load("menu/exitoff.png");
    quit1[2] = IMG_Load("menu/exiton.png");

    SDL_Surface *plus=IMG_Load("menu/plus.png");
    SDL_Surface *moins=IMG_Load("menu/moins.png");
    SDL_Surface *volm=IMG_Load("menu/volume.png");
    SDL_Surface *resolution=IMG_Load("menu/resolution.png");
    SDL_Surface *retour=IMG_Load("menu/retour.png");
    SDL_Surface *res1=IMG_Load("menu/1.png");
    SDL_Surface *res2=IMG_Load("menu/2.png");
    SDL_Surface *meilleur=IMG_Load("menu/score.png");

    // Chargement des images de background
    imageDeFond = IMG_Load("menu/backg.png");
    imageDeFond2 = IMG_Load("menu/800600.png");
    optionbackground=IMG_Load("menu/backop.png");

    //position des button

    positionFond.x = 0;
    positionFond.y = 0;

    positionoptionbackground.x=0;
    positionoptionbackground.y=0;

    positiontexte.x=1000;
    positiontexte.y=30;

    positionplay1.x=175;
    positionplay1.y=275;

    positionplay2.x=175;
    positionplay2.y=375;

    positionoptions1.x=175;
    positionoptions1.y=475;

    positionquit1.x=175;
    positionquit1.y=575;

    SDL_Rect posPlus;
    posPlus.x = 800;
    posPlus.y = 250;

    SDL_Rect posMoins;
    posMoins.x = 505;
    posMoins.y = 250;

    SDL_Rect posvolm;
    posvolm.x=513;
    posvolm.y=180;

    SDL_Rect posresolution;
    posresolution.x=515;
    posresolution.y=300;

    SDL_Rect posretour;
    posretour.x=930;
    posretour.y=100;

    SDL_Rect posres1;
    posres1.x=550;
    posres1.y=360;

    SDL_Rect posres2;
    posres2.x=550;
    posres2.y=460;

    SDL_Rect posscore;
    posscore.x=550;
    posscore.y=550;

    TTF_Font *police = NULL;

    SDL_Color couleurnoire = {0, 0, 0};

    //initialisation police
    TTF_Init();
    //Chargement de la police
    police = TTF_OpenFont("menu/Bubble Mint.ttf",50);

    // Écriture du texte dans la SDL_Surface
    texte = TTF_RenderText_Blended(police, "Enjoy Our game", couleurnoire);

    ecran = SDL_SetVideoMode(1366, 678, 32, SDL_HWSURFACE);

    //nom du jeu
    SDL_WM_SetCaption("salah and the desert's treasure", NULL);

    //Initialisation Son
    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)== -1)
    {
        printf("%s",Mix_GetError());
    }

    Mix_Music *musique;
    vol=MIX_MAX_VOLUME;
    Mix_VolumeMusic(vol);
    musique=Mix_LoadMUS("menu/music.mp3");//Chargement de musique
    Mix_PlayMusic(musique,-1);//play de music

    //initialisation de volume
    Mix_VolumeMusic(vol);

    //Chargement de son bref
    clic = Mix_LoadWAV("menu/souris.wav");

    //background variable
    background b;
    int collision;
    personnage pe,pe2;


    //minimap variable
    map m;
    Time temps;
    int score;
    int longueurM=8000,largeurM=800,longueur=800,largeur=80,distance=160;
    int redimensionnement=distance * longueur / longueurM;

    //enigme variable
    enigme e;

    //entite variable
    entity ent;
    Ennemie en;
    // enigme image variable
    enigmeimage ei;
    int runner=1;
    choix c;

//initialisation
    initBack(&b);
    initminimap(&m,ecran);
    inittemps(&temps);
    initialiserperso(&pe);
    initialiserperso2(&pe2);
    init_enigme(&e);
    initentity (&ent) ;
    initEnnemi (&en) ;
    init_enigmee(&ei);
    genererEnigmee(&ei,"fichier.txt","fichier1.txt"); 
    init_choix(&c);

    while (continuer)
    {
        SDL_WaitEvent(&event);// badel b pollevent
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE: // Appui sur la touche Echap quiiter le jeux
                continuer = 0;
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
//quit
            Mix_PlayChannel(1, clic, 0);
            if(event.button.x >= positionquit1.x && event.button.x <= (positionquit1.x + 278) && event.button.y >= positionquit1.y && event.button.y <= positionquit1.y+87)
            {
                Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic
                continuer = 0;
            }
//option
            else if(event.button.x >= positionoptions1.x && event.button.x <= (positionoptions1.x + 278) && event.button.y >= positionoptions1.y && event.button.y <= positionoptions1.y+87)
            {
                Mix_PlayChannel(1, clic, 0); //Jouer une petite musique lors du clic

                SDL_BlitSurface(optionbackground,NULL,ecran,&positionoptionbackground);
                SDL_BlitSurface(plus,NULL, ecran,&posPlus);
                SDL_BlitSurface(moins,NULL, ecran,&posMoins);
                SDL_BlitSurface(volm,NULL, ecran,&posvolm);
                SDL_BlitSurface(resolution,NULL, ecran,&posresolution);
                SDL_BlitSurface(retour,NULL, ecran,&posretour);
                SDL_BlitSurface(res1,NULL, ecran,&posres1);
                SDL_BlitSurface(res2,NULL, ecran,&posres2);
                SDL_BlitSurface(meilleur,NULL, ecran,&posscore);
//settings
                settingg=1;
                while (settingg==1)
                {
                    SDL_WaitEvent(&event2);
                    switch(event2.type)
                    {
                    case SDL_MOUSEBUTTONDOWN:
                        if (event2.button.button == SDL_BUTTON_LEFT)
                        {
                            //click on retour
                            if(event2.button.x>930 && event2.button.x<980 && event2.button.y>100 && event2.button.y<150 )
                            {
                                settingg=0;
                            }
                            //click on plus
                            if(event2.button.x>800 && event2.button.x<850 && event2.button.y>250 && event2.button.y<300 )
                            {
                                if((vol)<120)
                                {
                                    (vol)+=20;
                                }
                                Mix_VolumeMusic(vol);
                                printf("%f\n",vol);
                            }
                            //click on moins
                            if(event2.button.x>500 && event2.button.x<550 && event2.button.y>250 && event2.button.y<300 )
                            {
                                if((vol)>=20)
                                {
                                    (vol)-=20;
                                }
                                Mix_VolumeMusic(vol);
                                printf("%f\n",vol);
                            }
                            //resolution
                            if(event2.button.x>550 && event2.button.x<795 && event2.button.y>400 && event2.button.y<475 )
                            {
                                ecran = SDL_SetVideoMode(800, 600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
                                SDL_BlitSurface(imageDeFond2, NULL, ecran, &positionFond);
                                SDL_FreeSurface(imageDeFond2);
                            }
                            if(event2.button.x>550 && event2.button.x<795 && event2.button.y>550 && event2.button.y<625 )
                            {
                                affichermscore(score,ecran);
                            }
                        }
                        break;
                    case SDL_KEYDOWN:
                        printf("%f\n",vol);
                        switch(event2.key.keysym.sym)
                        {
                        case SDLK_UP:

                            if((vol)<120)
                            {
                                (vol)+=20;
                            }
                            Mix_VolumeMusic(vol);
                            break;
                        case SDLK_DOWN:
                            if((vol)>=20)
                            {
                                (vol)-=20;
                            }
                            Mix_VolumeMusic(vol);
                            break;
                        case SDLK_ESCAPE:
                            settingg=0;
                            break;
                        }
                        break;
                    }
                    SDL_Flip(ecran);
                }
            }
//play button
            else if(event.button.x >= positionplay1.x && event.button.x <= (positionplay1.x + 278) && event.button.y >= positionplay1.y && event.button.y <= positionplay1.y+87)
            {
                //Jouer une petite musique lors du clic
                Mix_PlayChannel(1, clic, 0);

                char nom[50];
                printf("saisir votre nom:\n");
                scanf("%s",nom);
                save_nom (nom);

                SDL_EnableKeyRepeat(10,10);


                playy=1;
                int enigme=1;
                int runninge=1;
                
                while(runninge)
                {   
                    generate_afficher(ecran,&c);
                    choisirchoix(&c,&runninge);
                    if (c.reponse_choisie==1)
                    {
                        while (playy==1)
                        {   
                            afficheBack(b,ecran);
                            afficherminimap(m,ecran);
                            animerbackground(&b,ecran);
                            afficher_perso(ecran,pe);
                            afficherentity(ent,ecran);
                            afficherEnnemi (en,ecran);
                            update_time(&temps);
                            displaytime(temps,ecran);
                            update_entity(&ent);
                            update_ennemie (&en,&pe);

                            if(SDL_PollEvent(&event1))
                            {
                                switch(event1.type)
                                {
                                case SDL_QUIT:
                                    playy = 0;
                                    break;
                                case SDL_KEYDOWN:
                                    switch(event1.key.keysym.sym)
                                    {
                                    case SDLK_ESCAPE:
                                        playy=0;
                                        break;

                                    case SDLK_RIGHT:
                                        scrolling(&b,0);
                                        break;
                                    case SDLK_LEFT:
                                        scrolling(&b,1);
                                        break;
                                    case SDLK_UP:
                                        scrolling(&b,2);
                                        break;
                                    case SDLK_DOWN:
                                        scrolling(&b,3);
                                        break;
                                    }
                                    break;
                                }
                            }
                            if(collisionpp(b.imgbackm,pe)==1)
                            {
                                printf("collision \n");
                            }

                            if(detect_collision(&pe,&ent))
                            {
                                gestion(&ent);
                            }

                            if (detect_collision_ennemie(&pe,&en))
                            {
                                while(runner)
                                {
                                    afficherEnigmee(ecran,&ei);
                                    choisir(&ei,ecran,&runner);
                                    if (ei.reponse_choisie!=-1)
                                    {
                                        afficher_resultat (ecran,&ei);
                                        runner=0;
                                    }
                                }
                                if (ei.reponse_choisie==ei.reponse_correcte)
                                {
                                    gerer(&en);
                                }
                                else
                                {
                                    playy=0;
                                }
                            }

                            if(pe.pos_perso.x==1195)
                            {
                                afficher_enigme(&e,ecran);
                                //save_score(score);
                                while (SDL_PollEvent(&event1))
                                {
                                    switch (event1.type)
                                    {
                                    //position click souris
                                    case SDL_MOUSEBUTTONUP:
                                    {
                                        //selection de reponse 1
                                        if((event1.motion.x>400 && event1.motion.x<600)&&(event1.motion.y>300 && event1.motion.y<360))
                                        {
                                            e.pos_selected=1;
                                            if (event1.button.button == SDL_BUTTON_LEFT)
                                            {
                                                //play de son click
                                                Mix_PlayChannel(2,e.sound,0);
                                                //verification de l'enigme
                                                verify_enigme(&e,ecran);
                                            }
                                        }
                                        //selection de reponse 2
                                        else if((event1.motion.x>650 && event1.motion.x<850)&&(event1.motion.y>300 && event1.motion.y<360))
                                        {
                                            e.pos_selected=2;
                                            if (event1.button.button == SDL_BUTTON_LEFT)
                                            {
                                                //play de son click
                                                Mix_PlayChannel(2,e.sound,0);
                                                //verification de l'enigme
                                                verify_enigme(&e,ecran);
                                            }
                                        }
                                        //selection de reponse 3
                                        else if((event1.motion.x>520 && event1.motion.x<720)&&(event1.motion.y>400 && event1.motion.y<460))
                                        {
                                            e.pos_selected=3;
                                            if (event1.button.button == SDL_BUTTON_LEFT)
                                            {
                                                //play de son click
                                                Mix_PlayChannel(2,e.sound,0);
                                                //verification de l'enigme
                                                verify_enigme(&e,ecran);
                                            }
                                        }
                                    }
                                    break;
                                    }
                                }
                            }
                            deplacer_perso(&pe,event1);
                            MAJminimap(pe,&m,b.camera,redimensionnement);
                            SDL_Flip(ecran);
                        }
                        runninge=0;
                    }

                    else if (c.reponse_choisie==2)
                    {      
                        //loadperso2
                        while (playy==1)
                        {
                            afficheBack(b,ecran);
                            afficherminimap(m,ecran);
                            animerbackground(&b,ecran);
                            afficher_perso(ecran,pe2);
                            afficherentity(ent,ecran);
                            afficherEnnemi (en,ecran);
                            update_time(&temps);
                            displaytime(temps,ecran);
                            update_entity(&ent);
                            update_ennemie (&en,&pe2);

                            if(SDL_PollEvent(&event1))
                            {
                                switch(event1.type)
                                {
                                case SDL_QUIT:
                                    playy = 0;
                                    break;
                                case SDL_KEYDOWN:
                                    switch(event1.key.keysym.sym)
                                    {
                                    case SDLK_ESCAPE:
                                        playy=0;
                                        break;

                                    case SDLK_d:
                                        scrolling(&b,0);
                                        break;
                                    case SDLK_q:
                                        scrolling(&b,1);
                                        break;
                                    case SDLK_z:
                                        scrolling(&b,2);
                                        break;
                                    case SDLK_s:
                                        scrolling(&b,3);
                                        break;
                                    }
                                    break;
                                }
                            }
                            if(collisionpp(b.imgbackm,pe2)==1)
                            {
                                printf("collision \n");
                            }

                            if(detect_collision(&pe2,&ent))
                            {
                                gestion(&ent);
                            }

                            if (detect_collision_ennemie(&pe2,&en))
                            {
                                while(runner)
                                {
                                    afficherEnigmee(ecran,&ei);
                                    choisir(&ei,ecran,&runner);
                                    if (ei.reponse_choisie!=-1)
                                    {
                                        afficher_resultat (ecran,&ei);
                                        runner=0;
                                    }
                                }
                                if (ei.reponse_choisie==ei.reponse_correcte)
                                {
                                    gerer(&en);
                                }
                                else
                                {
                                    playy=0;
                                }
                            }

                            if(pe2.pos_perso.x==1195)
                            {
                                afficher_enigme(&e,ecran);
                                save_score(score);
                                while (SDL_PollEvent(&event1))
                                {
                                    switch (event1.type)
                                    {
                                    //position click souris
                                    case SDL_MOUSEBUTTONUP:
                                    {
                                        //selection de reponse 1
                                        if((event1.motion.x>400 && event1.motion.x<600)&&(event1.motion.y>300 && event1.motion.y<360))
                                        {
                                            e.pos_selected=1;
                                            if (event1.button.button == SDL_BUTTON_LEFT)
                                            {
                                                //play de son click
                                                Mix_PlayChannel(2,e.sound,0);
                                                //verification de l'enigme
                                                verify_enigme(&e,ecran);
                                                return 0;

                                            }
                                        }
                                        //selection de reponse 2
                                        else if((event1.motion.x>650 && event1.motion.x<850)&&(event1.motion.y>300 && event1.motion.y<360))
                                        {
                                            e.pos_selected=2;
                                            if (event1.button.button == SDL_BUTTON_LEFT)
                                            {
                                                //play de son click
                                                Mix_PlayChannel(2,e.sound,0);
                                                //verification de l'enigme
                                                verify_enigme(&e,ecran);
                                                return 0;
                                            }
                                        }
                                        //selection de reponse 3
                                        else if((event1.motion.x>520 && event1.motion.x<720)&&(event1.motion.y>400 && event1.motion.y<460))
                                        {
                                            e.pos_selected=3;
                                            if (event1.button.button == SDL_BUTTON_LEFT)
                                            {
                                                //play de son click
                                                Mix_PlayChannel(2,e.sound,0);
                                                //verification de l'enigme
                                                verify_enigme(&e,ecran);
                                                return 0;
                                            }
                                        }
                                    }
                                    break;
                                    }
                                }
                            }
                            deplacer_perso2(&pe2,event1);
                            MAJminimap(pe2,&m,b.camera,redimensionnement);
                            SDL_Flip(ecran);
                        }

                        runninge=0;

                    }
                }
            }

//multiplayer
            else if(event.button.x >= positionplay2.x && event.button.x <= (positionplay2.x + 278) && event.button.y >= positionplay2.y && event.button.y <= positionplay2.y+87)
            {
                //Jouer une petite musique lors du clic
                Mix_PlayChannel(1, clic, 0);

                SDL_EnableKeyRepeat(10,10);

                initBack(&b);
                initBack1(&b);

                while (playy2)
                {
                    afficheBack(b,ecran);
                    afficheBack1(b,ecran);

                    while (SDL_PollEvent(&event3))
                    {
                        switch(event3.type)
                        {
                        case SDL_QUIT:
                            playy2 = 0;
                            break;
                        case SDL_KEYDOWN:
                            switch(event3.key.keysym.sym)
                            {
                            case SDLK_d:
                                scrolling(&b,0);//d
                                break;
                            case SDLK_q:
                                scrolling(&b,1);//q
                                break;
                            case SDLK_z:
                                scrolling(&b,2);//z
                                break;
                            case SDLK_s:
                                scrolling(&b,3);//s
                                break;
                            case SDLK_RIGHT:
                                scrolling(&b,4);//right
                                break;
                            case SDLK_LEFT:
                                scrolling(&b,5);//left
                                break;
                            case SDLK_UP:
                                scrolling(&b,6);//up
                                break;
                            case SDLK_DOWN:
                                scrolling(&b,7);//down
                                break;
                            }
                            break;
                        }
                    }
                    SDL_Flip(ecran);
                }
            }
            break;
//quit button
        case SDL_MOUSEMOTION:
            if(event.motion.x >= positionquit1.x && event.motion.x <= (positionquit1.x + 278) && event.motion.y >= positionquit1.y && event.motion.y <= positionquit1.y+87)
            {
                //SDL_SetColorKey(quit1[2], SDL_SRCCOLORKEY, SDL_MapRGB(quit1[2]->format, 0, 0, 0));
                //SDL_BlitSurface(quit1[2],NULL,ecran,&positionquit1);
            }
//option button
            else if(event.motion.x >= positionoptions1.x && event.motion.x <= (positionoptions1.x + 278) && event.motion.y >= positionoptions1.y && event.motion.y <= positionoptions1.y+87)
            {
                SDL_SetColorKey(options1[2], SDL_SRCCOLORKEY, SDL_MapRGB(options1[2]->format, 0, 0, 0));
                SDL_BlitSurface(options1[2], NULL, ecran, &positionoptions1);
            }
//play button
            else if(event.motion.x >= positionplay1.x && event.motion.x <= (positionplay1.x + 278) && event.motion.y >= positionplay1.y && event.motion.y <= positionplay1.y+87)
            {
                SDL_SetColorKey(play1[2], SDL_SRCCOLORKEY, SDL_MapRGB(play1[2]->format, 0, 0, 0));
                SDL_BlitSurface(play1[2],NULL,ecran,&positionplay1);
            }
            else if(event.motion.x >= positionplay2.x && event.motion.x <= (positionplay2.x + 278) && event.motion.y >= positionplay2.y && event.motion.y <= positionplay2.y+87)
            {
                SDL_SetColorKey(play2[2], SDL_SRCCOLORKEY, SDL_MapRGB(play2[2]->format, 0, 0, 0));
                SDL_BlitSurface(play2[2],NULL,ecran,&positionplay2);
            }
//default
            else
            {
                SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                SDL_BlitSurface(texte, NULL, ecran, &positiontexte); /* Blit du texte */
                SDL_SetColorKey(play1[1], SDL_SRCCOLORKEY, SDL_MapRGB(play1[1]->format, 0, 0, 0));
                SDL_BlitSurface(play1[1], NULL, ecran, &positionplay1);
                SDL_SetColorKey(play2[1], SDL_SRCCOLORKEY, SDL_MapRGB(play2[1]->format, 0, 0, 0));
                SDL_BlitSurface(play2[1], NULL, ecran, &positionplay2);
                SDL_SetColorKey(options1[1], SDL_SRCCOLORKEY, SDL_MapRGB(options1[1]->format, 0, 0, 0));
                SDL_BlitSurface(options1[1], NULL, ecran, &positionoptions1);
                SDL_SetColorKey(quit1[1], SDL_SRCCOLORKEY, SDL_MapRGB(quit1[1]->format, 0, 0, 0));
                SDL_BlitSurface(quit1[1], NULL, ecran, &positionquit1);
            }
            break;
        }
        SDL_Flip(ecran);
    }

//liberation
    liberer(temps,m);
    lib(b);
    free_enigme(&e);
    free_perso(pe);
    Free(&ei);

    SDL_FreeSurface(play1[1]);
    SDL_FreeSurface(play1[2]);
    SDL_FreeSurface(play2[1]);
    SDL_FreeSurface(play2[2]);
    SDL_FreeSurface(options1[1]);
    SDL_FreeSurface(options1[2]);
    SDL_FreeSurface(quit1[1]);
    SDL_FreeSurface(quit1[2]);
    SDL_FreeSurface(plus);
    SDL_FreeSurface(moins);
    SDL_FreeSurface(volm);
    SDL_FreeSurface(resolution);
    SDL_FreeSurface(retour);
    SDL_FreeSurface(res1);
    SDL_FreeSurface(res2);
    SDL_FreeSurface(meilleur);
    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(imageDeFond2);
    SDL_FreeSurface(optionbackground);
    SDL_FreeSurface(ecran);
    TTF_CloseFont(police);
    Mix_FreeMusic(son);
    Mix_FreeChunk(clic);
    SDL_FreeSurface(texte);
    Mix_Quit();
    TTF_Quit();
    Mix_CloseAudio();
    SDL_Quit();

    return EXIT_SUCCESS;
}

	

