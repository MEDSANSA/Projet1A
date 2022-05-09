#ifndef ARDUINO_H_INCLUDED
#define ARDUINO_H_INCLUDED
#include "background.h"
#include "perso.h"

typedef struct 
{
	int dir;
}buttonArduino;

int arduinoWriteData(int x);
int arduinoReadData(int *x);
void arduino_update(buttonArduino b,background *bk,personnage *p);

#endif
