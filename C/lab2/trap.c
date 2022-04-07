#define h 10.5
#define x 0.5
#define sum(a,b) a+b
#include <stdio.h>
int main(){
    printf("Enter the bases of the trapezium : \n");
    int b1, b2; scanf("%d%d",&b1,&b2);
    float area = (float)x*(sum(b1,b2))*h;
    printf("Area of the trapezium is %f %d %f %f\n",x,sum(b1,b2),h,area);
    return 0;
}