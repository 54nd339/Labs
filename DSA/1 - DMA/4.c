#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ar, i, j, temp, n;
    printf("Enter the no. of elements in the array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    printf ("Enter array elements :\n");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);
    for (i=0;i<n-1;i++)
        for (j=0;j<n-i-1;j++)
           if (*(ar+j)>*(ar+j+1)){
               temp=*(ar+j);
               *(ar+j)=*(ar+j+1);
               *(ar+j+1)=temp;
           }
    printf("Sorted array: \n");
    for (i=0;i<n;i++)
        printf("%d ", *(ar+i));
    free(ar);
    return 0;
}