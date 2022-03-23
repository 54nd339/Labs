#include<stdio.h>
int main(){
    printf("Enter no. of elements : ");
    int n; scanf("%d",&n);
    int ar[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    int max = ar[0], min = ar[0];
    for(int i=0; i<n; i++){
        if(max < ar[i])
            max = ar[i];
        if(min > ar[i])
            min = ar[i];
    }
    printf("max : %d, min: %d\n",max,min);
    return 0;
}