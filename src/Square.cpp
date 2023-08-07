#include "Square.hpp"

#include <SDL2/SDL_render.h>

#include "App.hpp"
#include "Piece.hpp"
#include "SDL_Util.hpp"

void Square::init(int x, int y, int piece) {
  this->x = x;
  this->y = y;
  this->piece = piece;
  renderX = x * Constants::TILESIZE;
  renderY = (7 - y) * Constants::TILESIZE;

  rect.x = renderX;
  rect.y = renderY;
  rect.w = Constants::TILESIZE;
  rect.h = Constants::TILESIZE;

  colour = ((x + y) % 2 == 0) ? 0xa87951 : 0xddcfc3;
}

void Square::render() const {
  SDL_Renderer* renderer = App::getRenderer();
  // render Square
  SDL_SetRenderDrawColor(renderer, colour >> 16, (colour >> 8) & 0xff,
                         (colour & 0xff), 255);
  SDL_RenderFillRect(renderer, &rect);

  if (Piece::Type(piece) != 0) {
    int colour = (Piece::Colour(piece) == Piece::white) ? 0xffffff : 0;
    SDL_SetRenderDrawColor(renderer, colour >> 16, (colour >> 8) & 0xff,
                           colour & 0xff, 255);
    SDL_Util::DrawCircle(renderX + (Constants::TILESIZE / 2),
                         renderY + (Constants::TILESIZE / 2),
                         Constants::TILESIZE / 3);
  }
}
