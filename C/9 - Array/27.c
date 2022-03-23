#include<stdio.h>
int main(){
    printf("Enter the dimension of the matrix : ");
    int n; scanf("%d",&n);
    int ar[n][n];
    printf("Enter the elements of the array :\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            printf("Enter elment %d,%d : ",i+1,j+1);
            scanf("%d",&ar[i][j]);
        }    
    printf("Original Matrix :\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%d ",ar[i][j]);
        printf("\n");
    }
    printf("New Matrix :\n");
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--)
            printf("%d ",ar[j][i]);
        printf("\n");
    }
    return 0;
}