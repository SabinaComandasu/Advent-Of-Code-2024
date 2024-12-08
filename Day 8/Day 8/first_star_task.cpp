#include "first_star_task.h"
#include <unordered_map>
#include <set>
#include <utility>

bool in_bounds(const std::pair<int, int>& pos, int w, int h) {
    int i = pos.first;
    int j = pos.second;
    return i >= 0 && i < h && j >= 0 && j < w;
}

size_t calculate_unique_antinodes_v1(const std::vector<std::vector<char>>& input_data) {
    int width = input_data[0].size();
    int height = input_data.size();

    std::unordered_map<char, std::vector<std::pair<int, int>>> antennas;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            char freq = input_data[i][j];
            if (freq != '.') {
                antennas[freq].emplace_back(i, j);
            }
        }
    }

    std::set<std::pair<int, int>> unique_antinodes;
    for (const auto& [frequency, positions] : antennas) {
        size_t n = positions.size();
        for (size_t a = 0; a < n; ++a) {
            for (size_t b = a + 1; b < n; ++b) {
                const auto& pos_a = positions[a];
                const auto& pos_b = positions[b];

                int slope_i = pos_b.first - pos_a.first;
                int slope_j = pos_b.second - pos_a.second;

                std::pair<int, int> antinode1 = { pos_a.first - slope_i, pos_a.second - slope_j };
                std::pair<int, int> antinode2 = { pos_b.first + slope_i, pos_b.second + slope_j };

                if (in_bounds(antinode1, width, height)) {
                    unique_antinodes.insert(antinode1);
                }
                if (in_bounds(antinode2, width, height)) {
                    unique_antinodes.insert(antinode2);
                }
            }
        }
    }

    return unique_antinodes.size();
}
