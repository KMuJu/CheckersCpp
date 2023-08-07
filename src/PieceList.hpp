#pragma once

#include <cstdint>
struct PieceList {
  int numPieces, maxPieces;
  int* pieces;
  int map[64];
  uint64_t bitboard;

  PieceList(int max_number);
  // free allocated memory
  ~PieceList();

  void reset();
  void add(int square);
  void remove(int square);
  void move(int start, int target);
  uint64_t& getBitboard();
};
