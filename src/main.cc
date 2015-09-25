#include <iostream>
#include "labyrinth.h"
#include "io.h"

#include "point.h"
#include "point.impl.h"

int main(int argc, char** argv){
    int width = 0;
    int height = 0;
    std::vector<std::string> map;
    
    readFile(width, height, map);

    // todo
    //    Labyrinth lab =  Labyrinth(width, height, map);
    
    Matrix<char> mat(width, height);
    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            mat.set(i, j, '1');
        }
    }
    
    std::cout << mat << std::endl;

    Point<unsigned int> point(10, 10), point2(10, 10);

    std::cout << point.getX() << std::endl;
    std::cout << point.getY() << std::endl;

    if (point == point2) std::cout << "Equals" << std::endl;
    
    
    return 0;
}
