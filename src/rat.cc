#include "rat.h"

Rat::Rat(const Point<unsigned int>& point)
    :_pos(point), _cheese(0u), _totalMoves(0u) 
{
    
}


void Rat::_move(const Point<unsigned int>& point, const bool& ateCheese) {
    Movement move;

    move.pos = point;
    move.ateCheese = ateCheese;

    _moves.insert(move);

    if (ateCheese) _cheese++;

    _totalMoves++;
}

void Rat::_rewindMove() {
    const auto topElement = _moves.getTopElement();

    if (topElement.ateCheese) --_cheese;

    _moves.remove();
}
