#include<stdio.h>
void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}
int main(){
    printf("Enter no. of elements in each array : ");
    int n; scanf("%d",&n);
    int ar1[n], ar2[n];
    printf("\nEnter Array 1 : \n");
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar1[i]);
    }
    printf("\nEnter Array 2 : \n");
    for(int i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar2[i]);
    }

    int ar[2*n];
    for(int  i=0; i<n; i++)
        ar[i] = ar1[i];
    for(int i=0; i<n; i++)
        ar[i+n] = ar2[i]; 
    printf("\nOriginal order : ");
    for(int i=0; i<2*n; i++)
        printf("%d ",ar[i]);
    
    printf("\nAscending order : ");
    for(int i=0; i<2*n; i++)
        for(int j=0; j<2*n; j++)
            if(ar[j]>ar[i])
                swap(&ar[j],&ar[i]);
    for(int i=0; i<2*n; i++)
        printf("%d ",ar[i]);
    
    printf("\nDescending order : ");
    for(int i=0; i<2*n; i++)
        for(int j=0; j<2*n; j++)
            if(ar[j]<ar[i])
                swap(&ar[j],&ar[i]);
    for(int i=0; i<2*n; i++)
        printf("%d ",ar[i]);
    return 0;
}