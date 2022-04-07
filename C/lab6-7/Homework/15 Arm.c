#include <stdio.h>
int main(){
    printf("Enter a number : ");
    int n; scanf("%d",&n);
    int m = n, sum = 0;
    while (n>0){
        int r = n%10;
        sum += (r*r*r);
        n /= 10;
    }
    if(m == sum)
        printf("%d is an Armstrong no.\n",m);
    else
        printf("%d is not an Armstrong no.\n",m);
    return 0;
}