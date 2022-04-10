#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the size of array : ");
    int n; scanf("%d",&n);
    int *ar = (int *)malloc(n*sizeof(int));
    int *out = (int *)malloc(n*sizeof(int));
    printf ("Enter array elements : ");
    for(int i=0; i<n; i++)
        scanf("%d",ar+i);
    printf("Enter the a & b respectively : ");
    int a, b; scanf("%d%d",&a,&b);
    int flag = 0, c= 0;
    for(int i=0; i<n; i++){
        if(*(ar+i) == a)
            flag=1;
        if(flag) {
            *(out+c) = *(ar+i);
            c++;
        }
        if(*(ar+i) == b) break;
    }
    printf("%d and the  elements are : ",c);
    for(int i=0; i<c; i++)
        printf("%d ",*(out+i));
    return 0;
}