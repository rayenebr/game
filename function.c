#include<stdio.h>
#include"SDL/SDL.h"
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>

void initBack(Background * b)
{
     SDL_Surface *ecran = NULL, *imageDeFond = NULL;
    SDL_Rect positionFond;

     ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
    background = load_image( "background.png" );

    camera_pos.x=0
    camera_pos.y=0

}

void scrolling (background * b, int direction )
{
    if (SDLK_LEFT)
    camera_pos.x--;
    else if (SDLK_RIGHT)
    camera_pos.x++;
    else if (SDLK_UP)
    camera_pos.y--;
    else if (SDLK_DOWN)
    camera_pos.y++;
}

void afficherBack(Background b, SDL_Surface * screen)
{
    int bgX = 0, bgY = 0;
    Mix_Music *music = NULL;
    music = Mix_LoadMUS( "beat.wav" );
        apply_surface( bgX, bgY, background, screen );
        apply_surface( bgX + background->w, bgY, background, screen );
   if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }
    SDL_WM_SetCaption( "Musique", NULL );
    SDL_FreeSurface( background );
    Mix_FreeMusic;
    Mix_CloseAudio();
    SDL_Quit();
}

