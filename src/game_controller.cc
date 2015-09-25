#include "game_controller.h"

GameController::GameController(const unsigned int& width, const unsigned int& height, const std::vector<std::string>& map)
    :_labyrinth(width, height, map)
{
    _rat = Rat(_labyrinth.getStart());
    _rat.moveFoward(false);
}

bool GameController::isExit() {
    return _labyrinth.isExit(_rat.getPosition());
}

void GameController::ratMove() {
    std::vector<Rat::Move> moves = { Rat::Move::RIGHT, Rat::Move::DOWN, Rat::Move::UP, Rat::Move::LEFT };

    for (auto& move : moves) {
        const auto& beforePos = _rat.getPosition();
        _rat.move(move);
        const auto& currentPos = _rat.getPosition();

        if (!_labyrinth.isValid(currentPos) || _rat.beenThere(currentPos)) { //If we are not valid rewind, this is a Labyrinth pos check not movement
            _rat.setPosition(beforePos);
            continue;
        }

        _rat.moveFoward(_labyrinth.isCheese(currentPos));

        if (_labyrinth.isWall(currentPos) || _labyrinth.isEntrance(currentPos)) { // If its a wall we cant move
            _rat.moveBackwards();
        }
        if (_labyrinth.isPath(currentPos) || _labyrinth.isExit(currentPos)) { // Found our path just exit it
            break;
        }
    }
}

void GameController::report() {
    _rat.report();
}
