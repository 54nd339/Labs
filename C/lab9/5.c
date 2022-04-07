#include<stdio.h>
int main(){
    printf("Enter no. of elements : ");
    int n; scanf("%d",&n);
    int ar[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Unique elements in the array : ");
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++)
            if(ar[i] == ar[j])
                count++;
        if(count == 1)
            printf("%d ",ar[i]);
    }
    return 0;
}