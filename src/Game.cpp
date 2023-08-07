#include "Game.hpp"

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "App.hpp"

Game::Game() {
  srand(time(NULL));
  init();
}

void Game::update() {}

void Game::render() const {
  SDL_SetRenderDrawColor(App::getRenderer(), 255, 255, 255, 255);
  SDL_RenderClear(App::getRenderer());

  renderBoardSquare();

  board.renderPieces();

  SDL_RenderPresent(App::getRenderer());
}

void Game::init() {
  // Restart game
  state = STATE::RUNNING;
}

void Game::klikk(int x, int y) {
  // klikk
  playerManager.klikk(x + y * 8);
  // std::cout << "Piece: " << board[x + y * 8]->piece << "\n";
}

void Game::renderBoardSquare() const {
  SDL_Rect rect;
  for (int y = 0; y < 8; y++) {
    for (int x = 0; x < 8; x++) {
      int colour = ((x + y) % 2 == 0) ? 0xa87951 : 0xddcfc3;
      rect.x = x * Constants::TILESIZE;
      rect.y = y * Constants::TILESIZE;
      rect.w = Constants::TILESIZE;
      rect.h = Constants::TILESIZE;

      SDL_SetRenderDrawColor(App::getRenderer(), colour >> 16,
                             (colour >> 8) & 0xff, colour & 0xff, 255);
      SDL_RenderFillRect(App::getRenderer(), &rect);
    }
  }
}
