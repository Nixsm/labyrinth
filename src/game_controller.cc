#include "game_controller.h"

GameController::GameController(const unsigned int& width, const unsigned int& height, const std::vector<std::string>& map)
    :_labyrinth(width, height, map), _rat(_labyrinth.getStart())
{
    
}
