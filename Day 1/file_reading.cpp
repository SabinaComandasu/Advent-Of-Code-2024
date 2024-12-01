#include "tasks.h"
#include <fstream>
#include <iostream>

void readDataFromFile(const std::string& filename, std::vector<int>& firstList, std::vector<int>& secondList) {
    std::ifstream inputFile(filename);
    int x, y;

    if (inputFile.is_open()) {
        while (inputFile >> x >> y) {
            firstList.push_back(x);
            secondList.push_back(y);
        }
        inputFile.close();
    }
    else {
        std::cerr << "ERROR: Couldn't open file!" << std::endl;
    }
}
