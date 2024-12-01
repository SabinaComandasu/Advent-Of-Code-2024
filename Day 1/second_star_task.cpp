#include "tasks.h"
#include <unordered_map>

void calculateFrequency(const std::vector<int>& secondList, std::unordered_map<int, int>& frequencyMap) {
    for (int num : secondList) {
        frequencyMap[num]++;
    }
}

void calculateSimilarityScore(const std::vector<int>& firstList, const std::vector<int>& auxiliaryList, int& similarityScore) {
    similarityScore = 0;
    for (size_t i = 0; i < firstList.size(); ++i) {
        similarityScore += firstList[i] * auxiliaryList[i];
    }
}

void processFrequencyAndSimilarity(const std::vector<int>& firstList, const std::vector<int>& secondList,
    std::unordered_map<int, int>& frequencyMap,
    std::vector<int>& auxiliaryList, int& similarityScore) {
    calculateFrequency(secondList, frequencyMap);

    auxiliaryList.resize(firstList.size());
    for (size_t i = 0; i < firstList.size(); ++i) {
        int ai = firstList[i];
        auxiliaryList[i] = frequencyMap[ai];
    }

    calculateSimilarityScore(firstList, auxiliaryList, similarityScore);
}
