#include <stdio.h>
int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    for (int i=1; i<=n; i++){
        for (int j=n-i+1; j<n; j++)
            printf("%d ",j);
        printf("0 ");
        for (int j=n-1; j>n-i; j--)
            printf("%d ",j);
        printf("\n");
    }
    return 0;
}