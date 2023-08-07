#include "Piece.hpp"

int Piece::Colour(int piece) { return piece & colourMask; }

int Piece::Type(int piece) { return piece & typeMask; }

bool Piece::isKing(int piece) { return Type(piece) & king; }
