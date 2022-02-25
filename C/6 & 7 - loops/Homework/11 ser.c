#include <stdio.h>
#include <math.h>
int main()
{
    int n,a=1,b,i,c=1;
    printf("Enter the no. of terms:");
    scanf("%d",&n);
    printf("Series:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\n",a);
        b=a;a=b+pow(2,c);
        c++;
    }
    return 0;
}
