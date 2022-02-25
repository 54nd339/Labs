#include <stdio.h>
int main(){
int i,j,n;
printf("Enter no. of elements in the array : ");
scanf("%d",&n);
int ar[n];
for(i=0;i<n;i++){
printf("Enter element %d : ",i+1);
scanf("%d",&ar[i]);
}
printf("Entered Elements : ");
for(i=0;i<n;i++)
printf("%d ",ar[i]);
printf("\nOutput : ");
for(i=n;i>0;i--)
printf("%d ",ar[i-1]);
return 0;
}
