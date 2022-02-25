#include <stdio.h>
int main()
{
    int n;
    printf("Enter no. of rows");
    scanf("%d",&n);

    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++)
            printf("A");
        for(int j=1;j<=n-i;j++)
            printf(" ");
        for(int j=1;j<=i;j++)
            printf("A");
        for(int j=1;j<=n-i;j++)
            printf(" ");
        for(int j=1;j<=i;j++)
            printf("A");
        printf("\n");
    }
    return 0;
}
