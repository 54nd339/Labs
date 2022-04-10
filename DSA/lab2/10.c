#include <stdio.h>
long fact(int n){
    return (n==1) ? 1 : n*fact(n-1);
}
int main(){
    printf("Enter a no. : ");
    int x; scanf("%d",&x);
    printf("factorial : %ld",fact(x));
    return 0; 
}