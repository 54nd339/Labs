#include <stdio.h>
int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    for (int i=1,k=1; i<=n; i++){
        int l=k;
        for (int j=1; j<=i; j++,k++)
            printf("%d\t",k);
        for (int j=k-2; j>=l; j--)
            printf("%d\t",j);
        printf("\n");
    }
    return 0;
}