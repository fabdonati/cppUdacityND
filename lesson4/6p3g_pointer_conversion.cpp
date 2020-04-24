// when we have a unique pointer and we want a shared pointer, we use move(steals the resource from the unique ptr and invalidates its resource handle on the heap-allocated int)
// we receive a weak pointer (shared but with no count) and we want to be sure the the object is not deallocated before we finish working on it. we lock it (conversion to shared ptr)
#include <iostream>
#include <memory>

using namespace std;

int main() {
    unique_ptr<int> uniquePtr(new int);
    shared_ptr<int> sharedPtr1 = move(uniquePtr);
    weak_ptr<int> weakPtr(sharedPtr1);
    shared_ptr<int> sharedPtr2 = weakPtr.lock();

    int *rawPtr = sharedPtr2.get();
    delete rawPtr;
    return 0;
}