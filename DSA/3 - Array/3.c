#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the size of array : ");
    int n; scanf("%d",&n);
    int *ar = (int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(int i=0; i<n; i++)
        scanf("%d",ar+i);
    
    int i = 0, j = n-1;
    while(j >= i) {
        if(ar[i]%2 != 0){
            if(ar[j]%2 == 0){
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
                i++; j--;
            }
            else j--;
        }
        else i++;
    }

    printf("Output : ");
    for (i=0; i<n; i++)
        printf("%d ",ar[i]);
    free(ar); return 0;
}