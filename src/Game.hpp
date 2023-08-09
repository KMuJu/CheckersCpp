#pragma once
#include <SDL2/SDL_rect.h>

#include "Board.hpp"
#include "Playermanager.hpp"

class Game {
 public:
  enum class STATE { WAITING, RUNNING };
  Game();

  void klikk(int x, int y);
  void update();
  void render() const;

 private:
  STATE state;
  Board board;
  PlayerManager playerManager = {&board};
  void init();

  void renderBoardSquare() const;
  // SDL_Rect rect;
};
