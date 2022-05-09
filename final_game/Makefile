prog:background.o main.o perso.o minimap.o enigme.o ennemie.o entity.o enigmeimage.o arduino.o
	gcc main.o background.o perso.o enigme.o minimap.o ennemie.o entity.o enigmeimage.o arduino.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image  -lSDL_mixer  -g
background.o:background.c
	gcc -c background.c -lSDL -lSDL_image  -lSDL_mixer  -g
minimap.o:minimap.c
	gcc -c minimap.c -lSDL -lSDL_image  -lSDL_mixer -lSDL_ttf -g
perso.o:perso.c
	gcc -c perso.c -lSDL -lSDL_image  -lSDL_mixer  -g
enigme.o:enigme.c
	gcc -c enigme.c
entity.o:entity.c
	gcc -c entity.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf  -g
ennemie.o:ennemie.c
	gcc -c ennemie.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf  -g
enigmeimage.o:enigmeimage.c
	gcc -c enigmeimage.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g
arduino.o:arduino.c
	gcc -c arduino.c -lSDL -lSDL_mixer -lSDL_image -lSDL_ttf  -g

