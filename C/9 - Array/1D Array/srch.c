#include <stdio.h>
int main(){
int item, n, pos=-1;
printf("Enter an item:");
scanf("%d",&item);
printf("Enter no. of items:");
scanf("%d",&n);
int ite[n];
for(int i=0;i<n;i++){
printf("Enter item %d:",(i+1));
scanf("%d",&ite[i]);
}
for(int i=0;i<n;i++){
if (item==ite[i]){
pos=i+1;
break;
}
}
if(pos==-1)
printf("Item not found\n");
else
printf("Found at pos.: %d\n", pos);
}
