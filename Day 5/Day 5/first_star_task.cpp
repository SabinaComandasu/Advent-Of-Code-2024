#include "first_star_task.h"
#include <unordered_map>

bool ruleCheck(const std::vector<int>& update, const std::vector<std::pair<int, int>>& rules) {
    std::unordered_map<int, int> positionMap;
    for (size_t i = 0; i < update.size(); ++i) {
        positionMap[update[i]] = i;
    }

    for (const auto& rule : rules) {
        int A = rule.first;
        int B = rule.second;

        if (positionMap.count(A) && positionMap.count(B)) {
            if (positionMap[A] >= positionMap[B]) {
                return false;
            }
        }
    }

    return true;
}

int correctMidPagesSum(const std::vector<std::vector<int>>& updates, const std::vector<std::pair<int, int>>& rules) {
    int sumOfMiddlePages = 0;

    for (const auto& update : updates) {
        if (ruleCheck(update, rules)) {
            size_t size = update.size();
            int middlePage = update[size / 2];
            sumOfMiddlePages += middlePage;
        }
    }

    return sumOfMiddlePages;
}
