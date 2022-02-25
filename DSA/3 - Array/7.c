#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,*ar,i,j,k,m,temp;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);
    printf("Enter k : ");
    scanf("%d",&k);
    
    for(i=0;i<n-1;i++){
        for(m=i, j=i+1;j<n;j++)
            if(ar[j]<ar[m]) m=j;
        temp=ar[m];
        ar[m]=ar[i];
        ar[i]=temp;
    }

    printf("%dth Smallest element : %d \n",k,ar[k-1]);
    printf("%dth Largest element : %d \n",k,ar[n-k]);
    free(ar); return 0;
}    