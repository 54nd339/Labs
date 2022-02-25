#include <stdio.h>
int main(){
int sum=0,r,i,j,c;
printf("Enter number of rows:");
scanf("%d",&r);
printf("Enter number of columns:");
scanf("%d",&c);
int num[r][c];
for(i=0;i<r;i++)
for(j=0;j<c;j++){
printf("Enter element %d,%d: ",i,j);
scanf("%d",&num[i][j]);
}
for(i=0;i<r;i++){
for(j=0;j<c;j++)
printf("%d\t",num[i][j]);
printf("\n");
}
return 0;
}
