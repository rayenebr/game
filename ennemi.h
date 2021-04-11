#ifndef enemy_H_INCLUDED
#define enemy_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct Ennemi
	{

	SDL_Rect rect;
    SDL_Surface *imgs[4][4];
	int frame;
	int direction;
        int stat;
	}Ennemi;


void initEnnemi (Ennemi *E);
void afficherEnnemi(Ennemi *E,SDL_Surface *screen);
void animerEnnemi (Ennemi *E);
int collisionBB (SDL_Rect e,SDL_Rect p);
void deplacer( Ennemi * e);
void etat (Ennemi *e,SDL_Rect posPerso);
void deplacerIA( Ennemi * e, SDL_Rect posPerso);




















#endif // DS_H_INCLUDED
