//
// Created by giang on 14 Feb 2024.
//

#include "Not_Quite_Lisp.h"

#include <cstdint>
#include <string>

using namespace std;

enum Floor { GROUND_LEVEL = 0, BASEMENT_LEVEL = -1 };

tuple<int16_t, auto> Not_Quite_Lisp::WhichFloor(const std::string& apartment) {
    int16_t floorPosition = 0;
    auto floorsToBasement = 0;

    for (int currentFloorLevel = GROUND_LEVEL; currentFloorLevel < apartment.size(); currentFloorLevel++) {
        floorPosition += apartment[currentFloorLevel] == '(' ? 1 : -1;
        if (floorPosition == BASEMENT_LEVEL) {
            floorsToBasement = currentFloorLevel + 1;
        }
    }
    return make_tuple(floorPosition, floorsToBasement);
}