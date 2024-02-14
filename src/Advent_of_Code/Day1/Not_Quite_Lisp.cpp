//
// Created by giang on 14 Feb 2024.
//

#include <string>

int WhichFloor(const std::string& apartment) {
    int floorPosition = 0;
    constexpr int groundLevel = 0;
    constexpr int basementLevel = -1;

    for (int currentFloorLevel = groundLevel; currentFloorLevel < apartment.size(); currentFloorLevel++) {
        if (apartment.at(currentFloorLevel) == '(') {
            floorPosition++;
            continue;
        }
        floorPosition--;
        if (floorPosition == basementLevel) {
            return currentFloorLevel + 1;
        }
    }
    return floorPosition;
}

#include "Not_Quite_Lisp.h"
