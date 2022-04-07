#include<stdio.h>
int main(){
    printf("Enter Number of rows : ");
    int r; scanf("%d",&r);
    printf("Enter Number of columns : ");
    int c; scanf("%d",&c);
    printf("Enter the Matrix Elements :\n");
    int a[r][c], flag = 1;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            printf("Enter Element %d,%d : ",i+1,j+1);  
            scanf("%d",&a[i][j]);
    	}
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if((i==j && a[i][j]==1) || (i!=j && a[i][j]==0));
            else {
                flag = 0; break;
            }    		
    if(flag)
        printf("The Matrix is an Identity Matrix\n");
    else
        printf("The Matrix is Not an Identity Matrix\n");
    return 0;
}