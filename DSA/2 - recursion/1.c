#include <stdio.h>
long power(int m,int n){
    return (n!=0)? m*power(m,n-1) : 1;
}
int main(){
    int x,y;
    printf("Enter the base and exponent : ");
    scanf("%d%d",&x,&y);
    printf("%d^%d = %ld",x,y,power(x,y));
    return 0; 
}