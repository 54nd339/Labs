#include <stdio.h>
int main(){
int n,c=0;
printf("Enter no. of items:");
scanf("%d",&n);
int ar[n];
for(int i=0;i<n;i++){
printf("Enter element %d:",(i+1));
scanf("%d",&ar[i]);
}
int l=ar[0];
for(int i=1;i<n;i++)
if (l<ar[i]){
l=ar[i];
c++;
}
printf("Largest No. : %d\n",l);
printf("No. of leaders : %d\n",c);
return 0;
}
