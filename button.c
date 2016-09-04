#include "button.h"

int Green_InitializeButton(Green_Button *button)
{
  if ((button = malloc(sizeof (Green_Button))) == NULL)
    return -1;
  if ((button->path = malloc(1024 * sizeof (char))) == NULL)
    return -2;
  
  button->state = 0;
  button->x = button->y = button->w = button->h = 0;
  return 0;
  //Green_InitilaizeLabel(button->label);
}

int Green_CheckButton(Green_Button *button, SDL_Event *event)
{
  switch (event->type)
    {
    case SDL_MOUSEBUTTONDOWN:
      if (event->button.x > button->x && event->button.x < button->x + button->w && event->button.y > button->y && event->button.y < button->y + button->h)
	{
	  button->state = 1;
	  return 1;
	}
      break;

    case SDL_MOUSEMOTION:
      if (event->motion.x > button->x && event->motion.x < button->x + button->w && event->motion.y > button->y && event->motion.y < button->y + button->h)
	{
	  button->state = 2;
	  return 2;
	}
    }
  return 0;
}

int Green_DrawButton(Green_Button *button, SDL_Surface *screen)
{ 
  SDL_Rect rect, button_rect;
  
  rect.x = button->x;
  rect.y = button->y;
  rect.w = button_rect.w = button->w;
  rect.h = button_rect.h = button->h;

  button_rect.x = button_rect.y = 0;

  if (SDL_BlitSurface(button->surface.normal, &button_rect, screen, &rect) < 0)
    return -1;
  return 0;
}

int Green_LoadButton(Green_Button *button, char *path)
{
  if (path != NULL)
    {
      if ((button->surface.normal = IMG_Load(path)) == NULL)
	return -1;
      button->path = path;
    } else if (button->path != NULL)
    if ((button->surface.normal = IMG_Load(button->path)) == NULL)
      return -1;
  
  button->w = button->surface.normal->w;
  button->h = button->surface.normal->h;

  return 0;
}

int Green_FillButton(Green_Button *button, Uint8 red, Uint8 green, Uint8 blue, Uint16 width, Uint16 height, SDL_Surface *screen)
{
  button->surface.normal->w = width;
  button->surface.normal->h = height;
  
  if (SDL_FillRect(button->surface.normal, 0, SDL_MapRGB(screen->format, red, green, blue)) < 0)
    return -1;
  return 0;
}

/*void Green_AddLabelToButton(Green_Button *button, Green_Label *label)
{
  button->label = label;
  
  if (label != NULL)
    {
      button->label->x = button->x;
      button->label->y = button->y;
    }
}*/

void Green_SetButtonXY(Green_Button *button, int x, int y)
{
  button->x = x;
  button->y = y;
}

int Green_SetButtonEverything(Green_Button *button, int x, int y, char *path)
{
  if (Green_InitializeButton(button) < 0)
    return -1;
  
  if (Green_LoadButton(button, path) < 0)
    return -2;
  
  Green_SetButtonXY(button, x, y);
  return 0;
  //Green_Add_LabbelToButton(button, label);
}

void Green_FreeButton(Green_Button *button)
{
  Green_FreeMultiSurface(button->surface);
  //Green_FreeLabel(button->label);
  free(button);
}
