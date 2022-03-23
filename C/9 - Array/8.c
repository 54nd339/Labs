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
    for(int j=min; j<=max; j++){
        int count = 0;
        for(int i=0; i<n; i++)
            if(ar[i] == j)
                count++;
        printf("Frequency of %d in array is : %d\n",j,count);
    }
    return 0;
}