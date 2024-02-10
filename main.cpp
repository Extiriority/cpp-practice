#include <iostream>
#include <memory>
#include <map>
#include <stack>

using namespace std;

class TicTacToe {
public:
    char playerMark = 'X';
    string userLastMove;
    int turnCounter = 0;
    bool winState = false;
    map<string, char> coordMap = {
            {"A1", ' '}, {"A2", ' '}, {"A3", ' '},
            {"B1", ' '}, {"B2", ' '}, {"B3", ' '},
            {"C1", ' '}, {"C2", ' '}, {"C3", ' '}
        };

    void Update() const {
        cout << "      _______________" << endl;
        cout << "          1   2   3" << endl;
        cout << "       A  "<<coordMap.at("A1")<<" | "<<coordMap.at("A2")<<" | "<<coordMap.at("A3")<<" " << endl;
        cout << "         -----------" << endl;
        cout << "       B  "<<coordMap.at("B1")<<" | "<<coordMap.at("B2")<<" | "<<coordMap.at("B3")<<" " << endl;
        cout << "         -----------" << endl;
        cout << "       C  "<<coordMap.at("C1")<<" | "<<coordMap.at("C2")<<" | "<<coordMap.at("C3")<<" " << endl;
        cout << "      _______________" << endl;
    }

    void SwitchPlayer() { playerMark = playerMark == 'X' ? 'O' : 'X'; }

     void Input() {
        do {
            cout << "Player ["<<playerMark<<"], enter your move: ";
            cin >> userLastMove;
            cout << endl;

            if (coordMap.contains(userLastMove) && coordMap[userLastMove] == ' ') {
                coordMap[userLastMove] = playerMark;
                break;
            }
            cout << "    ___Invalid input___" << endl;
            cout << "available OR correct coords ";
        } while (true);
    }

    void nextRound() {
        turnCounter++;
        SwitchPlayer();
    }

    [[nodiscard]] bool CheckWin() const {
        return CheckRow(userLastMove[0]) || CheckCol(userLastMove[1]) || CheckDiagonals();
    }

    [[nodiscard]] bool CheckRow(const char rowChar) const {
        const string row(1,  rowChar);
        return coordMap.at(row + "1") == playerMark &&
               coordMap.at(row + "2") == playerMark &&
               coordMap.at(row + "3") == playerMark;
    }

    [[nodiscard]] bool CheckCol(const char colChar) const {
        const string col(1,  colChar);
        return coordMap.at("A" + col) == playerMark &&
               coordMap.at("B" + col) == playerMark &&
               coordMap.at("C" + col) == playerMark;
    }

    [[nodiscard]] bool CheckDiagonals() const {
        const bool diagonalHill =  coordMap.at("A1") == playerMark &&
                                   coordMap.at("B2") == playerMark &&
                                   coordMap.at("C3") == playerMark;
        const bool diagonalSlope = coordMap.at("A3") == playerMark &&
                                   coordMap.at("B2") == playerMark &&
                                   coordMap.at("C1") == playerMark;
        return diagonalHill || diagonalSlope;
    }

    void PromptResetOrExit() {
        cout << "Try again Y/N?: ";
        cin >> userLastMove;

        if (userLastMove == "Y") {
            winState = false;
            turnCounter = 0;

            for (auto& [coords, input] : coordMap) {
                input = ' ';
            }
            cout << endl;
            Update();
            SwitchPlayer();
        } else {
            cout << "___ Thanks for Playing me! ___" << endl;
        }
    }
};

bool upOrDown(const int *other) {
    int x;
    if (!other) {
        return upOrDown(&x);
    }
    return &x < other;
}

int main() {
    TicTacToe Game;
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

    #pragma region [Compute if the stack grows up or down]
        cout << "___Compute if the stack grows up or down___" << endl;
        cout << "The stack grows " << (upOrDown(nullptr) ? "down" : "up") << endl;
    #pragma endregion [Compute if the stack grows up or down]


    /*#pragma region [Dynamic memory allocation using raw and unique pointers]
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

#pragma region [Class (auto private and public) and shared ptr]
    cout << "_________Class (auto private and public) and shared ptr_________" << endl;
    // Creating a shared_ptr to a Car
    const shared_ptr<Car> giangCar = createCar("RS e-tron GT");

    // Creating another shared_ptr that shares ownership
    const shared_ptr<Car> amyCar = giangCar;

    // Using the shared_ptr(s)
    giangCar->drive();
    amyCar->drive();
#pragma endregion [Class (auto private and public) and shared ptr]*/


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