#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Enter the size of array : ");
    int n; scanf("%d",&n);
    int *in = (int *)malloc(n*sizeof(int));
    int *out = (int *)malloc(n*sizeof(int));
    printf ("Enter array elements : ");
    for(int i=0; i<n; i++){
        scanf("%d",in+i);
        *(out+(n-1-i)) = *(in+i);
    }
    printf("Output : \n");
    for(int i=0; i<n; i++)
        printf("%d ",*(out+i));
    free(in);
    free(out);
    return 0;
}