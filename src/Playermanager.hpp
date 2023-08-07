#pragma once

class PlayerManager {
 public:
  enum class STATE { waiting, choosing_move };
  PlayerManager();

  void klikk(int index);

 private:
  int start, target;
  STATE state;
};
