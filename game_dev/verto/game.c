// simple demo game

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <time.h>

typedef struct
{
  int x, y;
  short life;
  char *name;
} Mob;

typedef struct
{
  int x, y;
} Hero;

typedef struct
{
  // players
  Mob mob;

  Hero heros[100];

  // images
  SDL_Texture *hero;
  SDL_Renderer *renderer;
} GameState;

// prototypes
int processEvents(SDL_Window *window, GameState *game);
int doRender(SDL_Renderer *renderer, GameState *game);
int loadGame(GameState *game);

int main(void)
{
  GameState gameState;      // use GameState struct
  SDL_Window *window = NULL;       // declare a window
  SDL_Renderer *renderer = NULL;   // declare a renderer

  SDL_Init(SDL_INIT_VIDEO); // initialize SDL2
  srandom((int) time(NULL));

  // Create an application window with the following settings:
  window = SDL_CreateWindow("Game Window",            // window title
                            SDL_WINDOWPOS_UNDEFINED,  // initial x position
                            SDL_WINDOWPOS_UNDEFINED,  // initial y position
                            640,                      // width, in pixels
                            480,                      // height, in pixels
                            0                         // flags
                            );
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  gameState.renderer = renderer;

  loadGame(&gameState);

  // The window is open, enter main loop
  int done = 0;
  while (!done)
  {
    done = processEvents(window, &gameState);  // check for events
    doRender(renderer, &gameState); // render screen

    // go easy on the cpu
    // SDL_Delay(20); // using vsync now
  }

  // close and destroy textures and window
  SDL_DestroyTexture(gameState.hero);
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

  // draw a white rectangle at mob's position
  SDL_Rect rect = { game->mob.x, game->mob.y, 50, 50 };  // x, y, width, height of rectangle
  SDL_RenderFillRect(renderer, &rect);

  // draw the heros
  for(int i = 0; i < 100; i++)
  {
    SDL_Rect heroRect = { game->heros[i].x, game->heros[i].y, 50, 37 };
    SDL_RenderCopy(renderer, game->hero, NULL, &heroRect);
  }
  SDL_Rect heroRect = { 50, 50, 50, 37 };
  SDL_RenderCopy(renderer, game->hero, NULL, &heroRect);

  // present to the window
  SDL_RenderPresent(renderer);
}

int loadGame(GameState *game)
{
  //Mob mob;
  game->mob.x = 320-50;
  game->mob.y = 240-40;
  SDL_Surface *heroSurface = NULL;

  // Load images and create rendering textures from them
  heroSurface = IMG_Load("hero.png");
  if (heroSurface == NULL)
  {
    printf("Can not find hero.png!\n\n");
    SDL_Quit();
    exit(1);
  }

  game->hero = SDL_CreateTextureFromSurface(game->renderer, heroSurface);
  SDL_FreeSurface(heroSurface);

  // init heros
  for(int i = 0; i < 100; i++)
  {
    game->heros[i].x = random() % 640;
    game->heros[i].y = random() % 480;
  }
}

