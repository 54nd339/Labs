#include <stdio.h>
int main(){
int i,j,n,p,m;
printf("Enter no. of elements in the array : ");
scanf("%d",&n);
int ar[n],b[n+1];

for(i=0;i<n;i++){
printf("Enter element %d : ",i+1);
scanf("%d",&ar[i]);
}

printf("Enter an element to insert : ");
scanf("%d",&m);
b[0]=m;
printf("\nAt starting : \n");
for(i=0;i<n;i++)
b[i+1]=ar[i];
for(i=0;i<=n;i++)
printf("element at %d : %d\n",i,b[i]);

printf("\nAt Ending : \n");
for(i=0;i<n;i++)
b[i]=ar[i];
b[n]=m;
for(i=0;i<=n;i++)
printf("element at %d : %d\n",i,b[i]);

printf("\nfrom a point : \n");
printf("Enter a point : ");
scanf("%d",&p);

for(i=0;i<p;i++)
b[i]=ar[i];
b[p]=m;
for(i=p;i<n;i++)
b[i+1]=ar[i];

for(i=0;i<=n;i++)
printf("element at %d : %d\n",i,b[i]);

return 0;
}
