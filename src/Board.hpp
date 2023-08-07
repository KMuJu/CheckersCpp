#pragma once
#include "Move.hpp"
#include "PieceList.hpp"

class Board {
 public:
  Board();

  void renderPieces() const;
  void init();

  int* operator[](int i);

  void move(Move& m);

 private:
  int board[64];
  PieceList whiteMan{12};
  PieceList blackMan{12};
  PieceList whiteKing{12};
  PieceList blackKing{12};
  PieceList empty{0};
};
