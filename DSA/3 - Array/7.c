#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the size of array : ");
    int n; scanf("%d",&n);
    int *ar = (int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(int i=0; i<n; i++)
        scanf("%d",ar+i);
    printf("Enter k : ");
    int k; scanf("%d",&k);
    
    for(int i=0; i<n-1; i++){
        int m = i;
        for(int j=i+1; j<n; j++)
            if(ar[j] < ar[m]) m=j;
        int temp = ar[m];
        ar[m] = ar[i];
        ar[i] = temp;
    }

    printf("%dth Smallest element : %d \n",k,ar[k-1]);
    printf("%dth Largest element : %d \n",k,ar[n-k]);
    free(ar); return 0;
}    