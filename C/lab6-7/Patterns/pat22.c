#include <stdio.h>
int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=n-i; j>=1; j--)
            printf("  "); 
        for(int j=1; j<=2*i-1; j++)
            printf("%d ",j);
        printf("\n");
    }
    for(int i=n-1; i>=1; i--){
        for(int j=n-1; j>=i; j--)
            printf("  ");
        for(int j=1; j<=2*i-1; j++)
            printf("%d ",j);
        printf("\n");
    }
    return 0;
}