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
        Point2U pos;
        bool ateCheese;

        bool operator==(const Movement& other) {
            if (pos == other.pos)
                return true;
            return false;           
        }
    };


public:
    Rat() {}
    Rat(const Point2U& point);
    
    void move(Move move);

    void moveFoward(const Point2U& pos, const bool& ateCheese);
    void moveBackwards();
    
    Point2U getPosition() const;
    void setPosition(const Point2U& p);

    inline Point2U getLast(){
        return _moves.getTopElement().pos;
    }
    
    void report();
private:
    void _moveFoward(const Point2U& point, const bool& ateCheese);
    void _rewindMove();
    
private:
    Point2U _pos;
    unsigned int _cheese;
    unsigned int _totalMoves;
    de::Stack<Movement> _moves;
};
#endif//RAT_H
