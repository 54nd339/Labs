#include <stdio.h>
int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    for (int i=1; i<=n; i++){
        for (int j=1; j<=(n-i); j++)
            printf("  ");
        for (int j=1; j<=(n+2)+2*(i-1); j++)
            printf("* ");
        for (int j=1; j<=2*(n-i)+1; j++)
            printf("  ");
        for (int j=1; j<=(n+2)+2*(i-1); j++)
            printf("* ");
        printf("\n");
    }
    int k = 3*n+1;
    for (int i=0; i<k; i++){
        for (int j=1; j<=i; j++)
            printf("  ");
        for (int j=1; j<=2*(k-i)-1; j++)
            printf("* ");
        printf("\n");
    }
    return 0;
}