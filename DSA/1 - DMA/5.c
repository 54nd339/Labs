#include <stdio.h>
#include <stdlib.h>
int main(){
    int *ar, *out, i, n, a, b, c=0, flag=0;
    printf("Enter the no. of elements in the array : ");
    scanf("%d",&n);
    ar=(int *)malloc(n*sizeof(int));
    out=(int *)malloc(n*sizeof(int));
    printf ("Enter array elements :\n");
    for(i=0;i<n;i++)
        scanf("%d",ar+i);
    printf("Enter the a & b respectively : ");
    scanf("%d%d",&a,&b);
    for(i=0;i<n;i++){
        if(*(ar+i)==a) flag=1;
        if(flag) {
            *(out+c)=*(ar+i);
            c++;
        }
        if(*(ar+i)==b) break;
    }
    printf("%d and the  elements are : ",c);
    for(i=0;i<c;i++)
        printf("%d ",*(out+i));
    return 0;
}