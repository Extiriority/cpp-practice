#include <iostream>
#include <memory>

using namespace std;

class Noughts_and_Crosses {
public:
    string numberTable;
    string border;
    string ARow;
    string BRow;
    string CRow;
    string coords[9] = {" ", " ", " ",
                        " ", " ", " ",
                        " ", " ", " "
       };

    void Update() {
        cout << numberTable << endl;
        cout << "A  "+coords[1]+" | "+coords[2]+" | "+coords[3]+" " << endl;
        cout << border << endl;
        cout << "B  "+coords[4]+" | "+coords[5]+" | "+coords[6]+" " << endl;
        cout << border << endl;
        cout << "C  "+coords[7]+" | "+coords[8]+" | "+coords[9]+" " << endl;
    }

    void InitGame() {
         numberTable =  "   1   2   3";
         border = "  -----------";
         ARow = "A   |    |   ";
         BRow = "B   |    |   ";
         CRow = "C   |    |   ";

        Update();
    }

    void input(const string& userCoords) {
        if (userCoords == "A1") {coords[1] = "X";}
        else if (userCoords == "A2") {coords[2] = "X";}
        else if (userCoords == "A3") {coords[3] = "X";}
        else if (userCoords == "B1") {coords[4] = "X";}
        else if (userCoords == "B2") {coords[5] = "X";}
        else if (userCoords == "B3") {coords[6] = "X";}
        else if (userCoords == "C1") {coords[7] = "X";}
        else if (userCoords == "C2") {coords[8] = "X";}
        else if (userCoords == "C3") {coords[9] = "X";}
        else {
            cout << "Invalid input" << endl;
        }
        Update();
    }
};

int main() {
    Noughts_and_Crosses Game;
    Game.InitGame();

    string coords;

    cout << "Enter coordinates: ";
    cin >> coords;
    cout << "coords is: " << coords << endl;

    Game.input(coords);

    cout << "Enter coordinates: ";
    cin >> coords;
    cout << "coords is: " << coords << endl;

    Game.input(coords);

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