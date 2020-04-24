#include <iostream>

void myFunction(int &val){
    ++val;
}

int main() {
    int i = 1;
    myFunction(i);
    std::cout << i << std::endl;
    // int &j = i;
    // ++i;
    // ++j;

    // std::cout << "i = " << i << ", j = " << j << std::endl;
    return 0;
}