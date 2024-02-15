//
// Created by giang on 14 Feb 2024.
//

#include "Not_Quite_Lisp.h"
#include <string>

enum Floor { GROUND_LEVEL = 0, BASEMENT_LEVEL = -1 };

int Not_Quite_Lisp::WhichFloor(const std::string& apartment) {
    int floorPosition {};
    constexpr int GROUND_LEVEL {};
    constexpr int BASEMENT_LEVEL {-1};

    for (int currentFloorLevel = GROUND_LEVEL; currentFloorLevel < apartment.size(); currentFloorLevel++) {
        floorPosition += apartment[currentFloorLevel] == '(' ? 1 : -1;
        if (floorPosition == BASEMENT_LEVEL) {
            return currentFloorLevel + 1;
        }
    }
    return floorPosition;
}