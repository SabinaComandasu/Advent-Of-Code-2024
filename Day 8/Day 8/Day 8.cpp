#include <iostream>
#include "file_reading.h"
#include "first_star_task.h"
#include "second_star_task.h"

int main() {
    try {
        std::vector<std::vector<char>> input_data = read_input("input.txt");

        size_t result_v1 = calculate_unique_antinodes_v1(input_data);
        size_t result_v2 = calculate_unique_antinodes_v2(input_data);

        std::cout << "Unique locations within the bounds of the map containing an antinode: " << result_v1 << std::endl;
        std::cout << "\nUnique locations within the bounds of the map containing an antinode using the updated model: " << result_v2 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
