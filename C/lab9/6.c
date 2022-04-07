#include<stdio.h>
void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}
int main(){
    printf("Enter no. of elements : ");
    int n; scanf("%d",&n);
    int ar[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("\nOriginal order: ");
    for(int i=0; i<n; i++)
        printf("%d ",ar[i]);
    
    printf("\nAscending order: ");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(ar[j]>ar[i])
                swap(&ar[i], &ar[j]);
    for(int i=0; i<n; i++)
        printf("%d ",ar[i]);
    
    printf("\nDescending order: ");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(ar[j]<ar[i])
                swap(&ar[i], &ar[j]);
    for(int i=0; i<n; i++)
        printf("%d ",ar[i]);
    return 0;
}