#include <stdio.h>
#define x 0.5
#include <math.h>
int main(){
    int b,h;
    printf("Enter base of the triangle : ");
    scanf("%d",&b);
    printf("Enter height of the triangle : ");
    scanf("%d",&h);
    printf("Area of the triangle with base %d, height %d is %f",b,h,(x*b*h));
    return 0;
}