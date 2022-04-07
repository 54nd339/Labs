#include<stdio.h>
#include<stdlib.h>
int row, col;
void add_row(int (*pa)[col]){
    int *pb = (int *)calloc(row,sizeof(int));
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            pb[i] += pa[i][j];
    for(int i=0; i<row; i++){              
        for(int j=0; j<col; j++)
            printf("%d ", *(*(pa+i)+j));
        printf("  %d \n",*(pb+i));
    }
}

int main(){
    printf("Enter number of rows for matrix : ");
    scanf("%d",&row);
    printf("Enter number of columns for matrix : ");
    scanf("%d",&col);
    int (*pa)[col] = (int(*)[col])malloc(row*col*sizeof(int));
    
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++){
            printf("Enter Element %d,%d: ",i+1,j+1);
            scanf("%d",(*(pa+i)+j));
        }
    add_row(pa);
    return 0;
}