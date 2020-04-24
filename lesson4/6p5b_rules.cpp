// pass by reference when the function is supposed to modify the ownership of an existing smart pointer and not a copy.
// pass a non-const reference to a unique_ptr to a function that might modify it in any way (also deleting or reassignign to a different resource)
// pass a const reference to a unique_ptr is not useful as the function cannot do anything
// pass a const or non-const reference to a shared_ptr. first when we want to say that the function only reads from the pointer or might create another one to share ownership
// pass raw pointer (can be NULL) or plain reference when function does not modify the smart pointer. the internal raw pointer to the obj can be retreived with get()
// in this case, do not delete them, as they have to be considered as owned by the smart pointers from which the raw reference has been obtained
// with returning values, only return a smart pointer if the caller needs to manipulate or access the pointer properties, otherwise use a raw pointer
// smart pointers should always be returned by value
#include <iostream>
#include <memory>

using namespace std;


class MyClass {
    int _member;
public:
    MyClass(int val) : _member(val){}
    ~MyClass() {cout << "freed memory at address=" << this << endl;}
    void PrintVal() {cout << ", value=" << _member << ", address=" << this << endl;}
};

void f(shared_ptr<MyClass> ptr) {
    cout << "shared_ptr (ref_cnt=" << ptr.use_count() << ") " << &ptr;
    ptr->PrintVal();
}

int main() {
    shared_ptr<MyClass> sharedPtr = make_shared<MyClass>(23);
    cout << "shared_ptr (ref_cnt=" << sharedPtr.use_count() << ") " << &sharedPtr;
    sharedPtr->PrintVal();

    f(sharedPtr);
    cout << "shared_ptr (ref_cnt=" << sharedPtr.use_count() << ") " << &sharedPtr;
    sharedPtr->PrintVal();

    return 0;
}