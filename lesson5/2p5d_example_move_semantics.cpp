#include <iostream>
#include <thread>
#include <future>

class Vehicle {
public:
    // Default constructor
    Vehicle() : _id(0), _name(new std::string("Default Name")) {
        std::cout << "Vehicle #" << _id << " at address " << this << ", Default constructor called" << std::endl;
    }
    // Destructor
    ~Vehicle() {
        std::cout << "Vehicle #" << _id << " Destructor called";
        if (_name != nullptr) {
            std::cout << " - Deleting resource at address " << this << std::endl;
            delete _name;
        }
    }
    // initializing constructor
    Vehicle(int id, std::string name) : _id(id), _name(new std::string(name)) {
        std::cout << "Vehicle #" << _id << " at address " << this << ", Initializing constructor called" << std::endl;
    }
    // Copy constructor (deep copy)
    Vehicle(const Vehicle &src) : _id(src.getID()), _name(new std::string(src.getName())) {
        std::cout << "Vehicle #" << _id << " at address " << this << ", Copy constructor called" << std::endl;
    }
    // Assignment operator
    Vehicle &operator=(const Vehicle &src) {
        if (this != &src) {
            delete _name;
            _id = src.getID();
            _name = new std::string(src.getName());
            std::cout << "Vehicle #" << _id << " at address " << this << ", Assignment constructor called" << std::endl;
        }
        return *this;
    }
    // Move operator
    Vehicle(Vehicle &&src) {
        _id = src.getID();
        _name = new std::string(src.getName());
        src.setID(0);
        src.setName("Default Name");
        std::cout << "Vehicle #" << _id << " at address " << this << ", Move operator called" << std::endl;
    }
    // Move assignment
    Vehicle &operator=(Vehicle &&src) {
        if (this != &src) {
            _id = src.getID();
            _name = new std::string(src.getName());
            src.setID(0);
            src.setName("Default Name");
        }
        std::cout << "Vehicle #" << _id << " at address " << this << ", Move assignment called" << std::endl;
        return *this;
    }

    void setID(int id) { _id = id; }
    void setName(std::string name) { *_name = name; }
    int getID() const { return _id; }  
    std::string getName() const { return *_name; }

private: 
    int _id;
    std::string *_name;
};

int main() {
    Vehicle v0;
    Vehicle v1(1, "Vehicle 1");

    std::future<void> ftr = std::async([](Vehicle v) {
        v.setName("Vehicle 2");
    },std::move(v0));

    ftr.wait();
    std::cout << v0.getName() << std::endl;
    std::cout << v1.getName() << std::endl;
    return 0;
}