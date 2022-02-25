#include <stdio.h>
#include <stdlib.h>
int main(){
    int *in, *out, n, i;
    printf("Enter the no. of elements in the array : ");
    scanf("%d",&n);
    in=(int *)malloc(n*sizeof(int));
    out=(int *)malloc(n*sizeof(int));
    printf ("Enter array elements :\n");
    for(i=0;i<n;i++){
        scanf("%d",in+i);
        *(out+(n-1-i))=*(in+i);
    }
    printf("Output : \n");
    for(i=0;i<n;i++)
        printf("%d ",*(out+i));
    free(in);
    free(out);
    return 0;
}