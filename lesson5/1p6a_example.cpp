// fork join parallelism
// push_back would not work in this case, creating a compile error
// this is because when we push it we actually copy it, but threads object do not have a copy constructor and cannot be duplicated 
// emplace_back internally uses move semantics to move the thread into the vector without making a copy of it

#include <iostream>
#include <thread>
#include <vector>

void printHello() {
    std::cout << "Hello from worker thread #" << std::this_thread::get_id() << std::endl;
}

int main() {
    std::vector<std::thread> threads;

    for (size_t i = 0; i < 5; i++) {
        threads.emplace_back(std::thread(printHello));
        //threads[i] = std::thread(printHello);
    }
    std::this_thread::sleep_for(std::chrono::microseconds(1));
    std::cout << "Hello from the main thread #" << std::this_thread::get_id() << std::endl;

    for (auto &t : threads) {
        t.join();
    }
    return 0;
}