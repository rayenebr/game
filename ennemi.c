#include "ennemi.h"
#include "Fonctions.h"

void initEnnemi (Ennemi *e){
    int i,j;
    char nomFich[60];
    
    e->rect.x=600;
    e->rect.y=300;
    e->direction=2; 
    e->frame=0;
    e->stat=0;
    /*
0:attack right 
1:attack left
2:move right
3:move left
*/

/*
o:waiting
1:following left
2:attacking left
3:following right
4:attacking right
/*/

    for ( i = 0; i < 4; i++)
{
  for ( j=0 ; j < 4; j++)
  {
    sprintf(nomFich,"animationennemie/%d/%d.png",i,j+1);
    e->imgs[i][j]=IMG_Load(nomFich);
  }
  
}

}

void afficherEnnemi (Ennemi *e,SDL_Surface *screen)
{
  SDL_BlitSurface(e->imgs[e->direction][e->frame],NULL,screen,&e->rect);
}


void animerEnnemi (Ennemi *e){
      e->frame++;
  if (e->frame > 3)
  {
    e->frame = 0;
  }  
}

void deplacer(Ennemi *e)
    {
    int Xmin=600;
    int Xmax=900;
    if (e->rect.x < Xmin)
    {
        e->direction = 2;
       // e->rect.x+=5;
    }else if (e->rect.x > Xmax)
    {
        e->direction = 3;
      //  e->rect.x-=5;
    }
    if (e->direction == 2)
    {
        e->rect.x+=15;
    }
    if (e->direction == 3)
    {
        e->rect.x-=15;
    }   
}


void etat( Ennemi *e, SDL_Rect posPerso){
    if (((e->rect.x - posPerso.x) < 400) && ((e->rect.x - posPerso.x) > 100)) // le perso est dans le champs de vision  de lennemi [100;400]
    {
        e->stat=1;
    }
    else if (((e->rect.x - posPerso.x) < 100) && ((e->rect.x - posPerso.x) > 0)) // le perso est dans le champs dattack de lennemi
    {
        e->stat=2;
    }
    else if (((e->rect.x - posPerso.x) < -100) && ((e->rect.x - posPerso.x) > -400))//le perso est dans le champs de vision  de lennemi [-400;-100] (lennemi a gauche de perso)
    {
        e->stat=3;
    }
    else if (((e->rect.x - posPerso.x) < 0) && ((e->rect.x - posPerso.x) > -100)) // le perso est dans le champs dattack de lennemi
    {
        e->stat=4;
    }
    else
    {
        e->stat=0;
    }
}


void deplacerIA(Ennemi *e,SDL_Rect posPerso)
{


switch(e->stat)
{
case 0:
deplacer(e);

break;
case 1: //left
 e->direction = 3;
    e->rect.x-=20;
break;
case 2:  //attack left
 e->direction = 1;
break;
case 3: //right
e->direction = 2;
        e->rect.x+=20;
break;
case 4: //attack right
 e->direction = 0;
break;

}
etat (e,posPerso);
}





    
    



int collisionBB (SDL_Rect e,SDL_Rect p){
    int collision;
    if (((p.x + p.w) < e.x) || (p.x > (e.x + e.w)) || ((p.y + p.y) < e.y) || (p.y > (e.y + e.y)))
    {
        collision = 0;
    }
    else
    {
        collision = 1;
    }
    
    return collision;
}

