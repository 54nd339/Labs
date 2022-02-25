#include <stdio.h>
#include <stdlib.h>
int sum(int *ar, int n){
    return (n==0) ? 0 : sum(ar,n-1)+*(ar+(n-1));
}
int main(){
    int n,i,*ar;
    printf("Enter size of array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);
    printf ("Sum : %d",sum(ar,n));
    return 0; 
}