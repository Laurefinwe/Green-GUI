#ifndef GREEN_SURFACE_H
#define GREEN_SURFACE_H

#include <SDL/SDL.h>

struct Green_MultiSurface
{
  SDL_Surface *actual;
  SDL_Surface *click;
  SDL_Surface *move;
  SDL_Surface *normal;
};

typedef struct Green_MultiSurface Green_MultiSurface;

void Green_FreeMultiSurface(Green_MultiSurface surface);

#endif
