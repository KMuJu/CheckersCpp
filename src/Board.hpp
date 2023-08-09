#pragma once
#include "Move.hpp"
#include "PieceList.hpp"
#include "PieceManager.hpp"
#include <stack>

class Board {
 public:
  Board();

  void renderPieces() const;
  void init();

  int operator[](int i);

  void move(Move& m);

 private:
  int board[64];
  PieceManager pieceManager;

  void addPiece(int square, int piece);
  void removePiece(int square, int piece);
  void movePiece(int start, int target, int piece);

  int currentGameState;
  std::stack<int> boardHistory;
};
