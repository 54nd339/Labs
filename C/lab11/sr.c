#include<stdio.h>
int main(){
    printf("Enter number of rows for matrix : ");
    int row; scanf("%d",&row);
    printf("Enter number of columns for matrix : ");
    int col; scanf("%d",&col);
    int a[row][col], b[row];
    int (*pa)[col], *pb;
    pa = a; pb = b;
    
    for(int i=0; i<row; i++)
        b[i] = 0;
    
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++){
            printf("Enter Element %d,%d : ",i+1,j+1);
            scanf("%d",(*(pa+i)+j));
        }
    
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            pb[i] += pa[i][j];
    
    for(int i=0; i<row; i++){              
        for(int j=0; j<col; j++)
            printf("%d ", *(*(pa+i)+j));
        printf("  %d \n",*(pb+i));
    }
    return 0;
}