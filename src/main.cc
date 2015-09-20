#include <iostream>
#include "labyrinth.h"

int main(int argc, char** argv){
    Matrix<char> mat(10, 10);

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            mat.set(i, j, '1');
        }
    }
    
    std::cout << mat << std::endl;
    
    return 0;
}
