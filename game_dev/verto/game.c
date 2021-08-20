// simple demo game

#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct
{
  int x, y;
  short life;
  char *name;
} Mob;

typedef struct
{
  // players
  Mob mob;

} GameState;

// prototypes
int processEvents(SDL_Window *window, GameState *game);
int doRender(SDL_Renderer *renderer, GameState *game);

int main(void)
{
  GameState gameState;      // use GameState struct
  SDL_Window *window;       // declare a window
  SDL_Renderer *renderer;   // declare a renderer

  SDL_Init(SDL_INIT_VIDEO); // initialize SDL2

  //Mob mob;
  gameState.mob.x = 320-50;
  gameState.mob.y = 240-40;

  // Create an application window with the following settings:
  window = SDL_CreateWindow("Game Window",            // window title
                            SDL_WINDOWPOS_UNDEFINED,  // initial x position
                            SDL_WINDOWPOS_UNDEFINED,  // initial y position
                            640,                      // width, in pixels
                            480,                      // height, in pixels
                            0                         // flags
                            );
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  // this time we will keep window open until an event occurs
  int done = 0;
  while (!done)
  {
    done = processEvents(window, &gameState);  // check for events
    doRender(renderer, &gameState); // render screen

    // go easy on the cpu
    // SDL_Delay(20); // using vsync now
  }

  // close and destroy window
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  // clean up
  SDL_Quit();

  return 0;
}

int processEvents(SDL_Window *window, GameState *game)
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
        }
      break;
      case SDL_QUIT: done = 1; break;
    }
  }
  
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_RIGHT])
    game->mob.x+=10;
  if (state[SDL_SCANCODE_LEFT])
    game->mob.x-=10;
  if (state[SDL_SCANCODE_UP])
    game->mob.y-=10;
  if (state[SDL_SCANCODE_DOWN])
    game->mob.y+=10;

  return done;
}

int doRender(SDL_Renderer *renderer, GameState *game)
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // set drawing color to blue
  SDL_RenderClear(renderer); // clear the screen to blue 
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // set drawing color to white

  // create a white rectangle 
  SDL_Rect rect = { game->mob.x, game->mob.y, 50, 50 };  // x, y, width, height of rectangle
  SDL_RenderFillRect(renderer, &rect);

  // present to the window
  SDL_RenderPresent(renderer);
}

