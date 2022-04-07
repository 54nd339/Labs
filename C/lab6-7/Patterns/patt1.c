#include <stdio.h>
int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    for(int i=0; i<=n-1; i++){
        for(int j=1; j<=i; j++)
            printf(" ");
        for(int k=1; k<=2*(n-i)-1; k++)
            printf("$");
        for(int j=1; j<=i; j++)
            printf("  ");
        for(int k=1; k<=2*(n-i)-1; k++)
            printf("$");
        printf("\n");
    }
    return 0;
}