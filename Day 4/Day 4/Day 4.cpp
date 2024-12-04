#include <iostream>
#include "file_reading.h"
#include "first_star_task.h"
#include "second_star_task.h"

int main() {
    const std::string filename = "input.txt";
    auto grid = readGridFromFile(filename);
    if (grid.empty()) {
        return 1;
    }

    const std::string word = "XMAS";

    int totalCount = countWordInGrid(grid, word);
    std::cout << "TASK 1: " << word << "' appears " << totalCount << " times in all directions." << std::endl;

    int xmasCount = countXmasPatterns(grid);
    std::cout << "TASK 2: X-MAS pattern appears " << xmasCount << " times in the grid." << std::endl;

    return 0;
}
