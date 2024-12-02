#include "first_star_task.h"
#include <cmath>

bool isSafe(const std::vector<int>& report) {
    if (report.size() <= 1) return true;

    bool isIncreasing = report[1] > report[0];
    bool isDecreasing = report[1] < report[0];

    for (size_t i = 1; i < report.size(); ++i) {
        int difference = report[i] - report[i - 1];
        if (abs(difference) < 1 || abs(difference) > 3) return false;
        if (isIncreasing && difference < 0) return false;
        if (isDecreasing && difference > 0) return false;
    }

    return true;
}
