#include <stdio.h>
    float sum(float a, float b){
    return a+b;
}
int main(){
    float m,n,s;
    printf("Enter 2 nos.");
    scanf("%f %f",&m,&n);
    s=sum(m,n);
    printf("sum = %f\n",s);
    return 0;
}
