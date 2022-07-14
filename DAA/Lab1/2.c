#include <stdio.h>
void swap(int *x, int *y) { 
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main() {
    printf("Enter 3 nos. : ");
    int a; scanf("%d", &a);
    int b; scanf("%d", &b);
    int c; scanf("%d", &c);
    swap(&c, &b);
    swap(&a, &b);
    printf("\na : %d, b : %d, c : %d\n", a, b, c);
}