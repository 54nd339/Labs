#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, i, j, (*p)[5], sum=0;
    printf("Enter no. of rows : ");
    scanf("%d",&n);
    p=(int(*)[5])malloc(n*5*sizeof(int));
    for(i=0;i<n;i++)
        for(j=0;j<5;j++){
            printf("Enter elements %d,%d : ",i+1,j+1);
            scanf("%d",(*(p+i)+j));
            sum+=*(*(p+i)+j);
        }
    printf("Sum of the elements : %d\n",sum);
    return 0; 
}
