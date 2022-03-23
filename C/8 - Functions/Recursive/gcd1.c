#include <stdio.h>
int gcd(int n1,int n2){
    return (n2!=0) ? gcd(n2, n1%n2) : n1;
}
int main(){
    int a,b;
    printf("Enter 2 nos. : ");
    scanf("%d %d",&a,&b);
    printf("GCD of %d and %d is %d.",a,b,gcd(a,b));
    return 0;
}