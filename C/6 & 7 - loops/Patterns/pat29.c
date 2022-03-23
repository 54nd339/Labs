#include <stdio.h>
int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    for (int i=1; i<2*n; i++){
        for (int j=1; j<2*n; j++)
            if (i==j || i+j==2*n)
                printf("  ");
            else
                printf("1 ");
        printf("\n");
    }
    return 0;
}