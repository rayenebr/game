#include "Fonctions.h"
#define GRAVITY 10





void initPerso (Personne *p)
{
int i,j;
char nomFich[60];
p->rect.x=0;
p->rect.y=300;

p->rect.w=48;
p->rect.h=150;
p->vitesse=5;
p->vitesseV=0;
p->direction=0; 
p->frame=0;
/*
0:stable right 
1:stable left
2:move right
3:move left
*/
for ( i = 0; i < 7; i++)
{
  for ( j=0 ; j < 4; j++)
  {
    sprintf(nomFich,"animation/%d/%d.png",i,j+1);
    p->imgs[i][j]=IMG_Load(nomFich);
  }
  
}


}

void initInput (Input *I)
{
I->left=0;
I->right=0;
I->up=0;
I->attack1=0;
I->attack2=0;
}


void afficherPerso (Personne *p,SDL_Surface *screen)
{
  SDL_BlitSurface(p->imgs[p->direction][p->frame],NULL,screen,&p->rect);
}




void deplacerPerso(Personne *p,Uint32 dt){
  double dx;
  dx =  p->acceleration * dt * dt * 0.5 + p->vitesse * dt ;
  if (p->direction == 2)
  {
    p->rect.x += dx;
  }else if (p->direction == 3)
  {
    p->rect.x-=dx;
  }
   
   
}

void animerPerso(Personne *p)
{
  p->frame++;
  if (p->frame > 3)
  {
    p->frame = 0;
  }  
}



void saut(Personne *p,int dt, int posinit)
{
  double dx;
  if (p->rect.y == posinit)
  {
    dx = 0.5 * p->acceleration  + 5* dt;
    p->vitesseV -= dx;
  }  
 /*/ else if (p->rect.y<posinit)
{
p->rect.y+= p->vitesseV;
p->vitesseV += GRAVITY;
 if(p->rect.y >= 300)
   {
    p->rect.y= 300;
    p->vitesseV = 0;
   }
}/*/
}
