#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "rat.h"
#include "labyrinth.h"

class GameController {
public:
    GameController(const unsigned int& width, const unsigned int& height, const std::vector<std::string>& map);

private:
    Rat _rat;
    Labyrinth _labyrinth;
};

#endif//GAME_CONTROLLER_H
