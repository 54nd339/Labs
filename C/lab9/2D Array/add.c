#include<stdio.h>
void read(int r, int c, int a[r][c]){
    for(int i=0; i<r; i++)
    for(int j=0; j<c; j++){
        printf("Enter Element %d,%d : ",i,j);
        scanf("%d",&a[i][j]);
    }
}

void add(int r, int c, int m1[r][c], int m2[r][c], int add[r][c]){
    for(int i=0; i<r; i++)
    for(int j=0; j<c; j++)
        add[i][j] =  m1[i][j] + m2[i][j];
}

void print(int r, int c, int a[r][c]){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

int main(){
    printf("Enter number of rows for matrix 1 : ");
    int row; scanf("%d",&row);
    printf("Enter number of columns for matrix 1 : ");
    int col; scanf("%d",&col);
    printf("Enter number of rows for matrix 2 : ");
    int ro; scanf("%d",&ro);
    printf("Enter number of columns for matrix 2 : ");
    int co; scanf("%d",&co);
    
    if(row==ro && col==co){
        int m1[row][col], m2[row][col], ad[row][col];
        printf("Enter Matrix 1: \n");
        read(row, col, m1);
        printf("Enter Matrix 2: \n");
        read(row, col, m2);
        add(row, col, m1, m2, ad);
        printf("Matrix 1: \n");
        print(row, col, m1);
        printf("Matrix 2: \n");
        print(row, col, m2);
        printf("Addition Matrix: \n");
        print(row, col, ad);
    }
    else printf("Addition Not possible");
    return 0;
}