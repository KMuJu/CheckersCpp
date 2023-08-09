#include "Board.hpp"

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include <iostream>

#include "App.hpp"
#include "Constants.hpp"
#include "Piece.hpp"
#include "PieceList.hpp"
#include "SDL_Util.hpp"

Board::Board() {
  //
  init();
}

int Board::operator[](int i) { return board[i]; }

void Board::renderPieces() const {
  int colour{0};
  for (int y_ = 0; y_ < 8; y_++) {
    int y = 7 - y_;
    for (int x = 0; x < 8; x++) {
      int index = x + y * 8;
      int colour =
          (Piece::Colour(board[x + y_ * 8]) == Piece::white) ? 0xffffff : 0;
      if (Piece::Type(board[x + y_ * 8]) != 0) {
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
  pieceManager.init();
  for (int index = 0; index < 64; index++) {
    int colour{0};
    if (index <= 24) {
      colour = Piece::black;
    } else if (index >= 40) {
      colour = Piece::white;
    }
    if (Constants::baseBoard[index] != 0) {
      addPiece(index, Constants::baseBoard[index] + colour);
    } else
      board[index] = 0;
  }

  //boardstate
  //first 6 bits  - moved square
  //next 6 bits   - captured square
  currentGameState = 0;
}

void Board::move(Move& m) {
  bool isCapture = m.isCapture();
  bool isPromotion = m.isPromotion();
  int start = m.getStart();
  int target = m.getTarget();
  int capture = m.getCapture();

  int movedPiece = board[start];
  int targetPiece = board[target];
  int capturePiece = board[capture];
  int colourToMove = Piece::Colour(movedPiece);
  if (isCapture) {
    removePiece(capture, capturePiece);
    currentGameState &= ~(Move::captureMask) << 6;
    currentGameState |= capture << 6;
  }
  movePiece(start, target, movedPiece);
  currentGameState &= ~Move::captureMask;
  currentGameState |= start;

  if (isPromotion) {
    removePiece(target, targetPiece);
    addPiece(target, Piece::king + colourToMove);
  }

  boardHistory.push(currentGameState);
}

void Board::addPiece(int square, int piece) {
  // adds piece to piecelist
  pieceManager.getPieceList(piece)->add(square);
  board[square] = piece;
}

void Board::removePiece(int square, int piece) {
  // removes piece
  pieceManager.getPieceList(piece)->remove(square);
  board[square] = 0;
}

void Board::movePiece(int start, int target, int piece) {
  // moves piece
  pieceManager.getPieceList(piece)->move(start, target);
  board[start] = 0;
  board[target] = piece;
}
