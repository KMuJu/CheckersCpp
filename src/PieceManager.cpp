#include "PieceManager.hpp"

#include <iostream>

#include "PieceList.hpp"

PieceList* PieceManager::getPieceList(int piece) {
  int colourIndex = (Piece::Colour(piece) == Piece::white) ? 0 : 1;
  int pieceIndex = (Piece::Type(piece) == Piece::man) ? 0 : 1;
  PieceList* list;
  switch (pieceIndex + 2 * colourIndex) {
    case 0:
      list = &whiteMen;
      break;
    case 1:
      list = &whiteKings;
      break;
    case 2:
      list = &blackMen;
      break;
    case 3:
      list = &blackKings;
      break;
    default:
      list = &empty;
      break;
  }
  return list;
}

void PieceManager::init(){
  whiteMen.reset();
  whiteKings.reset();
  blackMen.reset();
  blackKings.reset();
}
