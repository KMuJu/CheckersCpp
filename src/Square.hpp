#pragma once

#include <SDL2/SDL_rect.h>
class Square {
 public:
  Square() = default;
  void render() const;
  void init(int x, int y, int piece);

  int piece;
  int x, y, index;
  int renderX, renderY;
  int colour;
  SDL_Rect rect;
};
