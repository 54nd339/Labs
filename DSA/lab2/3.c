#include <stdio.h>
int count(int n){
    return (n==0)? 0 : 1+count(n/10);
}
int main(){
    printf("Enter a no. : ");
    int x; scanf("%d",&x);
    printf("no. of digits : %d",count(x));
    return 0; 
}