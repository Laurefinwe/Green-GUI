#include "button.h"
#include "label.h"

int main(int argc, char **argv)
{
  SDL_Surface *screen;
  Green_Label *label;
  
  Green_InitializeLabel(label);
  Green_SetLabelEverything(label, 10, 10, 10, 0, 255, 0, "font.ttf", "TAK");

  screen = SDL_SetVideoMode(640, 480, 32, 0);
  
  Green_FreeLabel(label);
  
  return 0;
}
