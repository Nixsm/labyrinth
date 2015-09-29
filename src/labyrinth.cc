#include "labyrinth.h"

#include <algorithm>

Labyrinth::Labyrinth(const int& width, const int& height, const std::vector<std::string>& map)
    :_data(width, height), _visited(width, height)
{

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            _visited.set(i, j, false); //None visited yet
            _data.set(i, j, map[i][j]);
            if (_data.get(i, j) == 'E') {
                _start = Point2U(i, j);
            }
        }
    }
}

bool Labyrinth::isValid(const Point2U& point) const {
    return _data.valid(point);
}

bool Labyrinth::isCheese(const Point2U& point) const {
    return _data.get(point) == 'Q';
}

bool Labyrinth::isEntrance(const Point2U& point) const {
    return _data.get(point) == 'E';
}

bool Labyrinth::isExit(const Point2U& point) const {
    return _data.get(point) == 'S';
}

bool Labyrinth::isWall(const Point2U& point) const {
    return _data.get(point) == '1';
}

bool Labyrinth::isPath(const Point2U& point) const {
    return _data.get(point) == '0';
}

Point2U Labyrinth::getStart() const {
    return _start;
}


bool Labyrinth::checkRight(const Point2U &point) const {
    auto right = point + Point2U(1, 0);

    if (isWall(right)) return false;

    return true;
}
bool Labyrinth::checkLeft(const Point2U &point) const {
    auto left = point + Point2U(-1, 0);

    if (isWall(left)) return false;

    return true;
}

bool Labyrinth::checkUp(const Point2U &point) const {
    auto up = point + Point2U(0, 1);

    if (isWall(up)) return false;

    return true;
}

bool Labyrinth::checkDown(const Point2U &point) const {
    auto down = point + Point2U(0, -1);

    if (isWall(down)) return false;

    return true;
}

void Labyrinth::setVisited(const Point2U& point) {
    _visited.set(point, true);
}

bool Labyrinth::visited(const Point2U& point) const {
    return _visited.get(point); 
}

bool Labyrinth::getNeighbor(const Point2U& point, Point2U& neighbor) const {
    auto down = point + Point2U(0, -1);
    auto up = point + Point2U(0, 1);
    auto left = point + Point2U(-1, 0);
    auto right = point + Point2U(1, 0);
    auto dright = down + Point2U(1, 0);
    auto dleft = down + Point2U(-1, 0);
    auto uright = up + Point2U(1, 0);
    auto uleft = up + Point2U(-1, 0);
    
    std::vector<Point2U> moves = {down, up, left, right, dright, dleft, uright, uleft};

    for (auto& move : moves) {
        if (isValid(move))
            if (!visited(move) && !isWall(move))  {
                neighbor = move;
                return true;
        }
    }
    return false;
}
