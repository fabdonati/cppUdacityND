#include <memory>
#include <iostream>

// raw or default pointer is created on the heap, it needs delete the resource at the end
void RawPointer() {
    int * raw = new int;
    *raw = 1;
    delete raw;
}

// unique pointer is created on the stack, we don't need delete at the end
void UniquePointer() {
    std::unique_ptr<int> unique(new int);
    *unique = 2;
}

int main() {
    auto sourcePtr = std::make_unique<int>(2);
    auto destinPtr = std::move(sourcePtr);
    if (sourcePtr != nullptr) {
        std::cout << "sourcePtr address: " << &sourcePtr << ", value: " << *sourcePtr << std::endl;
    }
    std::cout << "destinPtr address: " << &destinPtr << ", value: " << *destinPtr << std::endl;
    return 0;
}