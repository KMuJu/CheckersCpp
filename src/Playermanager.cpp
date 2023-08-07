
#include "Playermanager.hpp"

#include <iostream>

PlayerManager::PlayerManager() {
  // init
  state = STATE::waiting;
}

void PlayerManager::klikk(int index) {
  if (state == STATE::waiting) {
    start = index;
    state = STATE::choosing_move;
    return;
  }
  target = index;
  state = STATE::waiting;
  std::cout << "Start: " << start << ", Target: " << target << "\n";
}
