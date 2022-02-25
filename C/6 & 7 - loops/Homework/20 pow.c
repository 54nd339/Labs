#include <stdio.h>
int main()
{
    int n,i,x,pro=1;
    printf("Enter the base:");
    scanf("%d",&n);
    printf("Enter the exponent:");
    scanf("%d",&x);
    for(i=1;i<=x;i++)
        pro*=n;
    printf("%d ^ %d = %d\n",n,x,pro);
    return 0;
}
