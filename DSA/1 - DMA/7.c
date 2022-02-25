#include <stdio.h>
#include<malloc.h>
int i, j, n;

void nonzero(int **ar) {
    int c=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if (*(*(ar+i)+j)!=0) c++;
    printf("total nonzero element is %d\n",c);
}

void sum(int **ar){
    int s=0;
    for(i=0;i<n-1;i++)
        for(j=0;j<n;j++)
           if((i+j)>2*i) s+=*(*(ar+i)+j);
    printf("Sum of elements above lead diag : %d\n",s);
}

void print(int **ar){
    printf("Elements below minor diag :\n");
    for(i=1;i<n;i++){
        for(j=0;j<n;j++)
            if((i+j)>(n-1))
                printf("%d ",*(*(ar+i)+j));
        printf("\n");
    }
}

void product(int **ar) {
    int p1=1, p2=1;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(i==j) p1*=*(*(ar+i)+j);
            if(i+j==n-1) p2*=*(*(ar+i)+j);
        }
    printf("product of lead diagonal element is %d\n",p1);
    printf("product of minor diagonal element is %d\n",p2);
}

int main(){
    printf("Enter n for n x n matrix : ");
    scanf("%d",&n);
    int **ar = (int **)malloc(n*sizeof(int *));
    for (i=0; i<n; i++)
        *(ar+i) = (int *)malloc(n*sizeof(int));
    printf ("Enter array elements :\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&*(*(ar+i)+j));
    
    nonzero(ar);
    sum(ar);
    print(ar);
    product(ar);
    free(ar);
    return 0;
}