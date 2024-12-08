#ifndef FIRST_STAR_TASK_H
#define FIRST_STAR_TASK_H

#include <vector>
#include <utility>


bool in_bounds(const std::pair<int, int>& pos, int w, int h);

size_t calculate_unique_antinodes_v1(const std::vector<std::vector<char>>& input_data);

#endif // FIRST_STAR_TASK_H
