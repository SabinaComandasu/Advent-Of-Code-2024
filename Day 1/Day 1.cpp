#include "tasks.h"
#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    std::vector<int> firstList, secondList, auxiliaryList;
    std::unordered_map<int, int> frequencyMap;

    readDataFromFile("input.txt", firstList, secondList);

    sortLists(firstList, secondList);

    int sum = calculateTotalDistance(firstList, secondList);
    std::cout << "Total distance: " << sum << std::endl;

    int similarityScore = 0;
    processFrequencyAndSimilarity(firstList, secondList, frequencyMap, auxiliaryList, similarityScore);

    std::cout << "Similarity score: " << similarityScore << std::endl;

    return 0;
}
