#include <iostream>
#include <thread>

int main() {
    int id = 0;

    id++;
    auto f1 =  [id]() {std::cout << "ID = " << id << std::endl;};
    id++;
    auto f2 =  [&id]() {std::cout << "ID = " << id << std::endl;};
    //auto f3 =  [id]() {std::cout << *"ID = " << ++id << std::endl;};
    auto f4 =  [id]() mutable {std::cout << "ID = " << ++id << std::endl;};

    f1();
    f2();
    f4();
//    std::thread t = std::thread( Vehicle(1) ); // copy initialization
//    std::cout << "Finished work in main \n";
//    t.join();
    return 0;
}
