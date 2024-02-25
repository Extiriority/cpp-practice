//
// Created by Amy on 25-2-2024.
//

#include "Perfectly_Spherical_Houses_in_a_Vacuum.h"

#include <cstdint>
#include <map>
#include <stdexcept>
#include <vector>

enum compass { NORTH = '^', EAST = '>', SOUTH = 'v', WEST = '<' };
enum location { START = 0 };

std::tuple<uint32_t, uint32_t> Perfectly_Spherical_Houses_in_a_Vacuum::calculateTotalHousesWithPresent(
    const std::string &directions) {

    int8_t previousYearHousePosX = 0, previousYearHousePosY = 0;
    std::pair<int8_t, int8_t> previousYearHousePos[1] = {{0, 0}};
    std::pair<int8_t, int8_t> currentYearHousePos[2] = {{0, 0}, {0, 0}};

    std::map<std::pair<int8_t, int8_t>, uint8_t> previousYearHousePresents, currentYearHousePresents;

    previousYearHousePresents[std::make_pair(previousYearHousePosX, previousYearHousePosY)] = 1;
    currentYearHousePresents[currentYearHousePos[0]] = 2;

    int currentCharacter = 0;

    for (const uint8_t towards: directions) {
        switch (towards) {
            case NORTH:
                previousYearHousePos->second++;
                currentYearHousePos[currentCharacter].second++;
                break;
            case EAST:
                previousYearHousePos->first++;
                currentYearHousePos[currentCharacter].first++;
                break;
            case SOUTH:
                previousYearHousePos->second--;
                currentYearHousePos[currentCharacter].second--;
                break;
            case WEST:
                previousYearHousePos->first--;
                currentYearHousePos[currentCharacter].first--;
                break;
            default:
                throw std::runtime_error("Unknown enum!");
        }

        currentYearHousePresents[currentYearHousePos[currentCharacter]]++;
        currentCharacter = 1 - currentCharacter;

        previousYearHousePresents[*previousYearHousePos]++;
    }

    return std::make_tuple(previousYearHousePresents.size(), currentYearHousePresents.size());
}
