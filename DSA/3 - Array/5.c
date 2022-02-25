#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,*ar,i,t,temp;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);
    
    temp=ar[0];
    for(i=1;i<n-1;i++){
        t=ar[i];
        ar[i]=temp*ar[i+1];
        temp=t;
    }

    printf("Output : ");
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    free(ar); return 0;
}