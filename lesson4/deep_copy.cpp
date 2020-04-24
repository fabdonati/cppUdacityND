// idea is to allocate proprietary memory in the destination obj
// then copy content to which source is pointing into the new block of mem
// not unique data, and additional block of memory
#include <iostream>

class DeepCopy {
    int *_myInt;  
public:
    DeepCopy() {
        _myInt = (int*)malloc(sizeof(int));
    }
    DeepCopy(int val) {
        _myInt = (int*)malloc(sizeof(int));    
        *_myInt = val;
        std::cout << "resource allocated at address: " << _myInt << std::endl;
    }
    ~DeepCopy() {
        free(_myInt);
        std::cout << "resource freed at address: " << _myInt << std::endl;
    }
    DeepCopy(DeepCopy &source) {
        _myInt = (int*)malloc(sizeof(int));
        *_myInt = *source._myInt;
        std::cout << "resource allocated (copy) at address: " << _myInt << " with _myInt = "  << *_myInt << std::endl;
    }
    DeepCopy &operator=(DeepCopy &source) {
        //_myInt = (int*)malloc(sizeof(int));
        *_myInt = *source._myInt;
        std::cout << "resource allocated (assignment) at address: " << _myInt << " with _myInt = "  << *_myInt << std::endl;
        return *this;        
    }
};

int main() {
    DeepCopy source(42);
    DeepCopy dest1(source);
    DeepCopy dest2;
    dest2 = dest1;
}