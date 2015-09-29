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
    Labyrinth() {}
    Labyrinth(const int& width, const int& height, const std::vector<std::string>& map);

    bool isValid(const Point2U& point) const;
    bool isCheese(const Point2U& point) const;
    bool isEntrance(const Point2U& point) const;
    bool isExit(const Point2U& point) const;
    bool isWall(const Point2U& point) const;
    bool isPath(const Point2U& point) const;
    bool checkRight(const Point2U &point) const;
    bool checkLeft(const Point2U &point) const;
    bool checkUp(const Point2U &point) const;
    bool checkDown(const Point2U &point) const;

    bool getNeighbor(const Point2U& point, Point2U& neighbor) const;
    
    void setVisited(const Point2U& point);
    bool visited(const Point2U& point) const;
    Point2U getStart() const;
private:
    Matrix<char> _data;
    Matrix<bool> _visited;
    Point2U _start;
};


#endif//LABYRINTH_H
