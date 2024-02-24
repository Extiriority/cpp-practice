//
// Created by giang on 14 Feb 2024.
//
#include "I_Was_Told_There_Would_Be_No_Math.h"

#include <cstdint>
#include <sstream>

using namespace std;

tuple<uint32_t, uint32_t> I_Was_Told_There_Would_Be_No_Math::CalculateTotalWrapping(const string& input) {
    istringstream ss(input);
    string LENGTH, WIDTH, HEIGHT;
    uint32_t totalPaperInSquareFeet = 0;
    uint32_t totalLintInSquareFeet = 0;

    while (getline(ss, LENGTH, 'x') && getline(ss, WIDTH, 'x') && getline(ss, HEIGHT, '\n')) {
        int dimension[3] {stoi(LENGTH), stoi(WIDTH), stoi(HEIGHT)};

        for (auto swapIndex = 0; swapIndex < 3; swapIndex++) {
            for (auto compareIndex = swapIndex + 1; compareIndex < 3; compareIndex++) {
                if (dimension[swapIndex] > dimension[compareIndex])
                    swap(dimension[swapIndex], dimension[compareIndex]);
            }
        }
        const auto volume = 2*(dimension[0]*dimension[1] + dimension[1]*dimension[2] + dimension[2]*dimension[0]);
        const auto extra = dimension[0] * dimension[1];
        totalPaperInSquareFeet += volume + extra;

        const auto ribbon = 2*(dimension[0] + dimension[1]);
        const auto bow = dimension[0] * dimension[1] * dimension[2];
        totalLintInSquareFeet += ribbon + bow;
    }
    return make_tuple(totalPaperInSquareFeet, totalLintInSquareFeet);
}