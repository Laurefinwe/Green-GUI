#include <SDL/SDL_ttf.h>
#include <stdbool.h>

#ifndef GREEN_LABEL_H
#define GREEN_LABEL_H

struct Green_Label
{
  TTF_Font *font;
  int size;
  int x, y;
  int w, h;
  char *text;
  char *path;
  SDL_Color color;
} Green_DefaultLabel = {.font = NULL, .size = 0, .x = 0, .y = 0, .w = 0, .h = 0, .text = NULL, .path = NULL};

typedef struct Green_Label Green_Label;

void Green_SetLabelFont(Green_Label *label, int size, char *path);
void Green_SetLabelText(Green_Label *label, char *text);
void Green_DrawLabel(Green_Label *label, SDL_Surface *screen);
bool Green_CheckLabel(Green_Label *label, SDL_Event *event);
void Green_SetLabelEverything(Green_Label *label, int x, int y, int w, int h, int size, Uint8 red, Uint8 green, Uint8 blue, char *path, char *text);
void Green_CloseLabel(Green_Label *label);
void Green_InitializeLabel(Green_Label *label);

#endif
