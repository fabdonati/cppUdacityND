#include <iostream>

using namespace std;

void AddFive(int &val, bool &success) {
    val += 5;
    success = true;
}

void AddFour(int &val) {
    val += 4;
}

void AddSix(int *val) {
    *val += 6;
}

int main() {
    int val = 0;
    bool success = false;
    AddFive(val, success);
    cout << "val is now: " << val << ", bool is now: " << success << endl;

    AddFour(val);
    cout << "val is now: " << val << ", bool is now: " << success << endl;

    AddSix(&val);
    cout << "val is now: " << val << ", bool is now: " << success << endl;
    return 0;
}