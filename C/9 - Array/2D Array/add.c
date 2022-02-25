#include<stdio.h>
int col;
void read(int a[][col],int r,int c){
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++){
        printf("Enter Element %d,%d: ",i,j);
        scanf("%d",&a[i][j]);
    }
}

void add(int m1[][col],int m2[][col],int add[][col],int r,int c){
    for(int i=0;i<r;i++)
    for(int j=0;j<c;j++)
    add[i][j] =  m1[i][j] + m2[i][j];
}

void print(int a[][col],int r,int c){
    for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)
    printf("%d ",a[i][j]);
    printf("\n");
    }
}

int main(){
    int row,ro,co;
    printf("Enter number of rows for matrix 1:");
    scanf("%d",&row);
    printf("Enter number of columns for matrix 1:");
    scanf("%d",&col);
    printf("Enter number of rows for matrix 2:");
    scanf("%d",&ro);
    printf("Enter number of columns for matrix 2:");
    scanf("%d",&co);
    
    if(row==ro && col==co){
    int m1[row][col],m2[row][col],ad[row][col];
    printf("Enter Matrix 1: \n");
    read(m1,row,col);
    printf("Enter Matrix 2: \n");
    read(m2,row,col);
    add(m1,m2,ad,row,col);
    printf("Matrix 1: \n");
    print(m1,row,col);
    printf("Matrix 2: \n");
    print(m2,row,col);
    printf("Addition Matrix: \n");
    print(ad,row,col);
    }
    else printf("Addition Not possible");
    return 0;
}
