#include <stdio.h>

int myFunc(int i) {
    int j = i+1;
    printf("number is: %i, address is %p \n", j, &j);
    return myFunc(j); 
}

int main() {
    
    myFunc(0);
    return 0;
}