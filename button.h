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
};

typedef struct Green_Button Green_Button;

void Green_SetButton(Green_Button *button, int x, int y, int w, int h, Green_Label *label);
void Green_DrawButton(Green_Button *button, SDL_Surface *screen, SDL_Surface *button_surface);
bool Green_CheckButton(Green_Button *button, SDL_Event *event);

#endif
