#include<stdio.h>
int main(){
    printf("Enter no. of elements : ");
    int n; scanf("%d",&n);
    int ar[n], b[n+1];
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("\nAscending order: ");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(ar[j] > ar[i]){
              int t = ar[i];
              ar[i] = ar[j];
              ar[j] = t;  
            }
    
    printf("Enter a point : ");
    int p; scanf("%d",&p);
    printf("Enter element to be entered: ");
    int m; scanf("%d",&m);
    for(int i=0; i<p; i++)
        b[i] = ar[i];
    b[p] = m;
    for(int i=p; i<n; i++)
        b[i+1] = ar[i];

    for(int i=0; i<=n; i++)
        printf("element at %d : %d\n",i,b[i]);
    return 0;
}