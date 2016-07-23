#include "button.h"

void Green_InitializeButton(Green_Button *button)
{
  button = malloc(sizeof (Green_Button));
  Green_InitilaizeLabel(button->label);
}

bool Green_CheckButton(Green_Button *button, SDL_Event *event)
{
  if (event->motion.x > button->x && event->motion.x < button->x + button->w && event->motion.y > button->y && event->motion.y < button->y + button->h)
    {
      return true;
    } else return false;
}

void Green_DrawButton(Green_Button *button, SDL_Surface *screen)
{ 
  SDL_Rect rect, button_rect;
  
  rect.x = button->x;
  rect.y = button->y;
  rect.w = button_rect.w = button->w;
  rect.h = button_rect.h = button->h;

  button_rect.x = button_rect.y = 0;

  SDL_BlitSurface(button->surface, &button_rect, screen, &rect);
}

void Green_LoadButton(Green_Button *button, char *path, Uint8 r, Uint8 g, Uint8 b)
{
  if (path != NULL)
    {
      button->surface = IMG_Load(path);
    } else
    {
      SDL_FillRect(button->surface, 0, r, g, b);
    }
}

void Green_AddLabelToButton(Green_Button *button, Green_Label *label)
{
  button->label = label;
  
  if (label != NULL)
    {
      button->label->x = button->x;
      button->label->y = button->y;
    }

}

void Green_SetButtonXY(Green_Button *button, int x, int y)
{
  button->x = x;
  button->y = y;
  button->w = button->surface->w;
  button->h = button->surface->h;  
}

void Green_SetButtonEverything(Green_Button *button, int x, int y, char *path, Uint8 r, Uint8 g, Uint8 b, Green_Label *label, char *text)
{
  Green_InitializeButton(button);
  Green_LoadButton(button, path, r, g, b);
  Green_SetButtonXY(button, x, y);
  Green_Add_LabbelToButton(button, label);
}
