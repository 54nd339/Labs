#include <stdio.h>
int main()
{
    int n;
    printf("Enter no. of rows");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        for(int j=n-i;j>=1;j--)
            printf(" "); 
        for(int k=1;k<=2*i-1;k++)
            printf("%d",i);
        for(int j=n-i;j>=1;j--)
            printf("  ");
        for(int k=1;k<=2*i-1;k++)
            printf("%d",i);
        printf("\n");
    }
    
    for(int i=n-1;i>=1;i--)
    {
        for(int j=n-1;j>=i;j--)
            printf(" ");
        for(int k=1;k<=2*i-1;k++)
            printf("%d",i);
        for(int j=n-1;j>=i;j--)
            printf("  ");
        for(int k=1;k<=2*i-1;k++)
            printf("%d",i);
        printf("\n");
    }
    return 0;
}
