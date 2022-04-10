#include <stdio.h>
#include <stdlib.h>
int sum(int *ar, int n){
    return (n==0) ? 0 : sum(ar,n-1) + *(ar+(n-1));
}
int main(){
    printf("Enter size of array : ");
    int n; scanf("%d",&n);
    int *ar = (int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(int i=0; i<n; i++)
        scanf("%d",ar+i);
    printf ("Sum : %d",sum(ar,n));
    return 0; 
}