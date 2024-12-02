#include <iostream>
#include "file_reading.h"
#include "first_star_task.h"
#include "second_star_task.h"

int main() {
    std::vector<std::vector<int>> input = readInputFile("input.txt");
    int reportsThatAreSafe = 0;

    for (const auto& report : input) {
        if (isSafe(report) || second_star_task(report)) {
            reportsThatAreSafe++;
        }
    }

    std::cout << "Total number of safe reports: " << reportsThatAreSafe << std::endl;

    return 0;
}
