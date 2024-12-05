#include "second_star_task.h"
#include "first_star_task.h" 
#include <unordered_map>
#include <unordered_set>
#include <queue>

std::vector<int> reorderUpdate(const std::vector<int>& update, const std::vector<std::pair<int, int>>& rules) {
    std::unordered_map<int, std::vector<int>> graph;
    std::unordered_map<int, int> inDegree;

    for (int page : update) {
        inDegree[page] = 0;
    }

    for (const auto& rule : rules) {
        int A = rule.first;
        int B = rule.second;

        if (inDegree.count(A) && inDegree.count(B)) {
            graph[A].push_back(B);
            inDegree[B]++;
        }
    }

    std::queue<int> q;
    for (const auto& entry : inDegree) {
        if (entry.second == 0) {
            q.push(entry.first);
        }
    }

    std::vector<int> sortedOrder;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        sortedOrder.push_back(current);

        for (int neighbor : graph[current]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    std::unordered_set<int> sortedSet(sortedOrder.begin(), sortedOrder.end());
    for (int page : update) {
        if (!sortedSet.count(page)) {
            sortedOrder.push_back(page);
        }
    }

    return sortedOrder;
}

int sumReorderedMiddlePages(const std::vector<std::vector<int>>& updates, const std::vector<std::pair<int, int>>& rules) {
    int sumOfMiddlePages = 0;

    for (const auto& update : updates) {
        if (!ruleCheck(update, rules)) { 
            std::vector<int> reordered = reorderUpdate(update, rules);

            size_t size = reordered.size();
            int middlePage = reordered[size / 2];
            sumOfMiddlePages += middlePage;
        }
    }

    return sumOfMiddlePages;
}
