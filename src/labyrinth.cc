#include "labyrinth.h"

Labyrinth::Labyrinth(const int& width, const int& height, const std::vector<std::string>& map)
    :_data(width, height)
{

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            _data.set(i, j, map[i][j]);
            if (_data.get(i, j) == 'E') {
                _start = Point<unsigned int>(i, j);
            }
        }
    }
}

bool Labyrinth::isValid(const Point<unsigned int>& point) const {
    return _data.valid(point);
}

bool Labyrinth::isCheese(const Point<unsigned int>& point) const {
    return _data.get(point) == 'Q';
}

bool Labyrinth::isEntrance(const Point<unsigned int>& point) const {
    return _data.get(point) == 'E';
}

bool Labyrinth::isExit(const Point<unsigned int>& point) const {
    return _data.get(point) == 'S';
}

bool Labyrinth::isWall(const Point<unsigned int>& point) const {
    return _data.get(point) == '1';
}

bool Labyrinth::isPath(const Point<unsigned int>& point) const {
    return _data.get(point) == '0';
}

Point<unsigned int> Labyrinth::getStart() const {
    return _start;
}


bool Labyrinth::checkRight(const Point<unsigned int> &point) const {
    auto right = point + Point<unsigned int>(1, 0);

    if (isWall(right)) return false;

    return true;
}
bool Labyrinth::checkLeft(const Point<unsigned int> &point) const {
    auto left = point + Point<unsigned int>(-1, 0);

    if (isWall(left)) return false;

    return true;
}

bool Labyrinth::checkUp(const Point<unsigned int> &point) const {
    auto up = point + Point<unsigned int>(0, 1);

    if (isWall(up)) return false;

    return true;
}

bool Labyrinth::checkDown(const Point<unsigned int> &point) const {
    auto down = point + Point<unsigned int>(0, -1);

    if (isWall(down)) return false;

    return true;
}

