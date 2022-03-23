#include <stdio.h>
int main(){
    //enter matrix
    /*printf("Enter no. of rows: ");
    scanf("%d",&r);
    printf("Enter no. of columns: ");
    scanf("%d",&c);*/

    printf("Enter dimension of nxn matrix : ");
    int n; scanf("%d",&n);
    int r = n, c = n;
    int m[r][c], t[c][r];
    printf("Enter matrix elements :\n");
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++){
            printf("Enter element %d,%d : ",(i+1),(j+1));
            scanf("%d", &m[i][j]);
        }

    printf("Entered matrix : \n");
    for (int i=0; i<r; ++i){
        for (int j=0; j<c; ++j)
            printf("%d ",m[i][j]);
        printf("\n");
    }

    printf("Transpose of the matrix :\n");
    for (int i=0; i<c; ++i){
        for (int j=0; j<r; ++j)
            printf("%d ",m[j][i]);
        printf("\n");
    }
    return 0;
}