#include <iostream>
#include <memory>

class MyClass {
    int _member;
public:
    MyClass(int val) : _member(val) {}
    void PrintVal() {std::cout << ", managed object " << this << " with val = " << _member << std::endl;}
};

void f(std::unique_ptr<MyClass> ptr) {
    std::cout << "unique_ptr " << &ptr;
    ptr->PrintVal();
}

int main() {
    std::unique_ptr<MyClass> uniquePtr = std::make_unique<MyClass>(23);
    std::cout << "unique_ptr " << &uniquePtr;
    uniquePtr->PrintVal();

    f(std::move(uniquePtr));
    if (uniquePtr) {
        uniquePtr->PrintVal();
    }
    return 0;
}