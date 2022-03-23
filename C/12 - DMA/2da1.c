#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("Enter no. of rows : ");
    int n; scanf("%d",&n);
    int (*p)[5], sum=0;
    p = (int(*)[5])malloc(n*5*sizeof(int));
    for(int i=0; i<n; i++)
        for(int j=0; j<5; j++){
            printf("Enter elements %d,%d : ",i+1,j+1);
            scanf("%d",(*(p+i)+j));
            sum += *(*(p+i)+j);
        }
    printf("Sum of the elements : %d\n",sum);
    return 0; 
}