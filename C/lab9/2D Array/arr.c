#include <stdio.h>
int main(){
    printf("Enter number of rows:");
    int r; scanf("%d",&r);
    printf("Enter number of columns:");
    int c; scanf("%d",&c);
    int num[r][c];
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            printf("Enter element %d,%d : ",i,j);
            scanf("%d",&num[i][j]);
        }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            printf("%d\t",num[i][j]);
        printf("\n");
    }
    return 0;
}