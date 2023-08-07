#include "App.hpp"
#include <SDL2/SDL.h>
#include <iostream>

int main() {
  App app;
  if (!app.init()) {
    std::cout << "Failed to init\n";
    return 1;
  }
  app.run();
}
