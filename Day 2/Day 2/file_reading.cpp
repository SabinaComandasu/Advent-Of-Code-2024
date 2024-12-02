#include "file_reading.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::vector<std::vector<int>> readInputFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    std::string line;
    std::vector<std::vector<int>> data;

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return data;
    }

    while (getline(inputFile, line)) {
        std::stringstream ss(line);
        std::vector<int> report;
        int num;
        while (ss >> num) {
            report.push_back(num);
        }
        data.push_back(report);
    }

    inputFile.close();
    return data;
}
