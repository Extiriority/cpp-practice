#include <iostream>
#include <memory>
#include <map>

using namespace std;

class TicTacToe {
public:
    char playerSymbol = 'X';
    string userLastInput;
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

    void SwitchPlayer() { playerSymbol = playerSymbol == 'X' ? 'O' : 'X'; }

     void Input(const string& userCoords, const char& placeXO) {
        bool validInput = false;

        while (!validInput) {
            if (coordMap.contains(userCoords) && coordMap[userCoords] == ' ') {
                coordMap[userCoords] = placeXO;
                validInput = true;
            } else {
                cout << "    ___Invalid input___" << endl;
                cout << "Enter available OR correct coordinates: ";
                cin >> userLastInput;
                cout << endl;
            }
        }
    }

    void nextRound() {
        turnCounter++;
        SwitchPlayer();
    }

    bool CheckWin(const string& lastMove) const {
        return CheckRow(lastMove[0]) || CheckColumn(lastMove[1]) || CheckDiagonals();
    }

    bool CheckRow(const char rowChar) const {
        const string row(1,  rowChar);
        return coordMap.at(row + "1") == playerSymbol &&
               coordMap.at(row + "2") == playerSymbol &&
               coordMap.at(row + "3") == playerSymbol;
    }

    bool CheckColumn(const char colChar) const {
        const string col(1,  colChar);
        return coordMap.at("A" + col) == playerSymbol &&
               coordMap.at("B" + col) == playerSymbol &&
               coordMap.at("C" + col) == playerSymbol;
    }

    bool CheckDiagonals() const {
        const bool diagonalHill =  coordMap.at("A1") == playerSymbol &&
                                   coordMap.at("B2") == playerSymbol &&
                                   coordMap.at("C3") == playerSymbol;
        const bool diagonalSlope = coordMap.at("A3") == playerSymbol &&
                                   coordMap.at("B2") == playerSymbol &&
                                   coordMap.at("C1") == playerSymbol;
        return diagonalHill || diagonalSlope;
    }

    void Reset() {
        winState = false;
        turnCounter = 0;

        for (auto& [coords, input] : coordMap) {
            input = ' ';
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
        cout << "["<<Game.playerSymbol<<"] turn, Enter coordinates: ";
        cin >> Game.userLastInput;
        cout << endl;

        Game.Input(Game.userLastInput, Game.playerSymbol);

        system("cls");
        Game.Update();

        if (Game.turnCounter < 4) {
            Game.nextRound();
            continue;
        }

        Game.winState = Game.CheckWin(Game.userLastInput);
        if (Game.winState) {
            cout << "Player ["<<Game.playerSymbol<<"] won this match!" << endl;
        } else if (Game.turnCounter == 8) {
            cout << "The game is a draw!" << endl;
        } else {
            Game.nextRound();
            continue;
        }
        cout << "Try again Y/N?: ";
        cin >> Game.userLastInput;
        if (Game.userLastInput != "Y")
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