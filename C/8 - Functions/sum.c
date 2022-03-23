#include <stdio.h>
float sum(float a, float b){
    return a+b;
}
int main(){
    float m, n;
    printf("Enter 2 nos. : ");
    scanf("%f %f",&m,&n);
    float s = sum(m,n);
    printf("sum = %f\n",s);
    return 0;
}