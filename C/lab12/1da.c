#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Enter no. of elements: ");
    int n; scanf("%d",&n);
    int *p = malloc(n*sizeof(int));
    int sum = 0;
    for(int i=0; i<n; i++){
        printf("Enter elements %d : ",i+1);
        scanf("%d",p+i);
        sum += *(p+i);
    }
    printf("Sum of the elements : %d\n",sum);
    return 0;
}