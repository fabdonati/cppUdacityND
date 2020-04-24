#include <iostream>
#include <thread>
#include <string>

using namespace std;

void printName(string &name, int waitTime) {
    this_thread::sleep_for(chrono::milliseconds(waitTime));
    name += " (from Thread)";
    cout << name << endl;
}

int main() {
    string name ("MyThread");

    thread t1(printName, ref(name), 50);
    t1.join();

    name += " (from Main)";
    cout << name << endl;
    return 0;
}