#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char **argv) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("Original value : x = %d, y = %d\n", a, b);
    swap(&a, &b);
    printf("New value : x = %d, y = %d\n", a, b);
    return 0;
}