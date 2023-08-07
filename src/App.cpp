#include "App.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_hints.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

#include <iostream>

SDL_Window *App::gWindow = NULL;
SDL_Renderer *App::gRenderer = NULL;

App::~App() {
  if (gRenderer != NULL) {
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;
  }
  if (gWindow != NULL) {
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
  }
}

// starts SDL and initializes window
bool App::init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Couldn't start SDL! SDL error: %s\n", SDL_GetError());
    return false;
  }

  gWindow = SDL_CreateWindow("Checkers", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, SCREENSIZE, SCREENSIZE,
                             SDL_WINDOW_SHOWN);
  if (gWindow == NULL) {
    std::cout << "Couldn't create Window: " << SDL_GetError() << "\n";
    return false;
  }

  gRenderer = SDL_CreateRenderer(
      gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (gRenderer == NULL) {
    std::cout << "Couldn't create Renderer: " << SDL_GetError() << "\n";
    return false;
  }

  return true;
}

void App::run() {
  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
  bool quit = false;
  while (!quit) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        quit = true;
        break;
      }
      if (event.type == SDL_MOUSEBUTTONDOWN) {
        int xPos{0}, yPos{0};
        SDL_GetMouseState(&xPos, &yPos);
        int x{xPos / Constants::TILESIZE}, y{7 - yPos / Constants::TILESIZE};
        game.klikk(x, y);
      }
    }
    if (quit) break;

    // update
    game.update();
    // render
    game.render();
  }
}

SDL_Window *App::getWindow() { return gWindow; }
SDL_Renderer *App::getRenderer() { return gRenderer; }
