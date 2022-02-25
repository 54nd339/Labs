#include<stdio.h>
#include<stdlib.h>
int row,col,i,j;
void add_row(int (*pa)[col]){
    int *pb=(int *)calloc(row,sizeof(int));
    for(i=0;i<row;i++)
    for(j=0;j<col;j++)
    pb[i]+=pa[i][j];                        //sum of rows
    
    for(i=0;i<row;i++){              
        for(j=0;j<col;j++)
            printf("%d ", *(*(pa+i)+j));    //Display original Matrix
        printf("  %d \n",*(pb+i));          //Display the sum matrix
    }
}

int main(){
    printf("Enter number of rows for matrix :");
    scanf("%d",&row);
    printf("Enter number of columns for matrix :");
    scanf("%d",&col);
    int (*pa)[col]=(int(*)[col])malloc(row*col*sizeof(int));
    
    for(i=0;i<row;i++)
    for(j=0;j<col;j++){
        printf("Enter Element %d,%d: ",i+1,j+1);
        scanf("%d",(*(pa+i)+j));            //accept elements
    }
    
    add_row(pa);
    return 0;
}
