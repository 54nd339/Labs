#include <stdio.h>
int main(){
int n;
printf("Enter no. of rows:");
scanf("%d",&n);
for (int i=1;i<=n;i++){
for (int j=n-i+1;j<n;j++)
printf("%d ",j);
for (int j=i;j<=n;j++)
printf("%d ",n);
printf("\n");
}
return 0;
}
