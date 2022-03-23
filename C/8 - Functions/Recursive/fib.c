#include <stdio.h>
int fib(int n){
    return (n==1 || n==2) ? 1 : fib(n-1)+fib(n-2);
}
int main(){
    printf("Enter the no. of terms : ");
    int n; scanf("%d",&n);
    printf("Fibonacci Series : ");
    for(int i=1; i<=n; i++)
        printf("%d ",fib(i));
    return 0;
}