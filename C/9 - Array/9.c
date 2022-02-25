#include<stdio.h>
int main(){
    int n,i,max,min,count,j;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    max=ar[0],min=ar[0];
    for(i=0;i<n;i++){
        if(max<ar[i])
        max=ar[i];
        if(min>ar[i])
        min=ar[i];
    }
    printf("max : %d, min: %d\n",max,min);
    return 0;
}
