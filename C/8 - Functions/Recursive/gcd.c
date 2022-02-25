#include <stdio.h>
int gcd(int n1,int n2){
    return (n1%n2)?n2:gcd(n2,n1%n2);
}
int main(){
    int a,b,g;
    printf("Enter 2 nos. : ");
    scanf("%d %d",&a,&b);
    g=(a>b)?gcd(a,b):gcd(b,a);
    printf("GCD of %d and %d is %d\n",a,b,g);
    return 0;
}
