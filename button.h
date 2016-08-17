#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
//#include "label.h"

#ifndef BUTTON_H
#define BUTTON_H

struct Green_Button
{
  int x, y;
  int w, h;
  SDL_Surface *surface;
};

typedef struct Green_Button Green_Button;

void Green_LoadButton(Green_Button *button, char *path, Uint8 red, Uint8 green, Uint8 blue, SDL_Surface *screen);
void Green_SetButtonXY(Green_Button *button, int x, int y);
//void Green_AddLabelToButton(Green_Button *button, Green_Label *label);
void Green_SetButtonEverything(Green_Button *button, int x, int y, char *path, Uint8 red, Uint8 green, Uint8 blue, SDL_Surface *screen/*, Green_Label *label*/);

void Green_InitializeButton(Green_Button *button);
void Green_FreeButton(Green_Button *button);
void Green_DrawButton(Green_Button *button, SDL_Surface *screen);
bool Green_CheckButtonMotion(Green_Button *button, SDL_Event *event);
bool Green_CheckButtonClick(Green_Button *button, SDL_Event *event);

#endif
