#ifndef PERSO9_H_INCLUDED
#define PERSO9_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>

typedef struct
{

SDL_Rect pos;
SDL_Rect pos1;
SDL_Surface *sprite[8];
int score;
double vitesse;
double acceleration;
int vie;

int move;
int frame;
int frame1;
int jump;
}Personne;


void init (Personne * p, int numperso);
void initPerso(Personne *p);
void afficherPerso(Personne p, SDL_Surface * screen);
void deplacerPerso (Personne *p);
void animerPerso (Personne* p);
void saut (Personne* p) ;







#endif
