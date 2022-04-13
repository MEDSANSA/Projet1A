#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "perso.h"

int main (void)
{

    int continuer=1,collision;
    background b;
    personnage p;
    SDL_Surface *ecran=NULL;
    SDL_Event event;
    SDL_Init(SDL_INIT_EVERYTHING);
    ecran= SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

//Initialisation de l'API Mixer
    if(Mix_OpenAudio(1366, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 678) == -1)
    {
        printf("%s", Mix_GetError());
    }

//nom du jeux
    SDL_WM_SetCaption("salah and the desert's treasure",NULL);

//Enables or disables the keyboard repeat rate
//delay specifies how long the key must be pressed before it begins repeating, it then repeats at the speed specified by interval
    SDL_EnableKeyRepeat(10,10);

    initBack(&b);
    initialiserperso(&p);
	
    while (continuer)
    {
    
    afficheBack(b,ecran);
    afficher_perso(ecran,p);
    animerbackground(&b,ecran);
    
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {

            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
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
        if(collisionpp(b.imgbackm,p)==1)
        {
               printf("collision \n");
        }
        deplacer_perso(&p,event);
        SDL_Flip(ecran);
    }
    Mix_CloseAudio();
    liberer(b);
    free_perso(p);
    SDL_Quit();
    return EXIT_SUCCESS;
}

