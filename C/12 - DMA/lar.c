#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, i, sum=0;float *d;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    d=(float*)calloc(n,sizeof(float));
    for(i=0;i<n;i++){
        printf("Enter elements %d : ",i+1);
        scanf("%f",d+i);
        if(*d<*(d+i))
            *d=*(d+i);
    }
    printf("Largest element : %.2f\n",*d);
    free(d);
    return 0;
}
