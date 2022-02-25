#include <stdio.h>
#include <stdlib.h>
int main(){
    int i, j, temp, m, n;
    printf("Enter the order of the matrix : ");
    scanf("%d%d",&m,&n);
    int **ar = (int **)malloc(m*sizeof(int *));
    for (i=0; i<m; i++)
        *(ar+i) = (int *)malloc(n*sizeof(int));
        
    printf("Enter Matrix Elements : \n");
    for (i=0; i<m; ++i)
        for (j = 0; j < n; ++j)
            scanf("%d", &ar[i][j]);

    for (i=0; i<m; ++i)
        for (j=0; j<n/2; ++j){
            temp=ar[i][j];
            ar[i][j]=ar[i][n-1-j];
            ar[i][n-1-j]=temp;
        }
    
    printf("Output :\n");
    for(i=0; i<m; ++i){
        for(j=0; j<n; ++j)
            printf("%d ", ar[i][j]);
        printf("\n");
    }
    free(ar); return 0;
}