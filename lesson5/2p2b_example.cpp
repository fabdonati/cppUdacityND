#include <iostream>
#include <thread>
#include <future>

void modifyMessage(std::promise<std::string> && prms, std::string message) {
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    std::string modifiedMessage = message  + " has been modified";
    prms.set_value(modifiedMessage);
}

int main() {
    std::string messageToThread = "My Message";

    // create promise and future
    std::promise<std::string> prms;
    std::future<std::string> ftr = prms.get_future();

    // start a thread and pass a promise as an argument
    std::thread t1(modifyMessage, std::move(prms), messageToThread);

    // print message to console
    std::cout << "Original message from main(): " << messageToThread << std::endl;
    
    // retrieve modified message via future and print to console
    std::string messageFromThread = ftr.get();
    std::cout << "Modified message from thread(): " << messageFromThread << std::endl;

    return 0;
}