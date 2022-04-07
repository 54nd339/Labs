#include <stdio.h>
int main(){
    printf("Enter number of element : ");
    int n; scanf("%d",&n);
    int arr[n], *p = arr;
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i);
        scanf("%d",p+i);
    }
    for(int i=0; i<n; i++)
        printf("Address of %d is %u\n",*(p+i),(p+i));
    return 0;
}