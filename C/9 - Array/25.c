#include<stdio.h>
int c1,i,j;
void read(int a[][c1],int r,int c){
    for(i=0;i<r;i++)
    for(j=0;j<c;j++){
        printf("Enter Element %d,%d : ",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
}

int comp(int m1[][c1],int m2[][c1],int r,int c){
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    if(m1[i][j]!=m2[i][j]){
        return 0;//break;
    }
    return 1;
}

void print(int a[][c1],int r,int c){
    for(i=0;i<r;i++){
    for(j=0;j<c;j++)
    printf("%d ",a[i][j]);
    printf("\n");
    }
}

int main(){
    int r1,r2,c2;
    printf("Enter number of rows for matrix 1:");
    scanf("%d",&r1);
    printf("Enter number of columns for matrix 1:");
    scanf("%d",&c1);
    int m1[r1][c1];
    printf("\nEnter Matrix 1: \n");
    read(m1,r1,c1);
    
    printf("\nEnter number of rows for matrix 2:");
    scanf("%d",&r2);
    printf("Enter number of columns for matrix 2:");
    scanf("%d",&c2);
    int m2[r2][c2];
    printf("\nEnter Matrix 2: \n");
    read(m2,r2,c2);
    
    printf("\nMatrix 1: \n");
    print(m1,r1,c1);
    printf("\nMatrix 2: \n");
    print(m2,r2,c2);
    
    if(r1==r2 && c1==c2){
        if(comp(m1,m2,r1,c1))
            printf("Both the matrix are equal\n");
        else
            printf("Both the matrix are not equal\n");
    }
    else printf("Cannot be compared\n");
    return 0;
}
