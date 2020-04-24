// this is a case of circular reference (the counter never goes to 0)
#include <iostream>
#include <string>
#include <memory>

class MyClass {
    std::string _text;
public:
    std::shared_ptr<MyClass> _member;
    ~MyClass() {std::cout << "destructor called" << std::endl;}
};

int main() {
    std::shared_ptr<MyClass> shared1(new MyClass);
    std::shared_ptr<MyClass> shared2(new MyClass);

    shared1->_member = shared2;
    shared2->_member = shared1;
    return 0;
}