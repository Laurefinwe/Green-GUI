#ifndef GREEN_BUTTON_H
#define GREEN_BUTTON_H

#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "surface.h"

struct Green_Button
{
  int x, y;
  int w, h;
  int state;
  char *path;
  Green_MultiSurface surface;
};

typedef struct Green_Button Green_Button;

int Green_LoadButton(Green_Button *button, char *path);
int Green_FillButton(Green_Button *button, Uint8 red, Uint8 green, Uint8 blue, Uint16 width, Uint16 height, SDL_Surface *screen);
void Green_SetButtonXY(Green_Button *button, int x, int y);
//void Green_AddLabelToButton(Green_Button *button, Green_Label *label);
int Green_SetButtonEverything(Green_Button *button, int x, int y, char *path);

int Green_InitializeButton(Green_Button *button);
void Green_FreeButton(Green_Button *button);
int Green_DrawButton(Green_Button *button, SDL_Surface *screen);
int Green_CheckButton(Green_Button *button, SDL_Event *event);

#endif
