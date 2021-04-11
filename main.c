#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>


#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "Fonctions.h"
#include "ennemi.h"
#include "background.h"

#define GRAVITY 10

int main()
{

SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen;
screen=SDL_SetVideoMode (1000,700,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

SDL_WM_SetCaption("game\t1",NULL);


background b;
Ennemi e;
Input I;
Personne p;
SDL_Event event;
Uint32 dt, t_prev;
SDL_Surface *back;

initBack(&b);
initPerso (&p);
initInput  (&I);
initEnnemi(&e);



int running=1;



while(running)
{

t_prev=SDL_GetTicks();
while(SDL_PollEvent(&event))
	{

		switch(event.type)
		{
		case SDL_QUIT:

			running=0;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			
			case SDLK_LEFT :
				I.left=1;



      		break;
      		case SDLK_RIGHT :
				I.right=1;
				
      		break;
			case SDLK_UP :
				I.up = 1;
				
	                case SDLK_d:
                          I.attack1=1;
                          p.direction=5;
                break;
                      case SDLK_a:
                          I.attack2=1;
                          p.direction=6;
                break;
			}
		break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				I.right=0;
				p.direction=0;
			break;
			case SDLK_LEFT :
				I.left=0;
				p.direction=1;
      		break;
			  case SDLK_UP : 
			  I.up = 0;
		    case SDLK_d:
                          I.attack1=0;
                          p.direction=0;
                break;
                      case SDLK_a:
                          I.attack2=0;
                          p.direction=1;
                break;
			}
		break;
		}
	}

 if (I.right==1)
{
	p.acceleration+=0.02;
	p.direction=2;
	p.vitesse = 5;
}
else if (I.left==1 )
{
	p.acceleration+=0.02;
	p.direction=3;
	p.vitesse = 5;
}
else if (I.left==0 && I.right==0)
{
	p.vitesse = 0;
}




p.acceleration-=0.004;


if (p.acceleration<0 ) p.acceleration=0;
if (p.acceleration>0.02 ) p.acceleration=0.02;



SDL_Delay(10);

dt=SDL_GetTicks()-t_prev;

deplacerPerso(&p,dt);

if (I.up==1)
{
	saut(&p,dt,300);
}
p.rect.y+= p.vitesseV;
p.vitesseV += GRAVITY;
 if(p.rect.y >= 300)
 	 {
 		 p.rect.y= 300;
 		 p.vitesseV = 0;
}






//	SDL_BlitSurface(back, NULL, screen, NULL);
     
	aficherBack(b,screen);
    
      
	afficherEnnemi(&e,screen);
	deplacerIA(&e,p.rect);
	animerEnnemi(&e);
	animerPerso(&p);
        
	afficherPerso (&p,screen);
     
        

	if (collisionBB(e.rect,p.rect)==1)
	{
	printf("vie--\n");
		printf("score--\n");
	}
	
//scrolling(&b,screen);

	SDL_Flip(screen);
	SDL_Delay(100);
}
SDL_FreeSurface(screen);
TTF_Quit();
SDL_Quit;



}



