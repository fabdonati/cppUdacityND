#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int *p = (int*)malloc(sizeof(int));
    printf("address= %p, value= %d\n", p, *p);

    int *ap = (int*)calloc(3, sizeof(int));
    printf("address= %p, value= %d\n", ap, *ap);

    int *p2 = (int*)malloc(3*sizeof(int));
    p2[0] = 1;
    p2[1] = 2;
    p2[2] = 3;
    printf("address= %p, value1=%d, value2=%d, value3=%d\n", p2, p2[0], p2[1], p2[2]);


    return 0;
}