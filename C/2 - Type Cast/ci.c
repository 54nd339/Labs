#include <stdio.h>
#include <math.h>
int main(){
    int p,r,t;
    float A,ci;
    printf("Enter the principal amount : ");
    scanf("%d",&p);
    printf("Enter the rate of interst : ");
    scanf("%d",&r);
    printf("Enter the time period : ");
    scanf("%d",&t);
    A=p*pow((1+(float)r/100),t);
    ci=A-p;
    printf("The compound intrest : %f\n",ci);
    printf("The final amount : %f\n",A);
}
