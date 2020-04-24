#include <stdlib.h>
#include <stdio.h>

const int ARR_SIZE = 1000;

int main() {
    int *intArray = (int*)malloc(sizeof(int) * ARR_SIZE);
    for (int i = 0; i < ARR_SIZE; i++) {
        intArray[i] = i;
    }
    intArray = (int*)realloc(intArray, sizeof(int) * ARR_SIZE * 2);
    for (int i = 0; i < ARR_SIZE * 2; i++) {
        intArray[i] = i;
    }
    //p[0] = 1; p[1] = 2;

    //p = (int*)realloc(p, 4*sizeof(int));
    //p[2] = 3; p[3] = 4;

    //p = (int*)realloc((int*)p, 2*sizeof(int));

    //printf("address=%p, value=%d\n", p+0, *(p+0));
    //printf("address=%p, value=%d\n", p+1, *(p+1));
    //printf("address=%p, value=%d\n", p+2, *(p+2)); // not advisable, dangling pointers
    //printf("address=%p, value=%d\n", p+3, *(p+3)); // not advisable, dangling pointers

    free(intArray);
    return 0;
}