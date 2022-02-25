#include<stdio.h>
#include<stdlib.h>
int main(){
    int row,col,i,j;
    printf("Enter number of rows for matrix :");
    scanf("%d",&row);
    printf("Enter number of columns for matrix :");
    scanf("%d",&col);
    int a[row][col];
    int *pb=(int *)calloc(row,sizeof(int));
    
    for(i=0;i<row;i++)
    for(j=0;j<col;j++){
        printf("Enter Element %d,%d: ",i+1,j+1);
        scanf("%d",&a[i][j]);          //accept elements
    }
    
    for(i=0;i<row;i++)
    for(j=0;j<col;j++)
    pb[i]+=a[i][j];                   //sum of rows
    
    for(i=0;i<row;i++){              
        for(j=0;j<col;j++)
            printf("%d ",a[i][j]);    //Display original Matrix
        printf("  %d \n",pb[i]);      //Display the sum matrix
    }
    return 0;
}
