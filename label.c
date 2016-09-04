#include "label.h"

int Green_InitializeLabel(Green_Label *label)
{
  if ((label = malloc(sizeof (Green_Label))) == 0)
    return -1;
  return 0;
}

void Green_SetLabelColor(Green_Label *label, Uint8 red, Uint8 green, Uint8 blue)
{
  label->color.g = green;
  label->color.r = red;
  label->color.b = blue;
}

void Green_SetLabelPosition(Green_Label *label, int x, int y)
{
  label->x = x;
  label->y = y;
}

int Green_SetLabelFont(Green_Label *label, int size, char *path)
{
  label->size = size;
  label->path = path;
  
  if ((label->font = TTF_OpenFont(label->path, label->size)) < 0)
    return -1;
  return 0;
}

void Green_SetLabelText(Green_Label *label, char *text)
{
  label->text = text;
}

int Green_DrawLabel(Green_Label *label, SDL_Surface *screen)
{
  SDL_Rect rect, label_rect;
  SDL_Surface *label_surface;

  label_rect.x = label_rect.y = 0;
  rect.x = label->x;
  rect.y = label->y;
  
  if ((label_surface = TTF_RenderText_Blended(label->font, label->text, label->color)) < 0)
    return -1;
  
  label_rect.w = rect.w = label_surface->w;
  label_rect.h = rect.h = label_surface->h;
  
  if ((SDL_BlitSurface(label_surface, &label_rect, screen, &rect)) < 0)
    return -2;
  return 0;
}

int Green_CheckLabel(Green_Label *label, SDL_Event *event)
{
  if (event->motion.x > label->x && event->motion.x < label->x + label->w && event->motion.y > label->y && event->motion.y < label->y + label->h)
    {
      return 0;
    } else return -1;
}

int Green_SetLabelEverything(Green_Label *label, int x, int y, int size, Uint8 red, Uint8 green, Uint8 blue, char *path, char *text)
{
  Green_SetLabelText(label, text);
  Green_SetLabelPosition(label, x, y);
  if (Green_SetLabelFont(label, size, path) < 0)
    return -1;
  Green_SetLabelColor(label, red, green, blue);
  return 0;
}

void Green_FreeLabel(Green_Label *label)
{
  TTF_CloseFont(label->font);
  free(label->path);
  free(label->text);
  free(label);
}
