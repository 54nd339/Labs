#include <stdio.h>
int main(){
int i,j,n,sum=0;
printf("Enter no. of elements in the array : ");
scanf("%d",&n);
int ar[n];
for(i=0;i<n;i++){
printf("Enter element %d : ",i+1);
scanf("%d",&ar[i]);
}
printf("Entered Elements : ");
for(i=0;i<n;i++){
printf("%d ",ar[i]);
sum+=ar[i];
}
printf("\n sum of elements : %d\n",sum);
return 0;
}
