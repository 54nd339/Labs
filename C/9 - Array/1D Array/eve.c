#include <stdio.h>
int main(){
int n,sum=0,c=0;
printf("Enter no. of elements.:");
scanf("%d",&n);
int num[n];
for(int i=0;i<n;i++){
printf("Enter element %d:",(i+1));
scanf("%d",&num[i]);
}
printf("Even nos. in array:\n");
for(int i=0;i<n;i++)
if(num[i]%2==0){
printf("%d\n",num[i]);c++;
}
printf("No. of even nos.: %d\n",c);
return 0;
}
