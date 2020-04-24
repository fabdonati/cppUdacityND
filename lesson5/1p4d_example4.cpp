#include <iostream>
#include <thread>

int main() {
    int id = 0;

    auto f = [](const int id) {std::cout << "ID = " << id << std::endl;};
    f(++id);
    return 0;
}
