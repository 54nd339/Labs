#include <stdio.h>
#define x 0.5
#include <math.h>
int main(){
    printf("Enter base and height of the triangle : ");
    float b; scanf("%d",&b);
    float h; scanf("%d",&h);
    printf("Area of the triangle with base %.2f, height %.2f is %.2f",b,h,(x*b*h));
    return 0;
}