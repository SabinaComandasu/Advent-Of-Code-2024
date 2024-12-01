#ifndef TASKS_H
#define TASKS_H

#include <vector>
#include <unordered_map>
#include <string>

void readDataFromFile(const std::string& filename, std::vector<int>& firstList, std::vector<int>& secondList);
void calculateFrequency(const std::vector<int>& secondList, std::unordered_map<int, int>& frequencyMap);
void calculateSimilarityScore(const std::vector<int>& firstList, const std::vector<int>& auxiliaryList, int& similarityScore);
void sortLists(std::vector<int>& firstList, std::vector<int>& secondList);
int calculateTotalDistance(const std::vector<int>& firstList, const std::vector<int>& secondList);
void processFrequencyAndSimilarity(const std::vector<int>& firstList, const std::vector<int>& secondList,
    std::unordered_map<int, int>& frequencyMap,
    std::vector<int>& auxiliaryList, int& similarityScore);

#endif
