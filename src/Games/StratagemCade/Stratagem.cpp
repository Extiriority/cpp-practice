//
// Created by Amy on 26-2-2024.
//

#include "Stratagem.h"

#include <ctime>
#include <map>
#include <string>

enum Stratagems { Resupply = 1, Eagle_Airstrike = 2, Autocannon = 3, };

std::map<Stratagems, std::string> stratagemCodes = {
    {Resupply, "vv^>"}, { Eagle_Airstrike, "^>v>"}, {Autocannon, "v><vv^^>"}
};

std::string Stratagem::SolveStratagem() {
    srand(time(nullptr));
    auto random = rand()%+1;

}

//https://helldivers.fandom.com/wiki/Stratagem_Codes