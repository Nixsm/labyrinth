#ifndef GAME_H
#define GAME_H

#include "game_controller.h"
#include <memory>

class Game {
public:
    Game();
    
    void start();

private:
    std::shared_ptr<GameController> _gc;
};

#endif//GAME_H
