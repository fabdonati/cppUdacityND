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
        delete[] _data; // dtor
    }

    MyMovableClass(const MyMovableClass &source); // copy ctor
    MyMovableClass &operator=(const MyMovableClass &source); // copy assignment
    MyMovableClass(MyMovableClass &&source); //move ctor
    MyMovableClass &operator=(MyMovableClass &&source); // move assignment operator
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

// move ctor takes a rvalue reference to a source obj of the same class so that the obj can be used within the scope of the move ctor
// data handles are copied from source to target
MyMovableClass::MyMovableClass(MyMovableClass &&source) {
    std::cout << "MOVING (ctor) instance " << &source << " to instance " << this << std::endl;
    _data = source._data;
    _size = source._size;
    source._data = nullptr;
    source._size = 0;
}

MyMovableClass &MyMovableClass::operator=(MyMovableClass &&source) {
    std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
    if (this == &source) {
        return *this;
    }
    delete[] _data;
    _data = source._data;
    _size = source._size;
    source._data = nullptr;
    source._size = 0;
    return *this;
}

void useObject(MyMovableClass obj) {
    std::cout << "using object " << &obj << std::endl;
}

int main() {
// //test 1
//     MyMovableClass obj1(100), obj2(200);
//     MyMovableClass obj3(obj1);
//     MyMovableClass obj4 = obj1;
//     obj4 = obj2;
// //test 2

    MyMovableClass obj1(10);
    useObject(std::move(obj1));
    // obj1 = MyMovableClass(200); // move assignment operator
    // MyMovableClass obj2(MyMovableClass(300));  // move ctor
    return 0;
}