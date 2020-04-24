#include <iostream>
#include <thread>

class Vehicle {
public: 
    Vehicle(int id) : _id(id) {};
    void operator()(){
        std::cout << "Vehicle object has been created\n";
    }
private:
    int _id;
};

int main() {
    std::thread t = std::thread( Vehicle(1) ); // copy initialization
    std::cout << "Finished work in main \n";
    t.join();
    return 0;
}
