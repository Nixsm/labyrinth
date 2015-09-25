#include <iostream>
#include <fstream>
#include <vector>
#include <sys/stat.h>
#include "../include/io.h"

inline bool fileExists(const std::string& filename){
    return (access(filename.c_str(), F_OK) != -1);
}

void readFile(int &width, int &height, std::vector<std::string> &map){
    std::string filename;
    
    std::cout << "Filename: ";
    std::cin >> filename;

    if (!fileExists(filename)){
        std::cout << "Error, file does not exist.\n";
        exit(1);
    }
    std::ifstream infile(filename);

    // get first line with w/h
    while (infile >> width >> height){
        break;
    };

    std::string dummyString;
    getline(infile, dummyString); // get rid of the first line.

    for (std::string line; getline(infile, line);){
        map.push_back(line);
        std::cout << line;
    }
}
