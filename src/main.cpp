#include "Game.h"
#include <exception>
#include <iostream>

int main() {
  try {
    Game game;
    game.run();
  } catch (std::exception &e) {
    std::cerr << "Error " << e.what() << "\n";
  }
  return 0;
}
