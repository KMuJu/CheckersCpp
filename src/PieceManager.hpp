
#pragma once

#include "Piece.hpp"
#include "PieceList.hpp"
struct PieceManager {
  PieceList empty = {0};
  PieceList whiteMen = {12};
  PieceList whiteKings = {12};
  PieceList blackMen = {12};
  PieceList blackKings = {12};

  PieceList* getPieceList(int piece);

  void init();
};
