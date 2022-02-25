#include<stdio.h>
int main(){
    int i,j,r,c,a[10][10],count=0;
    printf("Enter Number of rows : ");
    scanf("%d",&r);
    printf("Enter Number of columnss : ");
    scanf("%d",&c);
    printf("Enter the Matrix Elements :\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            printf("Enter Element %d, %d",i+1,j+1);  
            scanf("%d", &a[i][j]);
    	}
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(a[i][j]==0)
    		count++;    		
    if(count > (r*c)/2)
    printf("The Matrix is a Sparse Matrix\n");
    else
    printf("The Matrix is Not a Sparse Matrix\n");
    return 0;
}
