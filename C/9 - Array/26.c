#include<stdio.h>
int main(){
    int i,j,r,c,a[10][10],flag=1;
    printf("Enter Number of rows : ");
    scanf("%d",&r);
    printf("Enter Number of columnss : ");
    scanf("%d",&c);
    printf("Enter the Matrix Elements :\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            printf("Enter Element %d,%d : ",i+1,j+1);  
            scanf("%d",&a[i][j]);
    	}
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if((i==j && a[i][j]==1) || (i!=j && a[i][j]==0));
            else {
                flag=0;break;
            }    		
    if(flag)
    printf("The Matrix is an Identity Matrix\n");
    else
    printf("The Matrix is Not an Identity Matrix\n");
    return 0;
}
