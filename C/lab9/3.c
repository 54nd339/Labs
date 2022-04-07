#include <stdio.h>
int main(){
    printf("Enter no. of elements in the array : ");
    int n; scanf("%d",&n);
    int ar[n], b[100];

    for(int i=0; i<n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&ar[i]);
    }

    printf("Entered Elements : ");
    for(int i=0; i<n; i++)
        printf("%d ",ar[i]);

    printf("\nAt starting : \n");
    for(int i=0; i<n; i++)
        b[i] = ar[i];
    for(int i=0; i<n; i++)
        printf("element at %d : %d\n",i,b[i]);

    printf("\nAt Ending : \n");
    for(int i=0; i<n; i++)
        b[100-n+i] = ar[i];
    for(int i=100-n; i<100; i++)
        printf("element at %d : %d\n",i,b[i]);

    printf("\nfrom a point : \n");
    printf("Enter a point : ");
    int p; scanf("%d",&p);
    if(p>100-n)
        printf("Not enough space\n");
    else{
        for(int i=0; i<n; i++)
            b[p+i] = ar[i];
        for(int i=p; i<p+n; i++)
            printf("element at %d : %d\n",i,b[i]);
    }
    return 0;
}