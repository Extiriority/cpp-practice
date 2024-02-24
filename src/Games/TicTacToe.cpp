//
// Created by giang on 14 Feb 2024.
//

#include "TicTacToe.h"

void TicTacToe::Update() const {
    cout << "      _______________" << '\n';
    cout << "          1   2   3" << '\n';
    cout << "       A  "<<coordMap.at("A1")<<" | "<<coordMap.at("A2")<<" | "<<coordMap.at("A3")<<'\n';
    cout << "         -----------" << '\n';
    cout << "       B  "<<coordMap.at("B1")<<" | "<<coordMap.at("B2")<<" | "<<coordMap.at("B3")<<'\n';
    cout << "         -----------" << '\n';
    cout << "       C  "<<coordMap.at("C1")<<" | "<<coordMap.at("C2")<<" | "<<coordMap.at("C3")<<'\n';
    cout << "      _______________" << '\n';
}

void TicTacToe::SwitchPlayer() { playerMark = playerMark == 'X' ? 'O' : 'X'; }

void TicTacToe::Input() {
    do {
        cout << "Player ["<<playerMark<<"], enter your move: ";
        cin >> userLastMove;
        cout << '\n';

        if (coordMap.contains(userLastMove) && coordMap[userLastMove] == ' ') {
            coordMap[userLastMove] = playerMark;
            break;
        }
        cout << "    ___Invalid input___" << '\n';
        cout << "available OR correct coords ";
    } while (true);
}

void TicTacToe::nextRound() {
    turnCounter++;
    SwitchPlayer();
}

bool TicTacToe::CheckWin() const {
    return CheckRow(userLastMove[0]) || CheckCol(userLastMove[1]) || CheckDiagonals();
}

bool TicTacToe::CheckRow(const char rowChar) const {
    const string row(1,  rowChar);
    return coordMap.at(row + "1") == playerMark &&
           coordMap.at(row + "2") == playerMark &&
           coordMap.at(row + "3") == playerMark;
}

bool TicTacToe::CheckCol(const char colChar) const {
    const string col(1,  colChar);
    return coordMap.at("A" + col) == playerMark &&
           coordMap.at("B" + col) == playerMark &&
           coordMap.at("C" + col) == playerMark;
}

bool TicTacToe::CheckDiagonals() const {
    const bool diagonalHill =  coordMap.at("A1") == playerMark &&
                                   coordMap.at("B2") == playerMark &&
                                   coordMap.at("C3") == playerMark;
    const bool diagonalSlope = coordMap.at("A3") == playerMark &&
                               coordMap.at("B2") == playerMark &&
                               coordMap.at("C1") == playerMark;
    return diagonalHill || diagonalSlope;
}

void TicTacToe::PromptResetOrExit() {
    cout << "Try again Y/N?: ";
    cin >> userLastMove;

    if (userLastMove == "Y") {
        winState = false;
        turnCounter = 0;

        for (auto& [coords, input] : coordMap) {
            input = ' ';
        }
        cout << '\n';
        Update();
        SwitchPlayer();
    } else {
        cout << "___ Thanks for Playing me! ___" << '\n';
    }
}