#include "tasks.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

void sortLists(std::vector<int>& firstList, std::vector<int>& secondList) {
    std::sort(firstList.begin(), firstList.end());
    std::sort(secondList.begin(), secondList.end());
}

int calculateTotalDistance(const std::vector<int>& firstList, const std::vector<int>& secondList) {
    std::vector<int> distanceList(firstList.size());
    std::transform(firstList.begin(), firstList.end(), secondList.begin(), distanceList.begin(), [](int ai, int bi) {
        return std::abs(ai - bi);
        });
    return std::accumulate(distanceList.begin(), distanceList.end(), 0);
}
