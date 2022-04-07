#include <stdio.h>
int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    for (int i=1; i<=n; i++){
        for (int j=n; j>=i; j--)
            printf("%d\t",(i%2));
        printf("\n");
    }
    return 0;
}
