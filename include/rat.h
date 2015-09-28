#ifndef RAT_H
#define RAT_H

#include "dynamic_stack.h"
#include "dynamic_stack.impl.h"

#include "point.h"
#include "point.impl.h"

class Rat {
public:
    enum Move {
        LEFT=0,
        RIGHT,
        UP,
        DOWN
    };
private:
    struct Movement {
        Point<unsigned int> pos;
        bool ateCheese;

        bool operator==(const Movement& other) {
            if (pos == other.pos)
                return true;
            return false;           
        }
    };


public:
    Rat() {}
    Rat(const Point<unsigned int>& point);
    
    void move(Move move);

    void moveFoward(const bool& ateCheese);
    void moveBackwards();
    
    Point<unsigned int> getPosition() const;
    void setPosition(const Point<unsigned int>& p);

    bool beenThere(const Point<unsigned int>& p);

    // todo, move from here
    Point<unsigned int> getLast(){
        return _moves.getTopElement().pos;
    }
    
    void report();
private:
    void _moveFoward(const Point<unsigned int>& point, const bool& ateCheese);
    void _rewindMove();
    
private:
    Point<unsigned int> _pos;
    unsigned int _cheese;
    unsigned int _totalMoves;
    de::Stack<Movement> _moves;
};
#endif//RAT_H
