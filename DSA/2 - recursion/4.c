#include <stdio.h>
int first(int n){
    return (n/10) ? first(n/10) : n;
}
int main(){
    printf("Enter a no. : ");
    int x; scanf("%d",&x);
    printf("first digits : %d",first(x));
    return 0; 
}