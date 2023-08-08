
#include <SDL.h>

#include "logger.h"
#include "common.h"

int main() {
  INFO("Starting Gizmo");

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    ERROR(SDL_GetError());
    return -1;
  }

  SDL_Window* window = SDL_CreateWindow(gizmoState->title.c_str(), gizmoState->size.x, gizmoState->size.y, 0);
  if (window == NULL) {
    ERROR(SDL_GetError());
    return -1;
  }

  SDL_Renderer* renderer = SDL_CreateRenderer(window, "", SDL_RENDERER_ACCELERATED); // ERROR here: "Couldn't find matching render driver"
  if (renderer == NULL) {
    ERROR(SDL_GetError());
    return -1;
  }

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  SDL_Delay(15000); // Wait for 2 seconds

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  delete gizmoState;
  return 0;
}