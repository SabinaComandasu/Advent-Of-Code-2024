#include "file_reading.h"
#include <fstream>
#include <stdexcept>

std::vector<std::vector<char>> read_input(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open input file.");
    }

    std::vector<std::vector<char>> input_data;
    std::string line;
    while (std::getline(file, line)) {
        input_data.emplace_back(line.begin(), line.end());
    }

    file.close();
    return input_data;
}
