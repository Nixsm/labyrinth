#include "labyrinth.h"

Labyrinth::Labyrinth(const int& width, const int& height, const std::vector<std::string>& map)
    :_data(std::vector<char>(width, std::vector<char>(height, '1')))
{
    for (auto& line : map) {
        for (auto& ch : line) {
            
        }
    }
}
