#include <iostream>
#include <string>

using namespace std;

class Vehicle {
    public:
        int wheels{0};
        string color{"none"};
        bool isEcoFriendly = false;
        void Print() const {
            cout << "This " << color << " vehicle has " << wheels << " wheels!" << endl;
        }
};

class Car : public Vehicle {
    public:
        Car() { wheels = 4; color = "red"; isEcoFriendly = false; }
};

class Bicycle : public Vehicle {
    public: 
        Bicycle() { wheels = 2; color = "black"; isEcoFriendly = true; }
};

int main() {
    Car car;
    car.Print();
    Bicycle bike;
    bike.Print();
    return 0;
}