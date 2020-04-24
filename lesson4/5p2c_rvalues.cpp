#include <iostream>

void myFunction(int &val) {
    std::cout << "val = " << val << std::endl;
}

int main() {
    int j = 42;
    myFunction(j);
    myFunction(42);
    int k = 23;
    //myFunction(j+k) // this does not work as a temporary variable has to be created to place it in (result of an addition, which is an rvalue)
    return 0;
}