#include <iostream>
#include <thread>

void threadFunctionEven() {
    //std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::cout << "Even thread\n";
}

void threadFunctionOdd() {
    //std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::cout << "Odd thread\n";
}

int main() {
    for (int i = 0; i < 6; i++) {
        std::thread t(i%2==0 ? threadFunctionEven : threadFunctionOdd);
        t.detach();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "End of main reached\n";
    return 0;
}