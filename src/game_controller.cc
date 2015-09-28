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
    Point<unsigned int> ratPos = _rat.getPosition();
    //_rat.moveFoward(false);
    de::Stack<Point<unsigned int> > movedPaths;
    std::vector<Point<unsigned int> > visited; 
    
    movedPaths.insert(ratPos);
    while (!_labyrinth.isExit(ratPos)){
        ratPos = _rat.getLast();
        visited.push_back(lastValue);
        
        if (!visited.elementExists(lastValue)){
            if (_labyrinth.checkRight(ratPos)){
                movedPaths.insert(ratPos); // todo, test this shit.
            }
            else if (_labyrinth.checkLeft(ratPos)){
                movedPaths.insert(ratPos); // todo, test this shit.
            }
            else if (_labyrinth.checkUp(ratPos)){
                movedPaths.insert(ratPos); // todo, test this shit.
            }
            else if (_labyrinth.checkDown(ratPost)){
                movedPaths.insert(ratPos); // todo, test this shit.
            }
        }
        else {
            auto tmp = std::find(visited.begin(), visited.end(), ratPos);
            if (tmp != visited.end()){
                visited.erase(tmp);                
            }
            movedPaths.remove();
        }
    }    
}

void GameController::report() {
    _rat.report();
}
