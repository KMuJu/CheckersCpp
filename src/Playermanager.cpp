
#include "Playermanager.hpp"

#include <iostream>

#include "Board.hpp"

PlayerManager::PlayerManager(Board* board) {
  // init
  state = STATE::waiting;
  this->board = board;
}

void PlayerManager::klikk(int index) {
  if (state == STATE::waiting) {
    start = index;
    state = STATE::choosing_move;
    return;
  }
  target = index;
  state = STATE::waiting;
  Move m = {start, target};
  board->move(m);
  // std::cout << "Start: " << start << ", Target: " << target << "\n";
}
