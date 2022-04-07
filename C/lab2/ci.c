#include <stdio.h>
#include <math.h>
int main(){
    printf("Enter the principal amount : ");
    int p; scanf("%d",&p);
    printf("Enter the rate of interst : ");
    int r; scanf("%d",&r);
    printf("Enter the time period : ");
    int t; scanf("%d",&t);
    float A = p*pow((1+(float)r/100),t);
    float ci = A-p;
    printf("The compound intrest : %f\n",ci);
    printf("The final amount : %f\n",A);
}