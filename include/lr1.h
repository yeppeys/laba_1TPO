#pragma once

#include <vector>
#include <string>
#include <map>

struct Data {
public:
    std::vector<int> input;
    int sum = 0;
    std::vector<int> result;
    std::map<std::string, std::vector<std::string>> errors;

    template<typename T>
    void foreach(const std::vector<T> &array, void (*func)(Data&, T&)){
        for (T element : array) {
            func(*this, element);
        }
    }
};

Data Solution(const std::vector<std::string>& testData);
bool checkOddDigitsIn(int number);
