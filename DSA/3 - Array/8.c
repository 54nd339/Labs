#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the size of array : ");
    int n; scanf("%d",&n);
    int *ar = (int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(int i=0; i<n; i++)
        scanf("%d",ar+i);
    
    int max = ar[0], c = 0;
    for(int i=1; i<n; i++){
        if(ar[i]>max){
            max=ar[i];
            c=0;
        }
        if(ar[i]==max) c++;
    }

    printf("Max occurence of %d : %d",max, c);
    free(ar); return 0;
}