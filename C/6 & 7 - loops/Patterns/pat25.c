#include <stdio.h>
int main(){
int n;
printf("Enter no. of rows:");
scanf("%d",&n);
for (int i=0;i<n;i++){
for (int j=n;j>(n-i);j--)
printf("%d ",j);
for (int j=1;j<=2*(n-i)-1;j++)
printf("%d ",(n-i));
for (int j=n-i;j<n;j++)
printf("%d ",(j+1));
printf("\n");
}
for (int i=2;i<=n;i++){
for (int j=n;j>=i;j--)
printf("%d ",j);
for (int j=1;j<=2*i-3;j++)
printf("%d ",i);
for (int j=i;j<=n;j++)
printf("%d ",j);
printf("\n");
}
return 0;
}
