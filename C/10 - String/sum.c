#include <stdio.h>
int main(){
    int *p,n,i,sum=0;
    printf("Enter number of element:");
    scanf("%d",&n);
    int arr[n];
    p=arr;

    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",p+i);
    }

    for(i=0;i<n;i++)
        sum+=*(p+i);

    printf("Sum : %d\n",sum);
    return 0;
}
