#include "button.h"

void Green_InitializeButton(Green_Button *button)
{
  button = malloc(sizeof (Green_Button));
  //Green_InitilaizeLabel(button->label);
}

bool Green_CheckButtonMotion(Green_Button *button, SDL_Event *event)
{
  if (event->motion.x > button->x && event->motion.x < button->x + button->w && event->motion.y > button->y && event->motion.y < button->y + button->h)
    {
      return true;
    } else return false;
}

bool Green_CheckButtonClick(Green_Button *button, SDL_Event *event)
{
  if (event->button.x > button->x && event->button.x < button->x + button->w && event->button.y > button->y && event->button.y < button->y + button->h)
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

void Green_LoadButton(Green_Button *button, char *path, Uint8 red, Uint8 green, Uint8 blue, SDL_Surface *screen)
{
  if (path != NULL)
    {
      button->surface = IMG_Load(path);
    } else
    {
      SDL_FillRect(button->surface, 0, SDL_MapRGB(screen->format, red, green, blue));
    }
  button->w = button->surface->w;
  button->h = button->surface->h;
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

void Green_SetButtonEverything(Green_Button *button, int x, int y, char *path, Uint8 red, Uint8 green, Uint8 blue, SDL_Surface *screen/*, Green_Label *label*/)
{
  Green_InitializeButton(button);
  Green_LoadButton(button, path, red, green, blue, screen);
  Green_SetButtonXY(button, x, y);
  //Green_Add_LabbelToButton(button, label);
}

void Green_FreeButton(Green_Button *button)
{
  SDL_FreeSurface(button->surface);
  //Green_FreeLabel(button->label);
  free(button);
}
