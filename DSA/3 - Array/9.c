#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,*ar,i,j;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);

    i=0, j=n-1;
    while(j>=i) {
        if(ar[i]!= 0){
            if(ar[j]==0){
                ar[j]=1;
                ar[i]=0;
                i++;j--;
            }
            else j--;
        }
        else i++;
    }

    printf("output : ");
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    free(ar); return 0;
}