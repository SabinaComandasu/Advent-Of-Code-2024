#include "second_star_task.h"
#include <unordered_map>
#include <set>
#include <utility>

bool in_bounds(const std::pair<int, int>& pos, int w, int h); 

size_t calculate_unique_antinodes_v2(const std::vector<std::vector<char>>& input_data) {
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
    for (const auto& pair : antennas) {
        const auto& positions = pair.second;
        size_t n = positions.size();
        for (size_t a = 0; a < n; ++a) {
            for (size_t b = a + 1; b < n; ++b) {
                const auto& pos_a = positions[a];
                const auto& pos_b = positions[b];

                int slope_i = pos_b.first - pos_a.first;
                int slope_j = pos_b.second - pos_a.second;

                std::vector<std::pair<int, int>> antinodes = { pos_a, pos_b };

                for (int i = 1;; ++i) {
                    std::pair<int, int> antinode = { pos_a.first - i * slope_i, pos_a.second - i * slope_j };
                    if (!in_bounds(antinode, width, height)) break;
                    antinodes.push_back(antinode);
                }

                for (int i = 1;; ++i) {
                    std::pair<int, int> antinode = { pos_b.first + i * slope_i, pos_b.second + i * slope_j };
                    if (!in_bounds(antinode, width, height)) break;
                    antinodes.push_back(antinode);
                }

                unique_antinodes.insert(antinodes.begin(), antinodes.end());
            }
        }
    }

    return unique_antinodes.size();
}
