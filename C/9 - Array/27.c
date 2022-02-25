#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter the dimension of the matrix : ");
    scanf("%d",&n);
    int ar[n][n];
    printf("Enter the elements of the array :\n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        printf("Enter elment %d,%d : ",i+1,j+1);
        scanf("%d",&ar[i][j]);
    }    
    printf("Original Matrix :\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%d ",ar[i][j]);
        printf("\n");
    }
    printf("New Matrix :\n");
    for(i=0;i<n;i++){
        for(j=n-1;j>=0;j--)
            printf("%d ",ar[j][i]);
        printf("\n");
    }
    return 0;
}
