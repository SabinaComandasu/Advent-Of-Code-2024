#include "second_star_task.h"
#include "first_star_task.h"

bool second_star_task(const std::vector<int>& report) {
    for (size_t i = 0; i < report.size(); ++i) {
        std::vector<int> reportAfterModifications = report;
        reportAfterModifications.erase(reportAfterModifications.begin() + i);
        if (isSafe(reportAfterModifications)) {
            return true;
        }
    }
    return false;
}
