#include "first_star_task.h"

int countWord(const std::vector<std::string>& grid, const std::string& word, int x, int y, int dx, int dy) {
    for (int i = 0; i < word.length(); i++) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].length() || grid[x][y] != word[i]) {
            return 0;
        }
        x += dx;
        y += dy;
    }
    return 1;
}

int countWordInGrid(const std::vector<std::string>& grid, const std::string& word) {
    int totalCount = 0;
    std::vector<std::pair<int, int>> directions = {
        {0, 1}, {1, 0}, {1, 1}, {-1, 1},
        {0, -1}, {-1, 0}, {-1, -1}, {1, -1}
    };

    for (int x = 0; x < grid.size(); x++) {
        for (int y = 0; y < grid[0].length(); y++) {
            for (const auto& dir : directions) {
                totalCount += countWord(grid, word, x, y, dir.first, dir.second);
            }
        }
    }

    return totalCount;
}
