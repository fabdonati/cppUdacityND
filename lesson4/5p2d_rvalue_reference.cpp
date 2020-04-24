// int k = i + j in this case a temporary rvalue i+j is created then assigned to the memory location of k
// int &&l = i + j holds temporarily in memory the result of i+j, it creates a temporary rvalue which holds the result of the addition
#include <iostream>

int main() {
    int i = 1;
    int j = 42;
    int k = i + j;
    int &&l = i + j;
    return 0;
}