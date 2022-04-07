#include <stdio.h>
#include <math.h>
int main(){
    printf("Enter radius of the circle : ");
    float r; scanf("%f",&r);
    printf("Area of the circle with radius %.2f is %.2f\n",r,(3.14*r*r));
    return 0;
}