#include <stdio.h>
int main(){
    printf("Enter no. of elements in the array : ");
    int n; scanf("%d",&n);
    int ar[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Entered Elements : ");
    for(int i=0; i<n; i++)
        printf("%d ",ar[i]);
    printf("\nOutput : ");
    for(int i=n; i>0; i--)
        printf("%d ",ar[i-1]);
    return 0;
}