#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the order of the matrix : ");
    int m, n; scanf("%d%d",&m,&n);
    int **ar = (int **)malloc(m*sizeof(int *));
    for (int i=0; i<m; i++)
        *(ar+i) = (int *)malloc(n*sizeof(int));
        
    printf("Enter Matrix Elements : \n");
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            scanf("%d", &ar[i][j]);

    for (int i=0; i<m; ++i)
        for (int j=0; j<n/2; ++j){
            int temp = ar[i][j];
            ar[i][j] = ar[i][n-1-j];
            ar[i][n-1-j] = temp;
        }
    
    printf("Output :\n");
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j)
            printf("%d ", ar[i][j]);
        printf("\n");
    }
    free(ar); return 0;
}