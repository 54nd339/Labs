#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ar, num, i, n, index=0;
    printf("Enter the no. of elements in the array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    printf ("Enter array elements :\n");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);
    printf("Enter the no. to be found in an array : ");
    scanf("%d",&num);
    for(i=0;i<n;i++){
        if(num==*(ar+i)){
            index=i+1;
            break;
        }
    }
    if(index!=0)
        printf("Found at position %d ",index);
    else 
        printf("Not Found");
    return 0;
}