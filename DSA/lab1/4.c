#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the size of array : ");
    int n; scanf("%d",&n);
    int *ar = (int *)malloc(n*sizeof(int));
    printf ("Enter array elements : ");
    for(int i=0; i<n; i++)
        scanf("%d",ar+i);
    for (int i=0; i<n-1; i++)
        for (int j=0; j<n-i-1; j++)
           if (*(ar+j) > *(ar+j+1)){
               int temp = *(ar+j);
               *(ar+j) = *(ar+j+1);
               *(ar+j+1) = temp;
           }
    printf("Sorted array: \n");
    for (int i=0; i<n; i++)
        printf("%d ", *(ar+i));
    free(ar);
    return 0;
}