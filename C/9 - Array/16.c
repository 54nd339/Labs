#include<stdio.h>
int main(){
    printf("Enter no. of elements : ");
    int n; scanf("%d",&n);
    int ar[n], sq[n], cb[n], fact[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
        sq[i] = ar[i] * ar[i];
        cb[i] = sq[i] * ar[i];
        int p = 1;
        for(int j=2; j<=ar[i]; j++)
            p*=j;
        fact[i] = p;
    }
    printf("\nOriginal Array : ");
    for(int i=0; i<n; i++)
        printf("%d, ",ar[i]);
    
    printf("\nSquare Array : ");
    for(int i=0; i<n; i++)
        printf("%d, ",sq[i]);
     
    printf("\nCube Array : ");
    for(int i=0; i<n; i++)
        printf("%d, ",cb[i]);
        
    printf("\nFactorial Array : ");
    for(int i=0; i<n; i++)
        printf("%d, ",fact[i]);
    return 0;
}