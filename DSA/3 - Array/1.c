#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the size of array : ");
    int n; scanf("%d",&n);
    int *ar = (int *)malloc(n*sizeof(int));
    printf("Enter array elements : ");
    for(int i=0;i<n;i++)
        scanf("%d",ar+i);
    int a, b;
    printf("Enter 2 nos. : ");
    scanf("%d%d",&a,&b);

    int p=-1, md=n+1;
    for(int i=0; i<n; i++)
        if(ar[i] == a || ar[i] == b){
            if(p != -1 && ar[i] != ar[p])
                md = (md<i-p) ? md : i-p;
            p = i;
        }
    
    if(md>n) printf("Wrong input\n");
    printf("Min Distance : %d\n",md);
    free(ar); return 0;
}