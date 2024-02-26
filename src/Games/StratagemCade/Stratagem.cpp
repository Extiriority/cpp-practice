//
// Created by Amy on 26-2-2024.
//

#include "Stratagem.h"

#include <ctime>

enum Stratagems { Resupply = "vv^>"};

std::string Stratagem::SolveStratagem() {
    srand(time(nullptr));
    auto random = rand()%+1;

}

//https://helldivers.fandom.com/wiki/Stratagem_Codes