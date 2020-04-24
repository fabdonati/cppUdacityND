// non-deterministic behavior of threads, it cannot be predicted which one is executed by the thread scheduler
// .join() can be used as a barrier, in case we want the work from the launched threads to be finished before we go on with the work from main
#include <iostream>
#include <thread>

using namespace std;

void threadFunction() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 1 in thread" << std::endl;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in thread" << std::endl;
}

int main() {
    std::thread t(threadFunction);
    t.detach();

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 1 in main" << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in main" << std::endl;

    return 0;
}
