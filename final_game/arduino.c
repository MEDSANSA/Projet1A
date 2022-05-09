#include <stdio.h>
#include <stdlib.h>
#include "arduino.h"

int arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyS0";
    FILE*f;

    f=fopen(chemin,"w");
    if(f == NULL)
        return(-1);

    fprintf(f,"%d",x);
    fclose(f);

    return(0);
}

int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyS0";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}

void arduino_update(buttonArduino b,background *bk,personnage *p)
{
int speed=6;
	/*Pour les directions:
	  buttonArduino.dir = 0: Avance (a droit)
	  buttonArduino.dir = 1: Retourne(a gauche)*/

	if(b.dir == 0)//Button droit active
	{
	bk->camera.x+=speed;
	p->pos_perso.x=p->pos_perso.x+5;
	}
	if(b.dir == 1)//Button gauche active
	{
	bk->camera.x-=speed;
	p->pos_perso.x=p->pos_perso.x-5;
	}
}
