#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the size of array : ");
    int n; scanf("%d",&n);
    int *ar = (int *)malloc(n*sizeof(int));
    printf ("Enter array elements : ");
    for(int i=0; i<n; i++)
        scanf("%d",ar+i);
    printf("Enter the no. to be found in an array : ");
    int num; scanf("%d",&num);
    int pos = -1;
    for(int i=0; i<n; i++){
        if(num == *(ar+i)){
            pos = i+1;
            break;
        }
    }
    if(pos == -1)
        printf("Not Found");
    else 
        printf("Found at position %d ",pos);
    return 0;
}