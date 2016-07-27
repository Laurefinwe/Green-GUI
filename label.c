#include "label.h"

void Green_InitializeLabel(Green_Label *label)
{
  label = malloc(sizeof (Green_Label));
}

void Green_SetLabelColor(Green_Label *label, Uint8 red, Uint8 green, Uint8 blue)
{
  label->color.g = green;
  label->color.r = red;
  label->color.b = blue;
}

void Green_SetLabelPosition(Green_Label *label, int x, int y, int w, int h)
{
  label->x = x;
  label->y = y;
  label->w = w;
  label->h = h;
}

void Green_SetLabelFont(Green_Label *label, int size, char *path)
{
  label->size = size;
  label->path = path;
  
  label->font = TTF_OpenFont(label->path, label->size);
}

void Green_SetLabelText(Green_Label *label, char *text)
{
  label->text = text;
}

void Green_DrawLabel(Green_Label *label, SDL_Surface *screen)
{
  SDL_Rect rect, label_rect;
  SDL_Surface *label_surface;

  label_rect.x = label_rect.y = 0;
  label_rect.w = rect.w = label->w;
  label_rect.h = rect.h = label->h;
  rect.x = label->x;
  rect.y = label->y;
  
  label_surface = TTF_RenderText_Blended(label->font, label->text, label->color);
  
  SDL_BlitSurface(label_surface, &label_rect, screen, &rect);
}

bool Green_CheckLabel(Green_Label *label, SDL_Event *event)
{
  if (event->motion.x > label->x && event->motion.x < label->x + label->w && event->motion.y > label->y && event->motion.y < label->y + label->h)
    {
      return true;
    } else return false;
}

void Green_SetLabelEverything(Green_Label *label, int x, int y, int w, int h, int size, Uint8 red, Uint8 green, Uint8 blue, char *path, char *text)
{
  Green_SetLabelText(label, text);
  Green_SetLabelPosition(label, x, y, w, h);
  Green_SetLabelFont(label, size, path);
  Green_SetLabelColor(label, red, green, blue);
}

void Green_FreeLabel(Green_Label *label)
{
  TTF_CloseFont(label->font);
  free(label->path);
  free(label->text);
  free(label);
}
