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
};

typedef struct Green_Label Green_Label;

#endif
