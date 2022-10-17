#include <stdio.h>
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main() {
    printf("Enter 2 nos. : ");
    int m, n;
    scanf("%d %d", &m, &n);
    printf("Original value : x = %d, y = %d\n", m, n);
    swap(&m, &n);
    printf("New value : x = %d, y = %d\n", m, n);
    return 0;
}