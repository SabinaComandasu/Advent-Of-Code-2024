#include <iostream>
#include "file_reading.h"
#include "first_star_task.h"
#include "second_star_task.h"

int main() {
    const std::string filename = "input.txt";
    std::vector<std::pair<int, int>> rules;
    std::vector<std::vector<int>> updates;

    readInput(filename, rules, updates);

    int sumOfMiddlePagesValid = correctMidPagesSum(updates, rules);
    std::cout << "Sum of middle pages: " << sumOfMiddlePagesValid << std::endl;

    int sumOfMiddlePagesReordered = sumReorderedMiddlePages(updates, rules);
    std::cout << "Sum of middle pages after reordering: " << sumOfMiddlePagesReordered << std::endl;

    return 0;
}
