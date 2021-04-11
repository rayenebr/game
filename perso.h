#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


typedef struct Personne
{

    SDL_Surface *imgs[7][4];
    SDL_Rect rect;
    double vitesse, acceleration , vitesseV;
    int direction;
    int frame;
} Personne;

typedef struct Input
{
    int left, right, up,attack1,attack2;

} Input;

void initPerso(Personne *p);
void initInput (Input *I);
void afficherPerso(Personne *p, SDL_Surface *screen);
void deplacerPerso(Personne *p,Uint32 dt);

void animerPerso(Personne *p);
void saut(Personne *p,int dt, int posinit);

#endif
