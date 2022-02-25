#include <stdio.h>
#include <math.h>
int main(){
    int a,b,c;
    float s,ar;
    printf("Enter 3 sides of the triangle : \n");
    scanf("%d%d%d",&a,&b,&c);
    s=(float)(a+b+c)/2;
    ar=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Area of the triangle is %f\n",ar);
    return 0;
}
