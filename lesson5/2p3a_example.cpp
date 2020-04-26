#include <iostream>
#include <thread>
#include <future>
#include <memory>
#include <cmath>

double divideByNumber(double num, double den) {
    std::cout << "Worker thread id = " << std::this_thread::get_id() << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    if (den == 0) {
        throw std::runtime_error("Exception from the thread: Division by zero!");
    }
    return num / den;
}

int main() {
    std::cout << "Main thread id = " << std::this_thread::get_id() << std::endl;

    double num = 42.0, den = 2.0;
    std::future<double> ftr = std::async(std::launch::deferred, divideByNumber, num, den);

    try {
        double result = ftr.get();
        std::cout << "Result = " << result << std::endl;
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}