#include <stdio.h>
int main(){
    int r=3, c=4;
    /*printf("Enter no. of rows: ");
    scanf("%d",&r);
    printf("Enter no. of columns: ");
    scanf("%d",&c);*/
    int m[r][c], o[r][c];
    printf("Enter matrix elements:\n");
    for (int i=0; i<r; i++)
        for (int j=0; j<c; j++){
            printf("Enter element %d,%d : ",(i+1),(j+1));
            scanf("%d",&m[i][j]);
        }
    printf("Enter a scalar no. : ");
    int n; scanf("%d",&n);
    printf("Entered matrix: \n");
    for (int i=0; i<r; ++i){
        for (int j=0; j<c; ++j){
            printf("%d\t",m[i][j]);
            o[i][j]=n*m[i][j];
        }
        printf("\n");
    }
    printf("Output: \n");
    for (int i=0; i<r; ++i){
        for (int j=0; j<c; ++j)
            printf("%d\t",o[i][j]);
        printf("\n");
    }
    return 0;
}