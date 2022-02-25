#include<stdio.h>
int main(){
    int n,i,j,t;
    printf("Enter no. of elements : ");
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("\nOriginal order: ");
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\nAscending order: ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(ar[j]>ar[i]){
              t=ar[i];
              ar[i]=ar[j];
              ar[j]=t;  
            }
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\nDescending order: ");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(ar[j]<ar[i]){
              t=ar[i];
              ar[i]=ar[j];
              ar[j]=t;  
            }
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    return 0;
}
