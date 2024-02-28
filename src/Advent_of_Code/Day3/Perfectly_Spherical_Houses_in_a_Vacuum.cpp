//
// Created by Amy on 25-2-2024.
//

#include "Perfectly_Spherical_Houses_in_a_Vacuum.h"

#include <cstdint>
#include <unordered_map>
#include <stdexcept>
#include <vector>

using PresentCount = uint8_t;

enum compass { NORTH = '^', EAST = '>', SOUTH = 'v', WEST = '<' };
enum location { START_POS = 0 };
enum helpers { SANTA = 1, SANTA_AND_ROBO = 2 };

struct Coordinate {
    int8_t x, y;

    bool operator==(const Coordinate&axis) const {
        return x == axis.x && y == axis.y;
    }
};

struct CoordinateHash {
    std::size_t operator()(const Coordinate&axis) const {
        const auto x = std::hash<int8_t>{}(axis.x);
        const auto y = std::hash<int8_t>{}(axis.y);

        return x ^ y;
    }
};

std::tuple<uint32_t, uint32_t> Perfectly_Spherical_Houses_in_a_Vacuum::calculateTotalHousesWithPresent(
    const std::string&directions) {
    Coordinate prevYearHousePos[SANTA]          = {{START_POS, START_POS}};
    Coordinate currYearHousePos[SANTA_AND_ROBO] = {{START_POS, START_POS}, {START_POS, START_POS}};

    std::unordered_map<Coordinate, PresentCount, CoordinateHash> prevYearHousePresents, currYearHousePresents;

    prevYearHousePresents[prevYearHousePos[START_POS]] = 1;
    currYearHousePresents[currYearHousePos[START_POS]] = 2;

    int currentCharacter = 0;

    for (const uint8_t towards: directions) {
        switch (towards) {
            case NORTH:
                prevYearHousePos->y++;
                currYearHousePos[currentCharacter].y++;
                break;
            case EAST:
                prevYearHousePos->x++;
                currYearHousePos[currentCharacter].x++;
                break;
            case SOUTH:
                prevYearHousePos->y--;
                currYearHousePos[currentCharacter].y--;
                break;
            case WEST:
                prevYearHousePos->x--;
                currYearHousePos[currentCharacter].x--;
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
