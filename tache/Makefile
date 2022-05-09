prog:background.o main.o perso.o
	gcc main.o background.o perso.o -o prog -lSDL -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image  -lSDL_mixer  -g
background.o:background.c
	gcc -c background.c -lSDL -lSDL_image  -lSDL_mixer  -g
perso.o:perso.c
	gcc -c perso.c -lSDL -lSDL_image  -lSDL_mixer  -g
