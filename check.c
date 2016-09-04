#include "check.h"

int Green_InitializeCheck(Green_Check *check)
{
  if ((check = malloc(sizeof (Green_Check))) == NULL)
    return -1;
  return 0;
}

void Green_SetCheckPosition(Green_Check *check, int x, int y)
{
  check->x = x;
  check->y = y;
}

int Green_LoadCheck(Green_Check *check, char *path)
{
  if((check->surface.normal = IMG_Load(path)) == NULL)
    return -1;
  
  check->w = check->surface.normal->w;
  check->h = check->surface.normal->h;
  
  return 0;
}

int Green_SetCheckEverything(Green_Check *check, char *path, int x, int y)
{
  if (Green_InitializeCheck(check) < 0)
    return -1;
  
  if (Green_LoadCheck(check, path) < 0)
    return -2;
  
  Green_SetCheckPosition(check, x, y);
  return 0;
}

int Green_CheckCheck(Green_Check *check, SDL_Event *event)
{
  if (check == NULL)
    return -1;
  if (event == NULL)
    return -2;
		
  switch (event->type)
    {    
    case SDL_MOUSEBUTTONDOWN:
      if (event->motion.x > check->x && event->motion.y > check->y && event->motion.x < check->x + check->w && event->motion.y < check->y + check->h)
	{
	  check->state = 1;
	  check->is = 1;
	  return 1;
	}
      break;

    case SDL_MOUSEMOTION:
      if (event->motion.x > check->x && event->motion.y > check->y && event->motion.x < check->x + check->w && event->motion.y < check->y + check->h)
	{
	  check->state = 2;
	  return 2;
	}
      break;

    }
  return 0;
}

int Green_IsChecked(Green_Check *check)
{
  if (check->is == 1)
    return 1;
  return 0;
}

void Green_FreeCheck(Green_Check *check)
{
  Green_FreeMultiSurface(check->surface);
  free(check);
}
