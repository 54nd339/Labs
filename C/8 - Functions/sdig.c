#include <stdio.h>
int sum(int n){
    int m = n, sum = 0;
    while(m != 0){
        sum += m % 10;
        m /= 10;
    }
    return sum;
}
int main(){
    int a;
    printf("Enter a no. : ");
    scanf("%d",&a);
    printf("sum of the digits of %d is %d",a,sum(a));
    return 0;
}