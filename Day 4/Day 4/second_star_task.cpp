#include "second_star_task.h"

bool has_xmas(const std::vector<std::string>& lines, int i, int j) {
    int n = lines.size();
    int m = lines[0].size();

    if (!(1 <= i && i < n - 1 && 1 <= j && j < m - 1)) {
        return false;
    }
    if (lines[i][j] != 'A') {
        return false;
    }

    std::string diag_1 = { lines[i - 1][j - 1], lines[i + 1][j + 1] };
    std::string diag_2 = { lines[i - 1][j + 1], lines[i + 1][j - 1] };

    return (diag_1 == "MS" || diag_1 == "SM") && (diag_2 == "MS" || diag_2 == "SM");
}

int countXmasPatterns(const std::vector<std::string>& grid) {
    int xmasCount = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            xmasCount += has_xmas(grid, i, j);
        }
    }
    return xmasCount;
}
