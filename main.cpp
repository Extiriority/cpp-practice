#include <iostream>
#include <memory>
#include <map>

using namespace std;

class TicTacToe {
public:
    string playerSymbol = "X";
    string userInput;
    int turnCounter = 0;
    bool winState = false;
    string coords[3][3] =  {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "},
    };

    void Update() const {
        cout << "      _______________" << endl;
        cout << "          1   2   3" << endl;
        cout << "       A  "+coords[0][0]+" | "+coords[0][1]+" | "+coords[0][2]+" " << endl;
        cout << "         -----------" << endl;
        cout << "       B  "+coords[1][0]+" | "+coords[1][1]+" | "+coords[1][2]+" " << endl;
        cout << "         -----------" << endl;
        cout << "       C  "+coords[2][0]+" | "+coords[2][1]+" | "+coords[2][2]+" " << endl;
        cout << "      _______________" << endl;
    }

    void SwitchPlayer() { playerSymbol = playerSymbol == "X" ? "O" : "X"; }

    pair<int, int> Input(const string& userCoords, const string& placeXorO) {
        pair<int, int> lastMove;
        bool validInput = false;

        while (!validInput) {
            if (map<string, pair<int, int>> coordMap = {
            {"A1", {0, 0}}, {"A2", {0, 1}}, {"A3", {0, 2}},
            {"B1", {1, 0}}, {"B2", {1, 1}}, {"B3", {1, 2}},
            {"C1", {2, 0}}, {"C2", {2, 1}}, {"C3", {2, 2}}
            }; coordMap.contains(userCoords) && coords[coordMap[userCoords].first][coordMap[userCoords].second] == " ") {
                coords[coordMap[userCoords].first][coordMap[userCoords].second] = placeXorO;
                lastMove = coordMap[userCoords];
                validInput = true;
            } else {
                cout << "    ___Invalid input___" << endl;
                cout << "Enter available OR correct coordinates: ";
                cin >> userInput;
                cout << endl;
            }
        }
        return lastMove;
    }

    void nextRound() {
        turnCounter++;
        SwitchPlayer();
    }

    bool CheckWin(const int row, const int col) const {
        return CheckRow(row) || CheckColumn(col) || CheckDiagonals();
    }

    bool CheckRow(const int row) const {
        return coords[row][0] == playerSymbol && coords[row][1] == playerSymbol && coords[row][2] == playerSymbol;
    }

    bool CheckColumn(const int col) const {
        return coords[0][col] == playerSymbol && coords[1][col] == playerSymbol && coords[2][col] == playerSymbol;
    }

    bool CheckDiagonals() const {
        const bool diagonal1 = coords[0][0] == playerSymbol && coords[1][1] == playerSymbol && coords[2][2] == playerSymbol;
        const bool diagonal2 = coords[0][2] == playerSymbol && coords[1][1] == playerSymbol && coords[2][0] == playerSymbol;
        return diagonal1 || diagonal2;
    }

    void Reset() {
        winState = false;
        turnCounter = 0;

        for (auto& row : coords) {
            ranges::fill(row, " ");
        }
        cout << endl;
        Update();
    }
};

int main() {
    TicTacToe Game;
    cout << "Welcome to Noughts and Crosses" << endl;
    Game.Update();

    while (!Game.winState) {
        cout << "["+ Game.playerSymbol +"] turn, Enter coordinates: ";
        cin >> Game.userInput;
        cout << endl;

        auto [row, col] = Game.Input(Game.userInput, Game.playerSymbol);
        Game.Update();

        if (Game.turnCounter < 4) {
            Game.nextRound();
            continue;
        }

        Game.winState = Game.CheckWin(row, col);
        if (Game.winState) {
            cout << "Player [" + Game.playerSymbol + "] won this match!" << endl;
        } else if (Game.turnCounter == 8) {
            cout << "The game is a draw!" << endl;
        } else {
            Game.nextRound();
            continue;
        }
        cout << "Try again Y/N?: ";
        cin >> Game.userInput;
        if (Game.userInput != "Y")
            continue;

        Game.Reset();
        Game.SwitchPlayer();
    }

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