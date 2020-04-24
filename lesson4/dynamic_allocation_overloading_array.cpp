#include <iostream>
#include <stdlib.h>

class MyClass {
    int _myMember;
public:
    MyClass() {
        std::cout << "Constructor is called\n";
    }

    ~MyClass() {
        std::cout << "Destructor is called\n";
    }

    void *operator new[](size_t size) {
        std::cout << "new: Allocating " << size << " bytes of memory" << std::endl;
        void *p = malloc(size);

        return p;
    }

    void operator delete[](void *p) {
        std::cout << "delete: Memory is freed now" << std::endl;
        free(p);
    }
};

int main() {
    MyClass *p = new MyClass[3](); // 8 bytes overhead to keep track of the allocated blocks of memory
    delete[] p;
    return 0;
}