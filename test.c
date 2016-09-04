#include <SDL/SDL_ttf2.h>
#include <SDL/SDL.h>
#include "button.h"
#include "label.h"

SDL_Event e;
SDL_Surface *screen, *sur;
Green_Button *button;
Green_Label *label;

int main(int argc, char **argv)
{
  SDL_Init(SDL_INIT_EVERYTHING);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();

  screen = SDL_SetVideoMode(640, 480, 0, SDL_ANYFORMAT);

  label = malloc(sizeof (Green_Label));
  button = malloc(sizeof (Green_Button));
  //Green_InitializeButton(button);

  Green_SetLabelEverything(label, 10, 20, 12, 0, 255, 0, "font.ttf", "Text");
  Green_DrawLabel(label, screen);
  Green_SetButtonEverything(button, 10, 10, "button.png");
  Green_DrawButton(button, screen);
  
  for (;;)
    {
      if (SDL_PollEvent(&e) == 0)
	{
	  if (strcmp(button->path, "button1.png"))
	    {
	      Green_LoadButton(button, "button.png");
	      Green_DrawButton(button, screen);
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
		  Green_LoadButton(button, "button2.png");
		  SDL_FillRect(screen, NULL, 0);
		  Green_DrawButton(button, screen);
		}
	      break;

	    case SDL_MOUSEMOTION:
	      if (Green_CheckButton(button, &e))
		{
		  Green_LoadButton(button, "button1.png");
		  SDL_FillRect(screen, NULL, 0);
		  Green_DrawButton(button, screen);
		}
	      
	      //Green_LoadButton(button, "button.png");
	      //Green_DrawButton(button, screen);
	      break;
	    }
	}
    }

  return 0;
}
