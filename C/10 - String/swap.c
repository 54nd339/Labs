#include <stdio.h>
void swap(int *x, int *y){
    int t = *x;
    *x = *y; *y = t;
}
int main(){
    printf("Enter num1: ");
    int num1; scanf("%d",&num1);
    printf("Enter num2: ");
    int num2; scanf("%d",&num2);
    printf("Before Swapping: num1 is: %d, num2 is: %d\n",num1,num2);
    swap(&num1, &num2);
    printf("After  Swapping: num1 is: %d, num2 is: %d\n",num1,num2);
    return 0;
}