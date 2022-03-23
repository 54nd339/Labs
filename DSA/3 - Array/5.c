#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the size of array : ");
    int n; scanf("%d",&n);
    int *ar = (int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(int i=0; i<n; i++)
        scanf("%d",ar+i);
    
    int temp = ar[0];
    for(int i=1; i<n-1; i++){
        int t = ar[i];
        ar[i] = temp*ar[i+1];
        temp = t;
    }

    printf("Output : ");
    for(int i=0; i<n; i++)
        printf("%d ",ar[i]);
    free(ar); return 0;
}