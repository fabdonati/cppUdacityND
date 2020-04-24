// can also be redirected using reset()
#include <iostream>
#include <string>
#include <memory>

class MyClass {
    std::string _text;
public:
    MyClass(std::string text) {_text = text;}
    ~MyClass() {std::cout << "destructor called" << std::endl;}
    std::string GetText() {return _text;}
};

int main() {
    std::shared_ptr<MyClass> shared1(new MyClass("prova"));
    std::cout << "shared pointer address on stack = " << &shared1 << ", value = " << shared1->GetText() << ", count = " << shared1.use_count() << std::endl;

    shared1.reset(new MyClass("nuova prova"));
    std::cout << "shared pointer address on stack = " << &shared1 << ", value = " << shared1->GetText() << ", count = " << shared1.use_count() << std::endl;
    return 0;
}