#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <string>
#include <vector>

class Labyrinth {
public:
    Labyrinth(const int& width, const int& height, const std::vector<std::string>& map);
private:
    std::vector<std::vector<char> > _data;
};


#endif//LABYRINTH_H
