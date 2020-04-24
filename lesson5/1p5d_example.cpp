// v2 has to live after t2 is completed or there will be an attempt to access memory which has been already invalidated
// an alternative is to use a smart pointer
#include <iostream>
#include <thread>

class Vehicle {
public:
    Vehicle() : _id(0), _name("default") {}
    void addID(int id) { _id = id; }
    void setName(std::string name) { _name = name; }
    void printID() {
        std::cout << "Vehicle ID = " << _id << std::endl;
    }
    void printName() {
        std::cout << "Vehicle Name = " << _name << std::endl;
    }

private:
    int _id;
    std::string _name;
};

int main() {
    Vehicle v1, v2;
    std::shared_ptr<Vehicle> v3(new Vehicle);
    std::thread t1i = std::thread(&Vehicle::addID, v1, 1);       // calls copy constructor?
    std::thread t2i = std::thread(&Vehicle::addID, &v2, 2);
    std::thread t3i = std::thread(&Vehicle::addID, v3, 100);
    std::thread t1n = std::thread(&Vehicle::setName, v1, "BMW");
    std::thread t2n = std::thread(&Vehicle::setName, &v2, "Mercedes");
    std::thread t3n = std::thread(&Vehicle::setName, v3, "Panda");
    t1i.join();
    t2i.join();
    t3i.join();
    t1n.join();
    t2n.join();
    t3n.join();
    
    v1.printID();
    v1.printName();

    v2.printID();
    v2.printName();

    v3->printID();
    v3->printName();

    return 0;
}