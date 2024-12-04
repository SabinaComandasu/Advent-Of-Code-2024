#include "file_reading.h"
#include <fstream>
#include <iostream>

std::vector<std::string> readGridFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return {};
    }

    std::vector<std::string> grid;
    std::string line;

    while (std::getline(file, line)) {
        grid.push_back(line);
    }
    file.close();

    return grid;
}
