#include <stdio.h>
int main(){
    printf("Enter no. of elements in the array : ");
    int n; scanf("%d",&n);
    int ar[n], sum = 0;
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Entered Elements : ");
    for(int i=0; i<n; i++){
        printf("%d ",ar[i]);
        sum += ar[i];
    }
    printf("\n sum of elements : %d\n",sum);
    return 0;
}