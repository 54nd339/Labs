#include<stdio.h>
#include<stdlib.h>
int main(){
    int row,col,i,j;
    printf("Enter number of rows for matrix : ");
    scanf("%d",&row);
    printf("Enter number of columns for matrix : ");
    scanf("%d",&col);
    int a[row][col],b[row][col];
    
    for(i=0;i<row;i++)
    for(j=0;j<col;j++){
        printf("Enter Element %d,%d : ",i+1,j+1);
        scanf("%d",&a[i][j]);  
    }
    
    for(i=0;i<row;i++)
    for(j=0;j<col;j++){
        b[i][j]=a[i][j];
        if(j>i)
        b[i][j]=0;                   
    }
    
    for(i=0;i<row;i++) {             
        for(j=0;j<col;j++)
            printf("%d ",a[i][j]);    
        printf("\n");
    } 
    printf("Output :\n"); 
    for(i=0;i<row;i++) {             
        for(j=0;j<col;j++)
            printf("%d ",b[i][j]);    
        printf("\n");
    }
    return 0;
}
