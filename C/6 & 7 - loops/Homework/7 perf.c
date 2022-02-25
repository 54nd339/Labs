#include <stdio.h>
int main(){
    int num,sum=0,i;
    printf("Enter a number : ");
    scanf("%d",&num);
    for(i=2;i<=num;i++)
        sum+=(!(num%i))*(num/i);
    if (sum==num)
        printf("%d is a perfect no.\n",num);
    else
        printf("%d is not a perfect no.\n",num);
    return 0;
}
