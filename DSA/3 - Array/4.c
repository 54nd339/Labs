#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the size of array : ");
    int n; scanf("%d",&n);
    int *ar = (int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(int i=0; i<n; i++)
        scanf("%d",ar+i);
    
    for(int i=0; i<n; i++){
        int flag=0;
        for(int j=i+1; j<n; j++)
            if(*(ar+j) > *(ar+i)){
                ar[i] = ar[j];
                flag = 1;
                break;
            }
        if(flag == 0) ar[i]=-1;
    }

    printf("Output : ");
    for(int i=0; i<n; i++)
        printf("%d ",ar[i]);
    free(ar); return 0;
}