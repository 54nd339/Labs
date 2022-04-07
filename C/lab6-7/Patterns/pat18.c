#include <stdio.h>
int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    for (int i=1,k=1; i<=n; i++){
        for (int j=n; j>=i; j--,k++)
            printf("%d\t",k);
        printf("\n");
    }
    return 0;
}