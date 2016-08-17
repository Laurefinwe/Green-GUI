#include <SDL/SDL.h>
#include "button.h"

SDL_Event e;
SDL_Surface *screen, *sur;
Green_Button *button;

int main(int argc, char **argv)
{
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG);

  screen = SDL_SetVideoMode(640, 480, 0, SDL_ANYFORMAT);

  button = malloc(sizeof (Green_Button));
  //Green_InitializeButton(button);
  
  Green_SetButtonEverything(button, 10, 10, "button.png", 0, 0, 0, screen);
  Green_DrawButton(button, screen);
  
  for (;;)
    {
      if (SDL_PollEvent(&e) == 0)
	{
	  if (strcmp(button->path, "button2.png"))
	    {
	      Green_LoadButton(button, "button.png", 0, 0, 0, NULL);
	    }
	  SDL_Flip(screen);
	} else
	{
	  switch (e.type)
	    {
	    case SDL_QUIT:
	      Green_FreeButton(button);
	      exit(1);
	      break;

	    case SDL_MOUSEBUTTONDOWN:
	      if (Green_CheckButton(button, &e))
		{
		  Green_LoadButton(button, "button2.png", 0, 0, 0, screen);
		  Green_DrawButton(button, screen);
		}
	      break;

	    case SDL_MOUSEMOTION:
	      if (Green_CheckButton(button, &e))
		{
		  Green_LoadButton(button, "button1.png", 0, 0, 0, screen);
		  Green_DrawButton(button, screen);
		}
	      
	      break;
	    }
	}
    }

  return 0;
}
