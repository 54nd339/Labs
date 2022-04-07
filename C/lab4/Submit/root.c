#include <stdio.h>
#include <math.h>
int main(){
    printf("Enter the coefficient of the quadratic : \n");
    float a, b, c; scanf("%f%f%f",&a,&b,&c);
    float d = (pow(b,2)) - 4*a*c;
    if(d > 0){
        float r1 = (-b+sqrt(d))/(2*a);
        float r2 = (-b-sqrt(d))/(2*a);
        printf("The roots are real and different : %f, %f\n",r1,r2);
        return 0;
    }
    if(d == 0){
        float r1 = (-b)/(2*a);
        printf("The roots are real and same : %f\n",r1);
        return 0;
    }
    printf("The roots are imaginary.\n");
    return 0;
}