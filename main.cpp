#include <iostream>
#include <memory>

using namespace std;

class TicTacToe {
public:
    string numberRow;
    string border;
    string player = "X";
    string userInput;
    int turns = 0;
    bool winState = false;
    string coords[3][3] =  {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "},
    };

    void InitGame() {
         cout << "Welcome to Noughts and Crosses" << endl;
         numberRow =  "   1   2   3";
         border = "  -----------";
         string ARow = "A   |    |   ";
         string BRow = "B   |    |   ";
         string CRow = "C   |    |   ";

        Update();
    }

    void Update() const {
        cout << "_______________" << endl;
        cout << numberRow << endl;
        cout << "A  "+coords[0][0]+" | "+coords[0][1]+" | "+coords[0][2]+" " << endl;
        cout << border << endl;
        cout << "B  "+coords[1][0]+" | "+coords[1][1]+" | "+coords[1][2]+" " << endl;
        cout << border << endl;
        cout << "C  "+coords[2][0]+" | "+coords[2][1]+" | "+coords[2][2]+" " << endl;
        cout << "_______________" << endl;
    }

    void SwitchPlayer() {
        player = player == "X" ? "O" : "X";
    }

    pair<int, int> Input(const string& userCoords, const string& currentPlayer) {
        pair<int, int> lastMove;
        bool validInput = false;

        if (userCoords == "A1" and coords[0][0] == " ") { coords[0][0] = currentPlayer; lastMove = {0, 0}; validInput = true; }
        if (userCoords == "A2" and coords[0][1] == " ") { coords[0][1] = currentPlayer; lastMove = {0, 1}; validInput = true; }
        if (userCoords == "A3" and coords[0][2] == " ") { coords[0][2] = currentPlayer; lastMove = {0, 2}; validInput = true; }
        if (userCoords == "B1" and coords[1][0] == " ") { coords[1][0] = currentPlayer; lastMove = {1, 0}; validInput = true; }
        if (userCoords == "B2" and coords[1][1] == " ") { coords[1][1] = currentPlayer; lastMove = {1, 1}; validInput = true; }
        if (userCoords == "B3" and coords[1][2] == " ") { coords[1][2] = currentPlayer; lastMove = {1, 2}; validInput = true; }
        if (userCoords == "C1" and coords[2][0] == " ") { coords[2][0] = currentPlayer; lastMove = {2, 0}; validInput = true; }
        if (userCoords == "C2" and coords[2][1] == " ") { coords[2][1] = currentPlayer; lastMove = {2, 1}; validInput = true; }
        if (userCoords == "C3" and coords[2][2] == " ") { coords[2][2] = currentPlayer; lastMove = {2, 2}; validInput = true; }

        if (!validInput) {
            cout << "___Invalid input___" << endl;
            cout << "Enter empty OR correct coordinates: ";
            cin >> userInput;
            cout << "coords is: " << userInput << endl;
            return Input(userInput, player);
        }
        return lastMove;
    }

    bool CheckDraw() const {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (coords[row][col] == " ") {
                    return false;
                }
            }
        }
    return true;
}

    bool CheckWin(const int row, const int col) const {
        return CheckRow(row) || CheckColumn(col) || CheckDiagonals();
    }

    bool CheckRow(const int row) const {
        return coords[row][0] == player && coords[row][1] == player && coords[row][2] == player;
    }

    bool CheckColumn(const int col) const {
        return coords[0][col] == player && coords[1][col] == player && coords[2][col] == player;
    }

    bool CheckDiagonals() const {
        const bool diagonal1 = coords[0][0] == player && coords[1][1] == player && coords[2][2] == player;
        const bool diagonal2 = coords[0][2] == player && coords[1][1] == player && coords[2][0] == player;
        return diagonal1 || diagonal2;
    }

    void Reset() {
        winState = false;

       for (int row = 0; row < 3; row++) {
           for (int col = 0; col < 3; col++) {
               coords[row][col] = " ";
           }
       }
        Update();
    }
};

int main() {
    TicTacToe Game;
    Game.InitGame();

    while (!Game.winState) {
        cout << "["+ Game.player +"] turn, Enter coordinates: ";
        cin >> Game.userInput;
        cout << "coords is: " << Game.userInput << endl;

        auto [row, col] = Game.Input(Game.userInput, Game.player);
        Game.Update();

        if (Game.turns < 4; and Game.winState = Game.CheckWin(row, col);) {
            cout << "Player [" + Game.player + "] won this match!" << endl;
        } else if (Game.CheckDraw()) {
            cout << "The game is a draw!" << endl;
        } else {
            Game.turns++;
            Game.SwitchPlayer();
            return false;
        }

        cout << "Try again Y/N?: ";
        cin >> Game.userInput;

        if (Game.userInput != "Y") {
            return false;
        }

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