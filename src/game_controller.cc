#include "game_controller.h"

GameController::GameController(const unsigned int& width, const unsigned int& height, const std::vector<std::string>& map)
    :_labyrinth(width, height, map)
{
    _rat = Rat(_labyrinth.getStart());
}

bool GameController::isExit() {
    return _labyrinth.isExit(_rat.getPosition());
}

void GameController::ratMove() {
    Point<unsigned int> currentCell = _rat.getPosition();

    de::Stack<Point2U> backtrack;
    std::vector<Point2U> path;
    backtrack.insert(currentCell);

    _rat.moveFoward(currentCell, false);
    
    while (!_labyrinth.isExit(currentCell)) {
        currentCell = _rat.getLast();

        _labyrinth.setVisited(currentCell);
        path.push_back(currentCell);

        Point2U neighbor;

        if (_labyrinth.getNeighbor(currentCell, neighbor)) {
            bool ateCheese = false;
            if (_labyrinth.isCheese(neighbor)) ateCheese = true;
            _rat.moveFoward(neighbor, ateCheese);
        } else {
            for (auto it = path.begin(); it != path.end();) {
                if (*it == currentCell) {
                    it = path.erase(it);
                } else {
                    ++it;
                }
            }
            
            _rat.moveBackwards();
        }
        
        
        
    }
}

void GameController::report() {
    _rat.report();
}
