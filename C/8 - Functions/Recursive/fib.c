#include <stdio.h>
int fib(int n){
    return (n==1 || n==2)? 1: fib(n-1)+fib(n-2);
}
int main(){
    int i,n;
    printf("Enter the no. of terms : ");
    scanf("%d",&n);
    printf("Fibonacci Series : ");
    for(i=1;i<=n;i++)
        printf("%d ",fib(i));
    return 0;
}
