#include <stdio.h>
int fact(int n){
    if(n==0)
        return 1;
    else
        return (n*fact(n-1));
}
int main(){
    printf("Enter a no. : ");
    int n; scanf("%d",&n);
    printf("Factorial : %d",fact(n));
    return 0;
}