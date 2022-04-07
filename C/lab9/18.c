#include <stdio.h>
int main(){
    printf("Enter n for NxN matrix : ");
    int n; scanf("%d",&n);
    int mat[n][n];
    printf("Enter the Elements of the matrix :\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            printf("Enter Element %d,%d : ",i+1,j+1);
            scanf("%d",&mat[i][j]);
        }
    int ls = 0, rs = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(i==j)
                ls += mat[i][j];
            if((i+j) == (n-1))
                rs += mat[i][j];
        }
    printf("Sum of left diagonal : %d\n",ls);
    printf("Sum of right diagonal : %d\n",rs);     
    return 0;
}