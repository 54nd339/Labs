#include <stdio.h>
int main(){
int n;
printf("Enter no. of rows:");
scanf("%d",&n);
for (int i=1;i<=n;i++){
for (int j=1;j<=n;j++)
if((i==1 || i==n || j==1 || j==n) && (i!=j) && (i+j!=(n+1)))
printf("*");
else
printf(" ");
printf("\n");
}
for (int i=2;i<=n;i++){
for (int j=1;j<=n;j++)
if((i==1 || i==n || j==1 || j==n) && (i!=j) && (i+j!=(1+n)))
printf("*");
else
printf(" ");
printf("\n");
}
return 0;
}
