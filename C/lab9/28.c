#include <stdio.h>
int main(){
    printf("Enter no. of elements in the array : ");
    int n; scanf("%d",&n);
    int ar[n], max[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Entered Elements :\n");
    for(int i=0; i<n; i++){
        printf("%d\n",ar[i]);
        int f = (i==n-1) ? -1 : ar[i+1];
        int b = (i==0) ? -1 : ar[i-1];
        max[i] = (f>b) ? f : b;
    }
    for(int i=0; i<n; i++)
    printf("%d is the largest integer next to %d\n",max[i],ar[i]);
}