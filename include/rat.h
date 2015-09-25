#ifndef RAT_H
#define RAT_H

#include "dynamic_stack.h"
#include "dynamic_stack.impl.h"

#include "point.h"
#include "point.impl.h"

class Rat {
    enum Moves {
        LEFT=0,
        RIGHT,
        UP,
        DOWN
    };

    struct Movement {
        Point<unsigned int> pos;
        bool ateCheese;
    };


public:
    Rat() {}
    Rat(const Point<unsigned int>& point);

    


private:
    void _move(const Point<unsigned int>& point, const bool& ateCheese);
    void _rewindMove();
    
private:
    Point<unsigned int> _pos;
    unsigned int _cheese;
    unsigned int _totalMoves;
    de::Stack<Movement> _moves;
};
#endif//RAT_H
