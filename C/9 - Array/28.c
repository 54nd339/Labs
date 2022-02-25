#include <stdio.h>
int main(){
int i,j,n,sum=0,f=0,b=0;
printf("Enter no. of elements in the array : ");
scanf("%d",&n);
int ar[n],max[n];
for(i=0;i<n;i++){
printf("Enter element %d : ",i+1);
scanf("%d",&ar[i]);
}
printf("Entered Elements :\n");
for(i=0;i<n;i++){
printf("%d\n",ar[i]);
f=(i==n-1)?-1:ar[i+1];
b=(i==0)?-1:ar[i-1];
max[i]=(f>b)?f:b;
}
for(i=0;i<n;i++)
printf("%d is the largest integer next to %d\n",max[i],ar[i]);
}
