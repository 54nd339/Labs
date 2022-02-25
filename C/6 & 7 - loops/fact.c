#include <stdio.h>
int main(){
    int num,i,pro=1;
    printf("Enter a number:");
    scanf("%d",&num);
    for (i=2;i<=num;i++)
        pro*=i;
    printf("Factorial of %d is %d\n",num,pro);
}
