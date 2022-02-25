#include <stdio.h>
int first(int n){
    return (n/10)? first(n/10) : n;
}
int main(){
    int x;
    printf("Enter a no. : ");
    scanf("%d",&x);
    printf("first digits : %d",first(x));
    return 0; 
}