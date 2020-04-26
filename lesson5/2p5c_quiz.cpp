#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include <thread>
#include <future>

class Vehicle {
public:
    Vehicle() : _id(0), _name(new std::string("Default Name")) {
        std::cout << "Vehicle #" << _id << " Default constructor called" << std::endl; 
    }

    Vehicle(int id, std::string name) : _id(id), _name(new std::string(name)) {
        std::cout << "Vehicle #" << _id << " Initializing constructor called" << std::endl; 
    }

    Vehicle(Vehicle const &src) {
        _id = src._id;
        if (src._name != nullptr) {
            _name = new std::string;
            *_name = *src._name;
        }
        std::cout << "Vehicle #" << _id << " copy constructor called" << std::endl;
    }

    ~Vehicle() {
        delete _name;
    }

    void setID(int id) { _id = id; }
    void setName(std::string name) { *_name = name;}
    int getID() { return _id; }
    std::string getName() { return *_name; }
private:
    int _id;
    std::string *_name;
};

int main() {
    Vehicle v0;
    Vehicle v1(1, "Vehicle 1");

    std::future<void> ftr = std::async([](Vehicle v) {
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        v.setName("Vehicle 2");
    }, v0);

    v0.setName("Vehicle 3");

    ftr.wait();
    std::cout << v0.getName() << std::endl;
    return 0;
}