#include "file_reading.h"
#include <fstream>
#include <sstream>
#include <iostream>

void readInput(const std::string& filename, std::vector<std::pair<int, int>>& rules, std::vector<std::vector<int>>& updates) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    bool readingRules = true;

    while (std::getline(file, line)) {
        if (line.empty()) {
            readingRules = false;
            continue;
        }

        if (readingRules) {
            std::istringstream iss(line);
            int A, B;
            char delimiter;
            if (iss >> A >> delimiter >> B) {
                rules.emplace_back(A, B);
            }
        }
        else {
            std::vector<int> update;
            std::istringstream iss(line);
            std::string token;
            while (std::getline(iss, token, ',')) {
                update.push_back(std::stoi(token));
            }
            updates.push_back(update);
        }
    }

    file.close();
}
