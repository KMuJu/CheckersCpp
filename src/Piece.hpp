#pragma once

namespace Piece {
static const int man = 0b01;
static const int king = 0b10;
static const int black = 0b0100;
static const int white = 0b1000;

static const int typeMask = 0b11;
static const int colourMask = 0b1100;

int Colour(int piece);
int Type(int piece);
bool isKing(int piece);

} // namespace Piece
