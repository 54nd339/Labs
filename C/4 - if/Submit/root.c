#include <stdio.h>
#include <math.h>
int main(){
    float a,b,c,d,r1,r2;
    printf("Enter the coefficient of the quadratic : \n");
    scanf("%f%f%f",&a,&b,&c);
    d = (pow(b,2)) - 4*a*c;
    if(d>0){
        r1 = (-b+sqrt(d))/(2*a);
        r2 = (-b-sqrt(d))/(2*a);
        printf("The roots are real and different : %f, %f\n",r1,r2);
        return 0;
    }
    if(d==0){
        r1=(-b)/(2*a);
        printf("The roots are real and same : %f\n",r1);
        return 0;
    }
    printf("The roots are imaginary.\n");
    return 0;
}