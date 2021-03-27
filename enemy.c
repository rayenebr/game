#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enemy2.h"
#include "perso9.h"

void initEnnemi(Enemy *e)
{

e->sprite[0]=IMG_Load("e1.png");
e->sprite[1]=IMG_Load("e2.png");
e->sprite[2]=IMG_Load("e3.png");

e->sprite1[0]=IMG_Load("ee1.png");
e->sprite1[1]=IMG_Load("ee2.png");
e->sprite1[2]=IMG_Load("ee3.png");
e->sprite1[3]=IMG_Load("ee4.png");
e->pos.x=600;
e->pos.y=200;
e->pos.h=20;
e->pos.w=20;
e->pos1=e->pos;
e->direction=0;
e->frame=0;
e->stat=0;
}

void afficherEnnemi(Enemy e, SDL_Surface * screen)
{
SDL_BlitSurface(e.sprite[0],NULL,screen,&e.pos);
     SDL_Flip(screen);

}



void animerEnnemi( Enemy  *e,SDL_Surface *screen)
{
 if(e->direction==0 )
{
while(e->frame<=3)
{
SDL_BlitSurface(e->sprite1[e->frame],NULL,screen,&e->pos);
SDL_Flip(screen);
e->frame++;
SDL_Delay(200);
SDL_FillRect(screen,NULL,0x0);    
}
e->frame=0;
}

else if(e->direction==1  )
{
while(e->frame<=2)
{
SDL_BlitSurface(e->sprite[e->frame],NULL,screen,&e->pos);
SDL_Flip(screen);
e->frame++;
SDL_Delay(200);
SDL_FillRect(screen,NULL,0x0);    
}
e->frame=0;
}
}



void deplacer( Enemy * e)
{

if(e->pos.x> e->pos1.x+200 )
e->direction=0;  //gauche
else if(e->pos.x <e->pos1.x-200  )
e->direction=1;  //droite


 
if(e->direction==0)
e->pos.x-=20;
else  if(e->direction==1)
e->pos.x+=20;



}

int collisionBB( Personne p, Enemy e)
{
int collision=0;

if((p.pos.x+p.pos.w<e.pos.x) || (p.pos.x>e.pos.x+e.pos.w) ||(p.pos.y+p.pos.h<e.pos.y) || (p.pos.y>e.pos.y+e.pos.h))

 collision=1;

return collision;
}

/*/void life (Personne p, Enemy e)
{
int coll;
coll= collisionBB( p,e);

if (coll=1)
{
vie--;
}



}/*/

/*/void etat (Enemy *e,Personne *p)
{
SDL_Event event;
int d,s1,s2;
d=e->pos.x-p->pos.x;
s1=500;
s2=200;

SDL_PollEvent(&event);
switch(e->stat)
{
case 0:
  if(d>s1)
       e->stat=0;
   else if (s2<d<=s1)
       e->stat=1;
break;
case 1:
  if (s2<d<=s1)
    e->stat=1;
  else if(0<d<=s2)
     e->stat=2;
break;
case 2:
   if(0<d<=s2)
      e->stat=2;
   else if(d<=0)
      e->stat=0;

break;
}
}/*/



/*/void update(Enemy *e,Personne *p,SDL_Surface *screen)
{
switch(e->stat)
{
case 0:
animerEnnemi( e,screen);
break;
case 1:
animerEnnemi( e,screen);
deplacer(e);

break;
case 2:

animerEnnemi( e,screen);
deplacer(e);

break;
}
etat (e,p);
}/*/









int main()
{

SDL_Surface *screen= NULL;
Personne p;
Enemy e;
int run=1;

SDL_Init(SDL_INIT_VIDEO);

if(SDL_Init(SDL_INIT_VIDEO) !=0)
{
printf("erreur: %s \n",SDL_GetError());
return 1;
}

screen = SDL_SetVideoMode(1000,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);



initEnnemi(&e);
afficherEnnemi(e, screen);

while(run)
{
animerEnnemi( &e,screen);
deplacer(&e);


//update(&e,&p,screen);



}
SDL_FreeSurface(e.sprite1[4]);
SDL_FreeSurface(e.sprite[3]);
SDL_Quit();

return 0;
}
