#include<stdio.h>
int main(){
    printf("Enter Number of rows : ");
    int r; scanf("%d",&r);
    printf("Enter Number of columnss : ");
    int c; scanf("%d",&c);
    printf("Enter the Matrix Elements :\n");
    int a[r][c], count = 0;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++){
            printf("Enter Element %d, %d : ",i+1,j+1);  
            scanf("%d", &a[i][j]);
    	}
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(a[i][j]==0)
    		    count++;    		
    if(count > (r*c)/2)
        printf("The Matrix is a Sparse Matrix\n");
    else
        printf("The Matrix is Not a Sparse Matrix\n");
    return 0;
}