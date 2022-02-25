#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,*ar,i,j,flag;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);
    
    for(i=0;i<n;i++){
        flag=0;
        for(j=i+1;j<n;j++)
            if(*(ar+j)>*(ar+i)){
                ar[i]=ar[j];
                flag=1;
                break;
            }
        if(flag==0)
        ar[i]=-1;
    }

    printf("Output : ");
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    free(ar); return 0;
}