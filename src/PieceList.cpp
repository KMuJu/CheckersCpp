#include "PieceList.hpp"

#include <cstdint>
#include <iostream>

PieceList::PieceList(int max_number) {
  this->maxPieces = max_number;
  pieces = new int[max_number];
}

PieceList::~PieceList() { delete[] pieces; }

void PieceList::reset() {
  for (int i = 0; i < maxPieces; i++) {
    pieces[i] = 0;
  }
}

void PieceList::add(int square) {
  if (numPieces >= maxPieces || numPieces < 0) {
    std::cout << "!!!!!!feil i add!!!!!!!!!!\n";
    return;
  }
  pieces[numPieces] = square;
  map[square] = numPieces;
  numPieces++;
  bitboard |= 1L << square;
}

void PieceList::remove(int square) {
  if (numPieces >= maxPieces || numPieces < 0) {
    std::cout << "!!!!!!feil i add!!!!!!!!!!\n";
    return;
  }
  int index = map[square];
  pieces[square] = pieces[numPieces - 1];
  map[pieces[square]] = square;
  numPieces--;
  bitboard -= 1L << square;
}

void PieceList::move(int start, int target) {
  int index = map[start];
  pieces[index] = target;
  map[target] = index;
  bitboard -= 1L << start;
  bitboard |= 1L << target;
}

uint64_t& PieceList::getBitboard() { return bitboard; }
