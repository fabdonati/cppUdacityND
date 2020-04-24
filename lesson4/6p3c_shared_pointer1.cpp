// shared pointer owns the resource it points to, only difference is that they keep a counter, that when is set to zero enables memory to be freed
// useful when requires access to memory location on the heap in multiple parts of the program
#include <iostream>
#include <string>
#include <memory>

int main() {
    std::shared_ptr<int> shared1(new int);
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;

    {
        std::shared_ptr<int> shared2 = shared1;
        std::cout << "shared pointer count = " << shared1.use_count() << std::endl; 
    }

    std::cout << "shared pointer count = " << shared1.use_count() << std::endl;
    return 0;
}