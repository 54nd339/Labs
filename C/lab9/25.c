#include<stdio.h>
void read(int r, int c, int a[r][c]) {
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            printf("Enter Element %d,%d : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
}

int comp(int r, int c, int m1[r][c], int m2[r][c]){
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(m1[i][j]!=m2[i][j])
                return 0;//break;
    return 1;
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
    int r1; scanf("%d",&r1);
    printf("Enter number of columns for matrix 1 : ");
    int c1; scanf("%d",&c1);
    printf("\nEnter Matrix 1 : \n");
    int m1[r1][c1]; read(r1, c1, m1);
    
    printf("\nEnter number of rows for matrix 2 : ");
    int r2; scanf("%d",&r2);
    printf("Enter number of columns for matrix 2 : ");
    int c2; scanf("%d",&c2);
    printf("\nEnter Matrix 2: \n");
    int m2[r2][c2]; read(r2, c2, m2);
    
    printf("\nMatrix 1: \n");
    print(m1, r1, c1);
    printf("\nMatrix 2: \n");
    print(m2, r2, c2);
    
    if(r1==r2 && c1==c2){
        if(comp(m1, m2, r1, c1))
            printf("Both the matrix are equal\n");
        else
            printf("Both the matrix are not equal\n");
    }
    else printf("Cannot be compared\n");
    return 0;
}