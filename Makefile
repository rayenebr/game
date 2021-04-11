game:main.o Fonctions.o  ennemi.o background.o 
	gcc main.o Fonctions.o ennemi.o background.o -o game -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

main.o:main.c
	gcc -c main.c
Fonctions.o:Fonctions.c
	gcc -c Fonctions.c
ennemi.o:ennemi.c
	gcc -c ennemi.c
background.o:background.c
	gcc -c background.c
