#include <stdio.h>
int main(){
int n;
printf("Enter no. of rows:");
scanf("%d",&n);
for (int i=1;i<=n;i++){
for (int j=1;j<i;j++)
printf("  ");
for (int j=65;j<=65+(n-i);j++)
printf("%c ",(char)j);
for (int j=65+(n-i);j>=65;j--)
printf("%c ",(char)j);
printf("\n");
}
return 0;
}
