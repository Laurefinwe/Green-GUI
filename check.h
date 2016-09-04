#ifndef GREEN_CHECK_H
#define GREEN_CHECK_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "surface.h"

struct Green_Check
{
  int x, y, w, h;
  int state;
  int is;
  Green_MultiSurface surface;
};

typedef struct Green_Check Green_Check;

int Green_SetCheckEverything(Green_Check *check, char *path, int x, int y);
int Green_InitializeCheck(Green_Check *check);
int Green_CheckCheck(Green_Check *check, SDL_Event *event);
int Green_IsChecked(Green_Check *check);
void Green_FreeCheck(Green_Check *check);
int Green_LoadCheck(Green_Check *check, char *path);

#endif
