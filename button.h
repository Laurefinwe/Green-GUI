#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "label.h"

#ifndef BUTTON_H
#define BUTTON_H

struct Green_Button
{
  int x, y;
  int w, h;
  Green_Label *label;
  SDL_Surface *surface;
} Green_ButtonDefault {.x = 0, .y = 0, .w = 0, .h = 0, .label = NULL, .surface = NULL};

typedef struct Green_Button Green_Button;

void Green_LoadButton(Green_Button *button, char *path, SDL_Surface *surface);
void Green_SetButtonXY(Green_Button *button, int x, int y);
void Green_InitializeButton(Green_Button *button);
void Green_AddLabelToButton(Green_Button *button, Green_Label *label);
void Green_SetButtonEverything();

void Green_DrawButton(Green_Button *button, SDL_Surface *screen);
bool Green_CheckButton(Green_Button *button, SDL_Event *event);

#endif
