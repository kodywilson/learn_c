// simple demo game

#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct
{
  int x, y;
  short life;
  char *name;
} Mob;

// prototypes
int processEvents(SDL_Window *window, Mob *mob);
int doRender(SDL_Renderer *renderer, Mob *mob);

int main(void)
{
  SDL_Window *window;       // declare a window
  SDL_Renderer *renderer;   // declare a renderer

  SDL_Init(SDL_INIT_VIDEO); // initialize SDL2

  Mob mob;
  mob.x = 220;
  mob.y = 140;

  // Create an application window with the following settings:
  window = SDL_CreateWindow("Game Window",            // window title
                            SDL_WINDOWPOS_UNDEFINED,  // initial x position
                            SDL_WINDOWPOS_UNDEFINED,  // initial y position
                            640,                      // width, in pixels
                            480,                      // height, in pixels
                            0                         // flags
                            );
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  // this time we will keep window open until an event occurs
  int done = 0;
  while (!done)
  {
    done = processEvents(window, &mob);  // check for events

    doRender(renderer, &mob); // render screen

    // go easy on the cpu
    SDL_Delay(100);
  }

  // close and destroy window
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  // clean up
  SDL_Quit();

  return 0;
}

int processEvents(SDL_Window *window, Mob *mob)
{
  SDL_Event event;
  int done = 0;

  // event loop
  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_WINDOWEVENT_CLOSE:
        if (window)
        {
          SDL_DestroyWindow(window);
          window = NULL;
          done = 1;
        }
      break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
          case SDLK_ESCAPE: done = 1; break;
          case SDLK_RIGHT: mob->x += 10; break;
          case SDLK_LEFT: mob->x -= 10; break;
        }
      break;
      case SDL_QUIT: done = 1; break;
    }
  }

  return done;
}

int doRender(SDL_Renderer *renderer, Mob *mob)
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // set drawing color to blue
  SDL_RenderClear(renderer); // clear the screen to blue 
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // set drawing color to white

  // create a white rectangle 
  SDL_Rect rect = { mob->x, mob->y, 200, 200 };  // x, y, width, height of rectangle
  SDL_RenderFillRect(renderer, &rect);

  // present to the window
  SDL_RenderPresent(renderer);
}

