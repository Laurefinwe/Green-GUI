#include "button.h"

bool Green_CheckButton(Green_Button *button, SDL_Event *event)
{
  if (event->motion.x > button->x && event->motion.x < button->x + button->w && event->motion.y > button->y && event->motion.y < button->y + button->h)
    {
      return true;
    } else return false;
}

void Green_DrawButton(Green_Button *button, SDL_Surface *screen, SDL_Surface *button_surface)
{ 
  SDL_Rect rect, button_rect;
  
  rect.x = button->x;
  rect.y = button->y;
  rect.w = button_rect.w = button->w;
  rect.h = button_rect.h = button->h;

  button_rect.x = button_rect.y = 0;

  SDL_BlitSurface(button_surface, &button_rect, screen, &rect);
}

void Green_SetButton(Green_Button *button, int x, int y, int w, int h, Green_Label *label)
{
  button->x = x;
  button->y = y;
  button->w = w;
  button->h = h;
  
  button->label = label;
  button->label->x = button->x + (int) button->w / 10;
  button->label->y = button->y + (int) button->h / 10;
}

