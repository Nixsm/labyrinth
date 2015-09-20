#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <string>
#include <vector>
#include "matrix.h"
#include "matrix.impl.h"

class Labyrinth {
public:
    Labyrinth(const int& width, const int& height, const std::vector<std::string>& map);

    bool isCheese(const unsigned int& x, const unsigned int& y) const;
private:
    Matrix<char> _data;
};


#endif//LABYRINTH_H
