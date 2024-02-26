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
enum helpers { SANTA = 1, SANTA_AND_ROBO = 2 };

std::tuple<uint32_t, uint32_t> Perfectly_Spherical_Houses_in_a_Vacuum::calculateTotalHousesWithPresent(
    const std::string &directions) {

    std::pair<int8_t, int8_t> prevYearHousePos[SANTA]          = {{START, START}};
    std::pair<int8_t, int8_t> currYearHousePos[SANTA_AND_ROBO] = {{START, START}, {START, START}};

    std::map<std::pair<int8_t, int8_t>, uint8_t> prevYearHousePresents, currYearHousePresents;

    prevYearHousePresents[prevYearHousePos[START]] = 1;
    currYearHousePresents[currYearHousePos[START]] = 2;

    int currentCharacter = 0;

    for (const uint8_t towards: directions) {
        switch (towards) {
            case NORTH:
                prevYearHousePos->second++;
                currYearHousePos[currentCharacter].second++;
                break;
            case EAST:
                prevYearHousePos->first++;
                currYearHousePos[currentCharacter].first++;
                break;
            case SOUTH:
                prevYearHousePos->second--;
                currYearHousePos[currentCharacter].second--;
                break;
            case WEST:
                prevYearHousePos->first--;
                currYearHousePos[currentCharacter].first--;
                break;
            default:
                throw std::runtime_error("Unknown enum!");
        }

        prevYearHousePresents[*prevYearHousePos]++;

        currYearHousePresents[currYearHousePos[currentCharacter]]++;
        currentCharacter = 1 - currentCharacter;
    }

    return std::make_tuple(prevYearHousePresents.size(), currYearHousePresents.size());
}
