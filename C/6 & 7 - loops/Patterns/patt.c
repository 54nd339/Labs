#include <stdio.h>
int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        for(int j=n-i; j>=1; j--)
            printf(" ");
        for(int k=1; k<=2*i-1; k++)
            printf("$");
        for(int j=n-i; j>=1; j--)
            printf("  ");
        for(int k=1; k<=2*i-1; k++)
            printf("$");
        printf("\n");
    }
    return 0;
}