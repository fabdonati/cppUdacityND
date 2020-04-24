// according to this policy, the source pointer is set to nullptr to make ownership exclusive
// whenever a resource management object is copied, the resource handle is transferred to the destination object
// however this is not how it works for the std libraries, as for a short period of time there is a two valid 
// handles to the same resource. This is a problem for concurrent programs, leading to data race problem --> move semantics
#include <iostream>

class ExclusiveCopy {
    int *_myInt;
public:
    ExclusiveCopy() {
        _myInt = (int*)malloc(sizeof(int));
        std::cout << "resource allocated" << std::endl;
    }
    ~ExclusiveCopy() {
        if(_myInt != nullptr) {
            free(_myInt);
            std::cout << "resource deallocated" << std::endl;
        }
    }
    ExclusiveCopy(ExclusiveCopy &source) {
        std::cout << "copy ctor" << std::endl;
        _myInt = source._myInt;
        source._myInt = nullptr;
    }
    ExclusiveCopy &operator=(ExclusiveCopy &source) {
        std::cout << "assignment" << std::endl;
        _myInt = source._myInt;
        source._myInt = nullptr; // invalidate source handle
        return *this;
    }
};

int main() {
    ExclusiveCopy source;
    ExclusiveCopy destination(source);
    ExclusiveCopy destination2;
    destination2 = source;
    return 0;
}