#include <iostream>
#include <thread>

void threadFunction(){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Finished work in thread" << std::endl;
}

int main() {
    // uint nCores = std::thread::hardware_concurrency();
    std::thread t(threadFunction);

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work in main" << std::endl;

    t.join();
    // std::cout << "Hello concurrent world from main thread id =" << std::this_thread::get_id() << std::endl;
    // std::cout << "This machine supports concurrency with " << nCores << " cores available" << std::endl;
    return 0;
}