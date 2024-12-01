#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

int main() {
    std::ifstream inputFile("input.txt");
    std::vector<int> firstList, secondList, c;
    int x, y;

    if (inputFile.is_open()) {
        while (inputFile >> x >> y) {
            firstList.push_back(x);
            secondList.push_back(y);
        }
        inputFile.close();
    }
    else {
        std::cerr << "ERROR: Couldn't open file!";
        return 1;
    }

    std::sort(firstList.begin(), firstList.end());
    std::sort(secondList.begin(), secondList.end());

    c.resize(firstList.size());
    std::transform(firstList.begin(), firstList.end(), secondList.begin(), c.begin(), [](int ai, int bi) {
        return std::abs(ai - bi);
        });

    int sum = std::accumulate(c.begin(), c.end(), 0);


    std::cout << "Total distance: " << sum << std::endl;

    return 0;
}
