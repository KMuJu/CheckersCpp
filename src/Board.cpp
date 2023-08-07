#include "Board.hpp"

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include "App.hpp"
#include "Constants.hpp"
#include "Piece.hpp"
#include "PieceList.hpp"
#include "SDL_Util.hpp"

Board::Board() {
  //
  init();
}

int* Board::operator[](int i) { return &board[i]; }

void Board::renderPieces() const {
  int colour{0};
  for (int y_ = 0; y_ < 8; y_++) {
    int y = 7 - y_;
    for (int x = 0; x < 8; x++) {
      int index = x + y * 8;
      int colour =
          (Piece::Colour(board[x + y_ * 8]) == Piece::white) ? 0xffffff : 0;
      if (Piece::Type(board[index]) != 0) {
        SDL_SetRenderDrawColor(App::getRenderer(), colour >> 16,
                               (colour >> 8) & 0xff, colour & 0xff, 255);
        SDL_Util::DrawCircle(x * Constants::TILESIZE + Constants::TILESIZE / 2,
                             y * Constants::TILESIZE + Constants::TILESIZE / 2,
                             Constants::TILESIZE / 3);
      }
    }
  }
}
void Board::init() {
  for (int index = 0; index < 64; index++) {
    int colour{0};
    if (index <= 24) {
      colour = Piece::black;
    } else if (index > 40) {
      colour = Piece::white;
    }
    board[index] = Constants::baseBoard[index] + colour;
  }

  whiteMan.reset();
  blackMan.reset();
  whiteKing.reset();
  blackKing.reset();
}

void Board::move(Move& m) {
  int start = m.getStart();
  int target = m.getTarget();
  int capture = m.getCapture();
}
