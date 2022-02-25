#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, i, *p, sum=0;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    p=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        printf("Enter elements %d : ",i+1);
        scanf("%d",p+i);
        sum+=*(p+i);
    }
    printf("Sum of the elements : %d\n",sum);
    return 0;
}
