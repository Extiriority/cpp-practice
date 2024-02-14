//
// Created by giang on 14 Feb 2024.
//

#include "Not_Quite_Lisp.h"
#include <string>


int Not_Quite_Lisp::WhichFloor(const std::string& apartment) {
    int floorPosition {};
    constexpr int groundLevel {};
    constexpr int basementLevel {-1};

    for (int currentFloorLevel = groundLevel; currentFloorLevel < apartment.size(); currentFloorLevel++) {
        floorPosition += apartment[currentFloorLevel] == '(' ? 1 : -1;
        if (floorPosition == basementLevel) {
            return currentFloorLevel + 1;
        }
    }
    return floorPosition;
}