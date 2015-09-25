#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "rat.h"
#include "labyrinth.h"

class GameController {
public:
    GameController() {}
    GameController(const unsigned int& width, const unsigned int& height, const std::vector<std::string>& map);

    bool isExit();
    void ratMove();
    void report();
private:
    Rat _rat;
    Labyrinth _labyrinth;
};

#endif//GAME_CONTROLLER_H
