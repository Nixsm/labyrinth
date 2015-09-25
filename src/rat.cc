#include "rat.h"
#include <vector>

Rat::Rat(const Point<unsigned int>& point)
    :_pos(point), _cheese(0u), _totalMoves(0u) 
{

}

Point<unsigned int> Rat::getPosition() const {
    return _pos;
}

void Rat::setPosition(const Point<unsigned int>& p) {
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

void Rat::moveFoward(const bool& ateCheese) {
    _moveFoward(_pos, ateCheese);
}

void Rat::moveBackwards() {
    _rewindMove();
}

void Rat::_moveFoward(const Point<unsigned int>& point, const bool& ateCheese) {
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

bool Rat::beenThere(const Point<unsigned int>& p) {
    Movement move;
    move.pos = p;
    
    if (_moves.elementExists(move)) {
        return true;
    }

    return false;
}

void Rat::report() {

    std::cout << "Total moves: " << _totalMoves << std::endl;

    std::cout << "Moves until exit: " << _moves.size() << std::endl;

    // HACK
    std::vector<Point<unsigned int> > points; //Workaround to invert
    
    while (!_moves.isEmpty()) {
        const auto& topElement = _moves.getTopElement();

        

        points.push_back(topElement.pos + Point<unsigned int>(1, 1));
        _moves.remove();
    }

    for (auto it = points.rbegin(); it != points.rend(); ++it) {
        std::cout << "I passed by: " << *it << std::endl; //Add +1, +1 to show
    }
    

    std::cout << "Ate " << _cheese << " cheeses." << std::endl;
    
}
