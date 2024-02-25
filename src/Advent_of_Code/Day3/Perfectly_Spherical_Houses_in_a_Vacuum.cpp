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
    std::pair<int8_t, int8_t> positions[2] = {{0, 0}, {0, 0}};
    std::map<std::pair<int8_t, int8_t>, uint8_t> previousYearHousePresents, currentYearHousePresents;

    previousYearHousePresents[std::make_pair(previousYearHousePosX, previousYearHousePosY)] = 1;
    currentYearHousePresents[positions[0]] = 2;

    int currentCharacter = 0;

    for (const uint8_t towards: directions) {
        switch (towards) {
            case NORTH:
                previousYearHousePosY++;
                positions[currentCharacter].second++;
                break;
            case EAST:
                previousYearHousePosX++;
                positions[currentCharacter].first++;
                break;
            case SOUTH:
                previousYearHousePosY--;
                positions[currentCharacter].second--;
                break;
            case WEST:
                previousYearHousePosX--;
                positions[currentCharacter].first--;
                break;
            default:
                throw std::runtime_error("Unknown enum!");
        }

        currentYearHousePresents[positions[currentCharacter]]++;
        currentCharacter = 1 - currentCharacter;

        previousYearHousePresents[std::make_pair(previousYearHousePosX, previousYearHousePosY)]++;
    }

    return std::make_tuple(previousYearHousePresents.size(), currentYearHousePresents.size());
}
