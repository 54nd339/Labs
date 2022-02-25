#include <stdio.h>
int main(){
    int *p,n,i;
    printf("Enter number of element:");
    scanf("%d",&n);
    int arr[n];
    p=arr;
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i);
        scanf("%d",p+i);
    }
    for(i=0;i<n;i++)
        printf("Address of %d is %u\n",*(p+i),(p+i));
    return 0;
}
