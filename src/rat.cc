#include "rat.h"
#include <vector>

Rat::Rat(const Point2U& point)
    :_pos(point), _cheese(0u), _totalMoves(0u) 
{

}

Point2U Rat::getPosition() const {
    return _pos;
}

void Rat::setPosition(const Point2U& p) {
    _pos = p;
}

void Rat::move(Move move) {
    switch(move) {
    case LEFT:
        _pos.addY(-1);
        break;
    case RIGHT:
        _pos.addY(1);
        break;
    case UP:
        _pos.addX(-1);
        break;
    case DOWN:
        _pos.addX(1);
        break;
    }
}

void Rat::moveFoward(const Point2U& pos, const bool& ateCheese) {
    _moveFoward(pos, ateCheese);
}

void Rat::moveBackwards() {
    _rewindMove();
}

void Rat::_moveFoward(const Point2U& point, const bool& ateCheese) {
    Movement move;

    move.pos = point;
    move.ateCheese = ateCheese;

    _moves.insert(move);

    if (ateCheese) _cheese++;

    _totalMoves++;
}

void Rat::_rewindMove() {
    if (_moves.size() > 0) {
        const auto topElement = _moves.getTopElement();

        if (topElement.ateCheese) --_cheese;

        _moves.remove();
    
        _pos = _moves.getTopElement().pos;
    }
}

void Rat::report() {

    std::cout << "Total moves: " << _totalMoves - 1 << std::endl; // Minus one for entry move

    std::cout << "Moves until exit: " << _moves.size() << std::endl;

    // HACK
    std::vector<Point2U > points; //Workaround to invert
    
    while (!_moves.isEmpty()) {
        const auto& topElement = _moves.getTopElement();

        

        points.push_back(topElement.pos + Point2U(1, 1));
        _moves.remove();
    }

    for (auto it = points.rbegin(); it != points.rend(); ++it) {
        std::cout << "I passed by: " << *it << std::endl; //Add +1, +1 to show
    }
    

    std::cout << "Ate " << _cheese << " cheeses." << std::endl;
    
}
