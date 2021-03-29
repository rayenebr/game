#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>

int main()
{
    int continuer=0;
    initBack();
    while (continuer==0)
    {
    scrolling();
    afficherBack();
    SDL_Flip(ecran);
    Delay
    }
    return 0;
}


