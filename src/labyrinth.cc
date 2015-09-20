#include "labyrinth.h"

Labyrinth::Labyrinth(const int& width, const int& height, const std::vector<std::string>& map)
    :_data(width, height)
{

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            _data.set(i, j, map[i][j]);
        }
    }
}

bool Labyringht::isCheese(const unsigned int& x, const unsigned int& y) const {
    return _data.get(x, y) == 'Q';
}

bool Labyringht::isEntrance(const unsigned int& x, const unsigned int& y) const {
    return _data.get(x, y) == 'E';
}

bool Labyringht::isExit(const unsigned int& x, const unsigned int& y) const {
    return _data.get(x, y) == 'S';
}

bool Labyringht::isWall(const unsigned int& x, const unsigned int& y) const {
    return _data.get(x, y) == '1';
}

bool Labyringht::isPath(const unsigned int& x, const unsigned int& y) const {
    return _data.get(x, y) == '0';
}

