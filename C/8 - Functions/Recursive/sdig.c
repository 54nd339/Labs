#include <stdio.h>
int sum(int n){
    return (n/10)?(n%10)+sum(n/10):n;
}
int main(){
    int a;
    printf("Enter a no. : ");
    scanf("%d",&a);
    printf("sum of the digits of %d is %d",a,sum(a));
    return 0;
}
