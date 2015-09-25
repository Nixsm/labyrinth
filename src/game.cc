#include "game.h"
#include "io.h"

Game::Game() {
    int width, height;
    std::vector<std::string> map;

    IO::readFile(width, height, map);

    _gc = std::make_shared<GameController>(width, height, map);
}

void Game::start() {
    do {
        _gc->ratMove();
    } while (!_gc->isExit());

    _gc->report();
    std::cout << "The end" << std::endl;
}
