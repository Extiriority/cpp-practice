//
// Created by giang on 14 Feb 2024.
//

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <map>
#include <string>

using std::string, std::cout, std::cin, std::map;

class TicTacToe {
public:
    char playerMark {'X'};
    string userLastMove;
    int turnCounter {};
    bool winState = false;
    map<string, char> coordMap = {
        {"A1", ' '}, {"A2", ' '}, {"A3", ' '},
        {"B1", ' '}, {"B2", ' '}, {"B3", ' '},
        {"C1", ' '}, {"C2", ' '}, {"C3", ' '}
    };

    void Update() const;
    void SwitchPlayer();
    void Input();
    void nextRound();
    [[nodiscard]] bool CheckWin() const;
    [[nodiscard]] bool CheckRow(char rowChar) const;
    [[nodiscard]] bool CheckCol(char colChar) const;
    [[nodiscard]] bool CheckDiagonals() const;
    void PromptResetOrExit();
};

#endif //TICTACTOE_H