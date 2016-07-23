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
} Green_LabelDefault {.font = NULL, .size = 0, .x = 0, .y = 0, .w = 0, .h = 0, .text = NULL, .path = NULL, .color = 0};

typedef struct Green_Label Green_Label;



#endif
