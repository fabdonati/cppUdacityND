#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int*)malloc(2*sizeof(int));
    *(p+0) = 10;
    *(p+1) = 20;
    int *p2 = p;
    printf("p1 address %p\np2 address %p", p, p2);
    printf("p1 value 1 %d, p1 value 2 %d", *(p+0), *(p+1));
    free(p);
    free(p2);
    return 0;
}