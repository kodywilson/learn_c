// simple demo game

#include <SDL2/SDL.h>
#include <stdio.h>

int main(void)
{
  SDL_Window *window;       // declare a window
  SDL_Renderer *renderer;   // declare a renderer

  SDL_Init(SDL_INIT_VIDEO); // initialize SDL2

  // Create an application window with the following settings:
  window = SDL_CreateWindow("Game Window",            // window title
                            SDL_WINDOWPOS_UNDEFINED,  // initial x position
                            SDL_WINDOWPOS_UNDEFINED,  // initial y position
                            640,                      // width, in pixels
                            480,                      // height, in pixels
                            0                         // flags
                            );
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // set drawing color to blue

  SDL_RenderClear(renderer); // clear the screen to blue

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // set drawing color to white

  // create a white rectangle
  SDL_Rect rect = { 220, 140, 200, 200 };  // x, y, width, height of rectangle
  SDL_RenderFillRect(renderer, &rect);

  // present to the window
  SDL_RenderPresent(renderer);

  // wait a few seconds and then quit program
  SDL_Delay(3000);

  // close and destroy window
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);

  // clean up
  SDL_Quit();

  return 0;
}

