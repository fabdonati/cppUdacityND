#include <iostream>

using namespace std;

void addThree(int *input) {
    *input += 3;
}


void addThree(int &input) {
    input += 3;
}


int main() {
    int val = 0;

    addThree(val); // same as esplicitly define pass by reference &val
    cout << "val is: " << val << endl;

    addThree(&val);
    cout << "val is: " << val << endl;

    addThree(&val);
    cout << "val is: " << val << endl;
    return 0;
}