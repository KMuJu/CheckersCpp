#pragma once
#include <SDL2/SDL.h>

#include "Constants.hpp"
#include "Game.hpp"

class App {
 public:
  const int SCREENSIZE = Constants::SCREENSIZE;
  ~App();

  bool init();
  void run();

  static SDL_Window *getWindow();
  static SDL_Renderer *getRenderer();

 private:
  Game game;
  static SDL_Window *gWindow;
  static SDL_Renderer *gRenderer;
  SDL_Event event;
};
