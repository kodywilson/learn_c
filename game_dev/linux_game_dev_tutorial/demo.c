// SDL Video Demo

#include <SDL.h>

// external variables
SDL_Surface *demo_screen;

int main(void)
{
  SDL_Event ev;
  int active;
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
  demo_screen = SDL_SetVideoMode(320,240,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
  if (!demo_screen)
    fprintf(stderr,"Could not set video mode: %s\n", SDL_GetError());
  // main loop
  active = 1;
  while(active)
  {
    // handle events
    while(SDL_PollEvent(&ev))
      if (ev.type == SDL_QUIT)
        active = 0;
  }
  SDL_Quit();

  return 0;
}

