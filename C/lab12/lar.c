#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Enter no. of elements : ");
    int n; scanf("%d",&n);
    float *d = (float*)calloc(n,sizeof(float));
    for(int i=0; i<n; i++){
        printf("Enter elements %d : ",i+1);
        scanf("%f",d+i);
        if(*d < *(d+i)) *d = *(d+i);
    }
    printf("Largest element : %.2f\n",*d);
    free(d);
    return 0;
}