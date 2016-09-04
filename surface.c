#include "surface.h"

void Green_FreeMultiSurface(Green_MultiSurface surface)
{
  SDL_FreeSurface(surface.normal);
  SDL_FreeSurface(surface.move);
  SDL_FreeSurface(surface.click);
  SDL_FreeSurface(surface.actual);
}
