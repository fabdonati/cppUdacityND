// this way we pass data from the main thread to the worker threads but how the viceversa?
#include <iostream>
#include <thread>

void printMessage(std::string message) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Thread 1: " << message << std::endl;
}

int main() {
    std::string message = "My message";

    std::thread t1(printMessage, message); // variadic template
    std::thread t2([message](){
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "Thread 2: " << message << std::endl;
    });
    
    // threads barrier
    t1.join();
    t2.join();
    return 0;
}