#include <iostream>

class MyClass {
private: 
    int * _myInt;
public:
    MyClass() {
        _myInt = (int*)malloc(sizeof(int));
    }

    ~MyClass() {
        free(_myInt);
    }

    void printOwnAddress() {std::cout << "Own address on the stack is: " << this << std::endl;}
    void printMemberAddress() {std::cout << "Managing memory block on the heap at: " << _myInt << std::endl;}
};

int main() {
    MyClass class1;
    class1.printOwnAddress();
    class1.printMemberAddress();

    MyClass class2(class1);
    class2.printOwnAddress();
    class2.printMemberAddress();

    return 0;
}