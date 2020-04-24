#include <stdlib.h>
#include <iostream>

class MyMovableClass {
    int _size;
    int *_data;
public:
    MyMovableClass(size_t size) {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int) << " bytes" << std::endl;
    } // ctor

    ~MyMovableClass() {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data; 
    }

    MyMovableClass(const MyMovableClass &source);
    MyMovableClass &operator=(const MyMovableClass &source);
};

MyMovableClass::MyMovableClass(const MyMovableClass &source) {
    _size = source._size;
    _data = new int[_size];
    *_data = *source._data;
    std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
}

MyMovableClass &MyMovableClass::operator=(const MyMovableClass &source) {
    std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
    if (this == &source) {
        return *this;
    } 
    delete[] _data;
    _data = new int[source._size];
    *_data = *source._data;
    _size = source._size;
    return *this;
}

int main() {
    MyMovableClass class1(10);
    MyMovableClass class2(class1);
    class2 = class1;
    return 0;
}