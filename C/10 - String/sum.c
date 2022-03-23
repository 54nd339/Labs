#include <stdio.h>
int main(){
    printf("Enter number of element:");
    int n; scanf("%d",&n);
    int arr[n];
    int *p = arr, sum = 0;
    for(int i=0; i<n; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",p+i);
    }
    for(int i=0; i<n; i++)
        sum += *(p+i);
    printf("Sum : %d\n",sum);
    return 0;
}