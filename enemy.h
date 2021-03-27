#ifndef ENEMY2_H_INCLUDED
#define ENEMY2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"
typedef struct
{
int direction;
int frame;
SDL_Rect pos;
SDL_Rect pos1;
SDL_Surface *sprite[3];
SDL_Surface *sprite1[4];
int stat;

}Enemy;


void initEnnemi(Enemy *e);
void afficherEnnemi(Enemy e, SDL_Surface * screen);
void animerEnnemi( Enemy  *e,SDL_Surface *screen);
void deplacer( Enemy * e);
int collisionBB( Personne p, Enemy e)  ;
void etat (Enemy *e,Personne *p);
void update(Enemy *e,Personne *p,SDL_Surface *screen);






#endif 
