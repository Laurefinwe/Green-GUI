#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "button.h"
#include "label.h"

int main()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG);

  SDL_Surface *screen = SDL_SetVideoMode(640, 480, 0, SDL_ANYFORMAT);
  Green_Button *button;
  Green_InitializeButton(button);
  Green_SetButtonEverything(button, 10, 10, "button.png", 0, 255, 0, screen);
  Green_DrawButton(button, screen);
  SDL_Flip(screen);
  SDL_Event e;
  for (;;)
    {
      SDL_PollEvent(&e);
      if (e.type == SDL_QUIT)
	break;
    }
  Green_FreeButton(button);
  SDL_FreeSurface(screen);
  SDL_Quit();
  return 1;
}
