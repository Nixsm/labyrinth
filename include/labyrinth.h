#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <string>
#include <vector>
#include "matrix.h"
#include "matrix.impl.h"

#include "point.h"
#include "point.impl.h"

class Labyrinth {
public:
    Labyrinth(const int& width, const int& height, const std::vector<std::string>& map);

    bool isCheese(const Point<unsigned int>& point) const;
    bool isEntrance(const Point<unsigned int>& point) const;
    bool isExit(const Point<unsigned int>& point) const;
    bool isWall(const Point<unsigned int>& point) const;
    bool isPath(const Point<unsigned int>& point) const;

    Point<unsigned int> getStart() const;
private:
    Matrix<char> _data;
    Point<unsigned int> _start;
};


#endif//LABYRINTH_H
