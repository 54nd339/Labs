#include <stdio.h>
int main(){
int r,c,n,i,j;

//enter matrix
/*printf("Enter no. of rows: ");
scanf("%d",&r);
printf("Enter no. of columns: ");
scanf("%d",&c);*/

printf("Enter dimension of nxn matrix: ");
scanf("%d",&n);
r=n;c=n;
int m[r][c], t[c][r];
printf("Enter matrix elements:\n");
for (i=0;i<r;i++)
for (j=0;j<c;j++){
printf("Enter element %d,%d: ",(i+1),(j+1));
scanf("%d", &m[i][j]);
}

printf("Entered matrix: \n");
for (i=0;i<r;++i){
for (j=0;j<c;++j)
printf("%d ",m[i][j]);
printf("\n");
}

printf("Transpose of the matrix:\n");
for (i=0;i<c;++i){
for (j=0;j<r;++j)
printf("%d ",m[j][i]);
printf("\n");
}
return 0;
}
