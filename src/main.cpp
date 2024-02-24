#include <iostream>
#include <memory>
#include <stack>
#include <sstream>
#include <string>

#include "Advent_of_Code/Day1/Not_Quite_Lisp.h"
#include "Advent_of_Code/Day2/I_Was_Told_There_Would_Be_No_Math.h"
#include "Utils/Stopwatch.hpp"
#include "Games/TicTacToe.h"

using namespace std;
void Display_StopWatch_(const stopwatch::Stopwatch& my_watch) {
    const auto duration_mus = my_watch.elapsed<stopwatch::microseconds>();
    cout << "Elapsed: " << duration_mus << " microseconds." << '\n';
}

#pragma region [Methods Library]
void AoC_Day_1() {
    const Not_Quite_Lisp apartment;
    auto [floorPosition, floorsToBasement] = Not_Quite_Lisp::WhichFloor(apartment.floors);
    cout << floorPosition << " is where Santa needs to be and " << floorsToBasement << " is the first time to reach basement level [-1]." << '\n';
}
void AoC_Day_2() {
    const I_Was_Told_There_Would_Be_No_Math Packages;
    auto [paper, ribbon] = I_Was_Told_There_Would_Be_No_Math::CalculateTotalWrapping(Packages.dimensions);
    cout << paper << " = total paper in sq feet and " << ribbon << " = Total Ribbon sq Feet" << '\n';
}

void TicTacToe() {
    class TicTacToe Game;
    cout << "Welcome to Noughts and Crosses" << endl;
    Game.Update();
    while (!Game.winState) {
        Game.Input();
        Game.Update();

        if (Game.turnCounter < 4) {
            Game.nextRound();
            continue;
        }

        Game.winState = Game.CheckWin();
        if (Game.winState) {
            cout << "Player ["<<Game.playerMark<<"] won this match!" << endl;
        } else if (Game.turnCounter == 8) {
            cout << "The game is a draw!" << endl;
        } else {
            Game.nextRound();
            continue;
        }
        Game.PromptResetOrExit();
    }
}

void stackAndHeapExample() {
    #pragma region [Compute if the stack is empty]
        cout << "___Compute if the stack is empty___" << endl;
        stack<int> stack;
        cout << "Is the stack empty? " << boolalpha << stack.empty() << endl;
    #pragma endregion [Compute if the stack is empty]

    #pragma region [Push and pop elements from the stack]
        cout << "___Push and pop elements from the stack___" << endl;
        stack.push(5);
        stack.push(7);
        stack.push(9);
        cout << "The top element of the stack: " << stack.top() << endl;
        stack.pop();
        cout << "The top element of the stack: " << stack.top() << endl;
    #pragma endregion [Push and pop elements from the stack]

    //Memory Address:  High ------------------> Low (hexadecimal address)
    //Stack:        | Empty | <- Top
    //              |-------|
    //              |   9   | <- 0xFFEEDDCC (pop the top element)
    //              |-------|
    //              |   7   | <- 0xFFEEDDC8
    //              |-------|
    //              |   5   | <- 0xFFEEDDC4 (Bottom of the stack (oldest element))
    //              |-------|


    #pragma region [Dynamic memory allocation using raw and unique pointers]
    cout << "___Dynamic memory allocation using raw and unique pointers___" << endl;
    // int* dynamicArray = new int[5];
    unique_ptr<int[]> dynamicArray = make_unique<int[]>(5);

    // Initialize values
    for (int i = 0; i < 5; ++i) {
        dynamicArray[i] = i * 10;
    }

    // Access and print values
    for (int i = 0; i < 5; ++i) {
        cout << "Value at index " << i << ": " << dynamicArray[i] << endl;
    }

    // delete[] dynamicArray;
#pragma endregion [Dynamic memory allocation using raw and unique pointers]


}

#pragma region [Car]
class Car {
public:
    //constructure
    explicit Car(const string &model) : model(model) {
        cout << "Car " << model << " is created." << endl;
    }
    //Destructure
    ~Car() {
        cout << "Car " << model << " is destroyed." << endl;
    }

    void drive() const {
        cout << "Driving the car " << model << "." << endl;
    }

private:
    string model;
};

// Function that returns a shared_ptr to a Car
shared_ptr<Car> createCar(const string &model) {
    return make_shared<Car>(model);
}
#pragma endregion Car
#pragma endregion [Methods Library]

int main() {
    namespace sw = stopwatch;
    const sw::Stopwatch my_watch;

    AoC_Day_2();

    Display_StopWatch_(my_watch);


    AoC_Day_1();

    TicTacToe();

    stackAndHeapExample();

#pragma region [Class (auto private and public) and shared ptr]
    cout << "_________Class (auto private and public) and shared ptr_________" << endl;
    // Creating a shared_ptr to a Car
    const shared_ptr<Car> giangCar = createCar("RS e-tron GT");

    // Creating another shared_ptr that shares ownership
    const shared_ptr<Car> amyCar = giangCar;

    // Using the shared_ptr(s)
    giangCar->drive();
    amyCar->drive();
#pragma endregion [Class (auto private and public) and shared ptr]
}



