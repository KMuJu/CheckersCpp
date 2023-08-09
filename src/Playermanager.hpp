#pragma once

#include "Board.hpp"
class PlayerManager {
 public:
  enum class STATE { waiting, choosing_move };
  PlayerManager(Board* board);

  void klikk(int index);

 private:
  int start, target;
  STATE state;
  Board* board;
};
