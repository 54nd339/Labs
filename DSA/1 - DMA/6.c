#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ar, i, n, j, flag;
    printf("Enter the no. of elements in the array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    printf ("Enter array elements :\n");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);
    printf("Elements\tNGE\n");
    for(i=0;i<n;i++){
        flag=0;
        for(j=i+1;j<n;j++){
            if(*(ar+j)>*(ar+i)){
                printf("%d\t\t%d",*(ar+i),*(ar+j));
                flag=1;
                break;
            }
        }
        if(flag==0)
        printf("%d\t\t%d",*(ar+i),-1);
        printf("\n");
    }
    free(ar);
    return 0;
}