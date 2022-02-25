#include <stdio.h>
int main(){
int n,c=1,flag=0;
printf("Enter no. of rows:");
scanf("%d",&n);
for (int i=1;i<2*n;i++){
for (int j=1;j<2*n;j++)
if(i<=n){
if (i==j || i+j==2*n)
printf("%d ",i);
else
printf("  ");
}
else{
if (i==j || i+j==2*n){
printf("%d ",n-c);
flag=1;
}
else
printf("  ");
}
if(flag)
c++;
printf("\n");
}
return 0;
}
